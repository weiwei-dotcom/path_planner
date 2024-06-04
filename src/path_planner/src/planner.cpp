#include "planner.hpp"

PathPlanner::PathPlanner():Node("path_planner")
{
    flag_get_map = false;

    cv::FileStorage fileRead("/home/weiwei/Desktop/project/path_planner/src/path_planner/config.yaml", cv::FileStorage::READ);

    weight_s_acc = fileRead["weight_s_acc"];
    weight_s = fileRead["weight_s"];
    weight_c = fileRead["weight_c"];
    safe_dist = fileRead["safe_dist"];

    ctrl_pt_interval = fileRead["ctrl_pt_interval"];
    time_interval = fileRead["time_interval"];

    this->degree = 3;
    resolution = fileRead["resolution"];

    // 初始化栅格地图的原点坐标，尺寸大小，并初始化栅格地图
    grid_map_origin_point.x() = fileRead["grid_map_origin_point_x"];
    grid_map_origin_point.y() = fileRead["grid_map_origin_point_y"];
    grid_map_origin_point.z() = fileRead["grid_map_origin_point_z"];

    this->inflation_radius = fileRead["inflation_radius"];
    this->inflation_radius_grid = std::ceil((inflation_radius-0.5*resolution)/resolution);

    std::cout <<"inflation_radius_grid: " << inflation_radius_grid<<std::endl;

    double map_size_x = fileRead["map_size_x"];
    double map_size_y = fileRead["map_size_y"];
    double map_size_z = fileRead["map_size_z"];
    grid_map_size_x = std::ceil((map_size_x+0.5*resolution)/resolution);
    grid_map_size_y = std::ceil((map_size_y+0.5*resolution)/resolution);
    grid_map_size_z = std::ceil((map_size_z+0.5*resolution)/resolution);
    grid_map_end_point.x() = (double)grid_map_size_x*resolution+grid_map_origin_point.x()-0.5*resolution;
    grid_map_end_point.y() = (double)grid_map_size_y*resolution+grid_map_origin_point.y()-0.5*resolution;
    grid_map_end_point.z() = (double)grid_map_size_z*resolution+grid_map_origin_point.z()-0.5*resolution;
    grid_map_start_point = grid_map_origin_point-Eigen::Vector3d(0.5,0.5,0.5)*resolution;


    ///DEBUG:
    RCLCPP_INFO(this->get_logger(), "map_x_size: %f", map_size_x);
    RCLCPP_INFO(this->get_logger(), "map_y_size: %f", map_size_y);
    RCLCPP_INFO(this->get_logger(), "map_z_size: %f", map_size_z);
    RCLCPP_INFO(this->get_logger(), "grid_map_start_point: %f, %f, %f", grid_map_start_point.x(), grid_map_start_point.y(),grid_map_start_point.z());
    RCLCPP_INFO(this->get_logger(), "grid_map_end_point: %f, %f, %f", grid_map_end_point.x(), grid_map_end_point.y(),grid_map_end_point.z());
    RCLCPP_INFO(this->get_logger(), "grid_map_x_size: %d", grid_map_size_x);
    RCLCPP_INFO(this->get_logger(), "grid_map_y_size: %d", grid_map_size_y);
    RCLCPP_INFO(this->get_logger(), "grid_map_z_size: %d", grid_map_size_z);

    // 初始化碰撞栅格地图
    std::vector<bool> temp_occupy(this->grid_map_size_z, false);
    std::vector<std::vector<bool>> temp_occupy_2d(this->grid_map_size_y, temp_occupy);
    this->grid_map.resize(this->grid_map_size_x, temp_occupy_2d);

    // 初始化用来寻找最短astar最短路径的GridNodeMap_
    initGridMap(Eigen::Vector3i(100,100,100));

    this->min_plan_dist = fileRead["min_plan_dist"];  

    // 创建路径跟随客户端
    this->path_plan_service = this->create_service<interface::srv::PathPlan>("path_plan", std::bind(&PathPlanner::planPathCallback,
                                                                                                    this,   
                                                                                                    std::placeholders::_1,
                                                                                                    std::placeholders::_2));
    map_sub = this->create_subscription<sensor_msgs::msg::PointCloud>("obs_pcl",10, std::bind(&PathPlanner::mapCallback,this,std::placeholders::_1));
    map_pub = this->create_publisher<sensor_msgs::msg::PointCloud>("map",10);
    marker_pub = this->create_publisher<visualization_msgs::msg::Marker>("test_marker",2);
    return;
}

// init the straight line path that for the 
void PathPlanner::planPathCallback(const interface::srv::PathPlan::Request::SharedPtr request,
                                   const interface::srv::PathPlan::Response::SharedPtr response)
{      
    ///DEBUG:
    std::cout <<" planPathCallback: start: " << std::endl;
    
    if (!flag_get_map)
    {
        RCLCPP_WARN(this->get_logger(),"未接收到障碍物地图，不能规划路径！");
        response->success = false;
        return;
    }
    // 1. 首先接收数据: 将得到的起始位置、速度赋值给全局变量
    Eigen::Vector3d start_pos(request->start_position.x,request->start_position.y,request->start_position.z);
    Eigen::Vector3d end_pos(request->end_position.x,request->end_position.y,request->end_position.z);
    if ((start_pos - end_pos).norm() < min_plan_dist)
    {
        RCLCPP_WARN(this->get_logger(), "路径规划起始点接近目标点，不需要规划路径！");
        response->success = false;
        return;
    }
    
    Eigen::Vector3d start_dir(request->start_velocity.x,request->start_velocity.y,request->start_velocity.z);
    start_dir.normalize();
    Eigen::Vector3d end_dir(request->end_velocity.x,request->end_velocity.y,request->end_velocity.z);
    if (end_dir.norm() > 1e-4)
    {
        end_dir.normalize();
        RCLCPP_WARN(this->get_logger(),"注意！规划路径目标点速度“不为零”");
    }
    // 1. 初始化控制点: 起点到终点之间进行插值获得初始化控制点列表ctrl_pts.
    std::vector<Eigen::Vector3d> ctrl_pts = initControlPoints(start_pos, end_pos, start_dir, end_dir);
    std::vector<Eigen::Vector3d> temp_eigen_vec;
    temp_eigen_vec.resize(0);
    std::vector<std::vector<Eigen::Vector3d>> base_pts(ctrl_pts.size(),temp_eigen_vec);
    std::vector<std::vector<Eigen::Vector3d>> esc_directions(ctrl_pts.size(),temp_eigen_vec);
    
    // 2. 计算优化每个控制点的逃逸向量以及障碍物表面锚点
    ///DEBUG:
    std::cout <<" getBasePointsAndDirection: start: " << std::endl;
    bool flag_success = getBasePointsAndDirection(ctrl_pts,base_pts,esc_directions);

    if (!flag_success)
    {
        RCLCPP_WARN(this->get_logger(), "获取控制点优化导航信息失败!");
        response->success = false;
        return;
    }
    bool flag_no_collision=false;
    while (!flag_no_collision)
    {
        std::cout <<" Optimize: end: " << std::endl;
        // 3. 对控制点进行优化得到最终控制点列表
        Optimize(ctrl_pts,base_pts,esc_directions);
        std::cout <<" check_collision_and_rebound: end: " << std::endl;
        flag_no_collision = check_collision_and_rebound(ctrl_pts,base_pts,esc_directions);        
    }
            
    // ///DEBUG: 发布基点与控制点
    // geometry_msgs::msg::Point pt;
    // visualization_msgs::msg::Marker pts;
    // pts.type = visualization_msgs::msg::Marker::SPHERE_LIST;
    // pts.action = visualization_msgs::msg::Marker::ADD;
    // pts.header.frame_id = "world";
    // pts.header.stamp = this->now();
    // pts.pose.position.x = 0.0;
    // pts.pose.position.y = 0.0;
    // pts.pose.position.z = 0.0;
    // pts.pose.orientation.x = 0.0;
    // pts.pose.orientation.y = 0.0;
    // pts.pose.orientation.z = 0.0;
    // pts.pose.orientation.w = 1.0;
    // pts.scale.x=9;
    // pts.scale.y=9;
    // pts.scale.z=9;
    // pts.color.r = 1.0;
    // pts.color.g = 0.0;
    // pts.color.b = 0.4;
    // pts.color.a = 1.0;
    // for (int i=0; i<ctrl_pts.size(); i++)
    // {
    //     pt.x = ctrl_pts[i].x();
    //     pt.y = ctrl_pts[i].y();
    //     pt.z = ctrl_pts[i].z();
    //     pts.points.push_back(pt);    
    //     for (int j=0; j<base_pts[i].size(); j++)
    //     {
    //         pt.x = base_pts[i][j].x();
    //         pt.y = base_pts[i][j].y();
    //         pt.z = base_pts[i][j].z();            
    //         pts.points.push_back(pt);       
    //     }
    // }
    // while(rclcpp::sleep_for(std::chrono::seconds(1)))
    // {
    //     marker_pub->publish(pts);
    // }

    for (int i=0; i<ctrl_pts.size(); i++)
    {
        geometry_msgs::msg::Point ctrl_pts_ros;
        ctrl_pts_ros.x = ctrl_pts[i].x();
        ctrl_pts_ros.y = ctrl_pts[i].y();
        ctrl_pts_ros.z = ctrl_pts[i].z();
        response->control_points.push_back(ctrl_pts_ros);
    }
    response->knot_interval = this->time_interval;
    response->degree = this->degree;
    response->success = true;

    std::cout <<" planPathCallback: end: " << std::endl;

    return;
}
void PathPlanner::mapCallback(const sensor_msgs::msg::PointCloud::SharedPtr pcl_obs_msg)
{

    std::cout <<" mapCallback: start: " << std::endl;
    
    this->map_pub->publish(*pcl_obs_msg);
    if (pcl_obs_msg->points.size() > 10000 && flag_get_map)
    {
        // RCLCPP_WARN(this->get_logger(),"已接收到地图点云！");
        // RCLCPP_WARN(this->get_logger(),"pcl_obs_msg->points.size(): %d",pcl_obs_msg->points.size());

        return;
    }
    int pcl_obs_size = pcl_obs_msg->points.size();
    Eigen::Vector3i temp_grid_map_id;
    std::cout << "pcl_obs_size: " << pcl_obs_size<<std::endl;
    for (int i=0;i<pcl_obs_size;i++)
    {
        bool temp_flag = coorToIndex(Eigen::Vector3d(pcl_obs_msg->points[i].x,pcl_obs_msg->points[i].y,pcl_obs_msg->points[i].z), temp_grid_map_id);

        // ///DEBUG:
        // if (!temp_flag)
        // {
        //     std::cout << "pcl_obs_msg->points["<<i<<"]: "<<pcl_obs_msg->points[i].x<<", "<<pcl_obs_msg->points[i].y<<", "<<pcl_obs_msg->points[i].z<<std::endl;
        // }

        grid_map[temp_grid_map_id.x()][temp_grid_map_id.y()][temp_grid_map_id.z()] = true;
        for (int x=temp_grid_map_id.x()-inflation_radius_grid;x<=temp_grid_map_id.x()+inflation_radius_grid;x++)
        {
            for (int y=temp_grid_map_id.y()-inflation_radius_grid;y<=temp_grid_map_id.y()+inflation_radius_grid;y++)
            {
                for (int z=temp_grid_map_id.z()-inflation_radius_grid;z<=temp_grid_map_id.z()+inflation_radius_grid;z++)
                {
                    boundCorrect(x,y,z);
                    grid_map[x][y][z] = true;
                } 
            }
        }
    }
    flag_get_map = true;

    return;
}

std::vector<Eigen::Vector3d> PathPlanner::initControlPoints(const Eigen::Vector3d &start_pos, const Eigen::Vector3d &end_pos,
                                                            const Eigen::Vector3d &start_dir, const Eigen::Vector3d &end_dir)
{
    ///DEBUG:
    std::cout << "initcontrolpints: start" << std::endl;

    if (end_dir.norm()<1e-4) {
        std::vector<Eigen::Vector3d> ctrl_pts;
        ctrl_pts.push_back(start_pos);
        Eigen::Vector3d dir_ctrl_pt = start_pos+start_dir*ctrl_pt_interval;
        ctrl_pts.push_back(dir_ctrl_pt);

        int interval_num = std::ceil((end_pos-dir_ctrl_pt).norm()/ctrl_pt_interval);
        for (int i=1; i<interval_num; i++)
        {
            double alpha = (double)i/(double)interval_num;
            Eigen::Vector3d temp_pt = alpha*end_pos+(1.0-alpha)*dir_ctrl_pt;
            ctrl_pts.push_back(temp_pt);
        }
        ctrl_pts.push_back(end_pos);
        return ctrl_pts;
    }
    else {
        std::vector<Eigen::Vector3d> ctrl_pts;
        ctrl_pts.push_back(start_pos);
        Eigen::Vector3d start_dir_ctrl_pt = start_pos+start_dir*ctrl_pt_interval;
        ctrl_pts.push_back(start_dir_ctrl_pt);
        Eigen::Vector3d end_dir_ctrl_pt = end_pos-end_dir*ctrl_pt_interval;
        int interval_num = std::ceil((end_dir_ctrl_pt-start_dir_ctrl_pt).norm()/ctrl_pt_interval);
        for (int i=1; i<interval_num; i++)
        {
            double alpha = (double)i/(double)interval_num;
            Eigen::Vector3d temp_pt = alpha*end_dir_ctrl_pt+(1.0-alpha)*start_dir_ctrl_pt;
            ctrl_pts.push_back(temp_pt);
        }
        ctrl_pts.push_back(end_dir_ctrl_pt);
        ctrl_pts.push_back(end_pos);

        // ///DEBUG: 
        // geometry_msgs::msg::Point pt;
        // visualization_msgs::msg::Marker pts;
        // pts.type = visualization_msgs::msg::Marker::SPHERE_LIST;
        // pts.action = visualization_msgs::msg::Marker::ADD;
        // pts.header.frame_id = "world";
        // pts.header.stamp = this->now();
        // pts.pose.position.x = 0.0;
        // pts.pose.position.y = 0.0;
        // pts.pose.position.z = 0.0;
        // pts.pose.orientation.x = 0.0;
        // pts.pose.orientation.y = 0.0;
        // pts.pose.orientation.z = 0.0;
        // pts.pose.orientation.w = 1.0;
        // pts.scale.x=9;
        // pts.scale.y=9;
        // pts.scale.z=9;
        // pts.color.r = 1.0;
        // pts.color.g = 0.0;
        // pts.color.b = 0.4;
        // pts.color.a = 1.0;
        // for (int i=2; i<ctrl_pts.size();i++)
        // {
        //     pt.x = ctrl_pts[i].x();
        //     pt.y = ctrl_pts[i].y();
        //     pt.z = ctrl_pts[i].z();
        //     pts.points.push_back(pt);
        // }
        // while (rclcpp::sleep_for(std::chrono::seconds(1)))
        // {
        //     marker_pub->publish(pts);
        // }
        return ctrl_pts;
    }   
}

bool PathPlanner::getBasePointsAndDirection(const std::vector<Eigen::Vector3d> &ctrl_pts, 
                                            std::vector<std::vector<Eigen::Vector3d>> &base_pts,
                                            std::vector<std::vector<Eigen::Vector3d>> &esc_directions)
{

    ///DEBUG:
    std::cout << "getBasePointsAndDirection: start" << std::endl;
    
    std::vector<bool> temp_flags(ctrl_pts.size(),false);
    /*** Segment the initial trajectory according to obstacles ***/
    constexpr int ENOUGH_INTERVAL = 2;
    // step_size is a ratio value
    double step_size = resolution / ((ctrl_pts[1] - ctrl_pts.back()).norm() / (ctrl_pts.size() - 2)) / 2;
    int in_id, out_id;
    int same_occ_state_times = ENOUGH_INTERVAL + 1;
    bool occ, last_occ = false;
    bool flag_got_start = false, flag_got_end = false, flag_got_end_maybe = false;
    int i_end = ctrl_pts.size()-3;
    std::vector<std::pair<int,int>> segment_ids;
    for (int i = 3; i <= i_end; ++i)
    {
        for (double a = 1.0; a >= 0.0; a -= step_size)
        {
            occ = checkCollision(a * ctrl_pts[i - 1] + (1 - a) * ctrl_pts[i]);

            if (occ && !last_occ)
            {
                if (same_occ_state_times > ENOUGH_INTERVAL || i == 3)
                {
                    in_id = i - 1;
                    flag_got_start = true;
                }
                same_occ_state_times = 0;
                flag_got_end_maybe = false; // terminate in advance
            }
            else if (!occ && last_occ)
            {
                out_id = i;
                flag_got_end_maybe = true;
                same_occ_state_times = 0;
            }
            else
            {
                ++same_occ_state_times;
            }

            if (flag_got_end_maybe && (same_occ_state_times > ENOUGH_INTERVAL || (i == i_end)))
            {
                flag_got_end_maybe = false;
                flag_got_end = true;
            }

            last_occ = occ;
            if (flag_got_start && flag_got_end)
            {
                flag_got_start = false;
                flag_got_end = false;
                segment_ids.push_back(std::pair<int, int>(in_id, out_id));
            }
        }
    }

    /*** a star search ***/
    vector<vector<Eigen::Vector3d>> a_star_pathes;
    for (size_t i = 0; i < segment_ids.size(); ++i)
    {
        //cout << "in=" << in.transpose() << " out=" << out.transpose() << endl;
        Eigen::Vector3d in(ctrl_pts[segment_ids[i].first]), out(ctrl_pts[segment_ids[i].second]);

        // ///DEBUG:
        // std::cout << "in_point: " << in << std::endl;
        // std::cout << "out_point: " << out << std::endl;
        // geometry_msgs::msg::Point pt;
        // visualization_msgs::msg::Marker pts;
        // pts.type = visualization_msgs::msg::Marker::SPHERE_LIST;
        // pts.action = visualization_msgs::msg::Marker::ADD;
        // pts.header.frame_id = "world";
        // pts.header.stamp = this->now();
        // pts.pose.position.x = 0.0;
        // pts.pose.position.y = 0.0;
        // pts.pose.position.z = 0.0;
        // pts.pose.orientation.x = 0.0;
        // pts.pose.orientation.y = 0.0;
        // pts.pose.orientation.z = 0.0;
        // pts.pose.orientation.w = 1.0;
        // pts.scale.x=9;
        // pts.scale.y=9;
        // pts.scale.z=9;
        // pts.color.r = 1.0;
        // pts.color.g = 0.0;
        // pts.color.b = 0.4;
        // pts.color.a = 1.0;
        // pt.x = in.x();
        // pt.y = in.y();
        // pt.z = in.z();
        // pts.points.push_back(pt);
        // pt.x = out.x();
        // pt.y = out.y();
        // pt.z = out.z();
        // pts.points.push_back(pt);
        // while(rclcpp::sleep_for(std::chrono::seconds(1)))
        // {
        //     marker_pub->publish(pts);
        // }

        if (AstarSearch(/*(in-out).norm()/10+0.05*/ resolution, in, out))
        {
            a_star_pathes.push_back(this->getPath());
        }
        else
        {
            RCLCPP_ERROR(this->get_logger(), "a star error, force return!");
            return false;
        }
    }


    // ///DEBUG: 发布成功寻找到的A_star路径
    // RCLCPP_INFO(this->get_logger(),"寻找astar路径成功");
    // geometry_msgs::msg::Point pt;
    // visualization_msgs::msg::Marker pts;
    // pts.type = visualization_msgs::msg::Marker::SPHERE_LIST;
    // pts.action = visualization_msgs::msg::Marker::ADD;
    // pts.header.frame_id = "world";
    // pts.header.stamp = this->now();
    // pts.pose.position.x = 0.0;
    // pts.pose.position.y = 0.0;
    // pts.pose.position.z = 0.0;
    // pts.pose.orientation.x = 0.0;
    // pts.pose.orientation.y = 0.0;
    // pts.pose.orientation.z = 0.0;
    // pts.pose.orientation.w = 1.0;
    // pts.scale.x=9;
    // pts.scale.y=9;
    // pts.scale.z=9;
    // pts.color.r = 1.0;
    // pts.color.g = 0.0;
    // pts.color.b = 0.4;
    // pts.color.a = 1.0;
    // for(int i=0; i<a_star_pathes.size(); i++)
    // {
    //     for (int j=0; j<a_star_pathes[i].size(); j++)
    //     {
    //         pt.x = a_star_pathes[i][j].x();
    //         pt.y = a_star_pathes[i][j].y();
    //         pt.z = a_star_pathes[i][j].z();
    //         pts.points.push_back(pt);            
    //     }
    // }
    // while(rclcpp::sleep_for(std::chrono::seconds(1)))
    // {
    //     marker_pub->publish(pts);
    // }

    /*** calculate bounds ***/
    int id_low_bound, id_up_bound;
    std::vector<std::pair<int, int>> bounds(segment_ids.size());
    for (size_t i = 0; i < segment_ids.size(); i++)
    {
        if (i == 0) // first segment
        {
            ///TODO: 可能修改的不对
            id_low_bound = 3;
            if (segment_ids.size() > 1)
            {
                id_up_bound = (int)(((segment_ids[0].second + segment_ids[1].first) - 1.0f) / 2); // id_up_bound : -1.0f fix()
            }
            else
            {
                ///TODO: 可能修改的不对
                id_up_bound = ctrl_pts.size() - 3;
            }
        }
        else if (i == segment_ids.size() - 1) // last segment, i != 0 here
        {
            id_low_bound = (int)(((segment_ids[i].first + segment_ids[i - 1].second) + 1.0f) / 2); // id_low_bound : +1.0f ceil()
            ///TODO: 可能修改的不对
            id_up_bound = ctrl_pts.size() - 3;
        }
        else
        {
            id_low_bound = (int)(((segment_ids[i].first + segment_ids[i - 1].second) + 1.0f) / 2); // id_low_bound : +1.0f ceil()
            id_up_bound = (int)(((segment_ids[i].second + segment_ids[i + 1].first) - 1.0f) / 2);  // id_up_bound : -1.0f fix()
        }
        bounds[i] = std::pair<int, int>(id_low_bound, id_up_bound);
    }

    /*** Adjust segment length ***/
    vector<std::pair<int, int>> final_segment_ids(segment_ids.size());
    constexpr double MINIMUM_PERCENT = 0.0; // Each segment is guaranteed to have sufficient points to generate sufficient thrust
    int minimum_points = round(ctrl_pts.size() * MINIMUM_PERCENT), num_points;
    for (size_t i = 0; i < segment_ids.size(); i++)
    {
        /*** Adjust segment length ***/
        num_points = segment_ids[i].second - segment_ids[i].first + 1;
        //cout << "i = " << i << " first = " << segment_ids[i].first << " second = " << segment_ids[i].second << endl;
        if (num_points < minimum_points)
        {
            double add_points_each_side = (int)(((minimum_points - num_points) + 1.0f) / 2);

            final_segment_ids[i].first = segment_ids[i].first - add_points_each_side >= bounds[i].first ? segment_ids[i].first - add_points_each_side : bounds[i].first;

            final_segment_ids[i].second = segment_ids[i].second + add_points_each_side <= bounds[i].second ? segment_ids[i].second + add_points_each_side : bounds[i].second;
        }
        else
        {
            final_segment_ids[i].first = segment_ids[i].first;
            final_segment_ids[i].second = segment_ids[i].second;
        }

      //cout << "final:" << "i = " << i << " first = " << final_segment_ids[i].first << " second = " << final_segment_ids[i].second << endl;
    }

    /*** Assign data to each segment ***/
    for (size_t i = 0; i < segment_ids.size(); i++)
    {
        // step 1
        for (int j = final_segment_ids[i].first; j <= final_segment_ids[i].second; ++j)
            temp_flags[j] = false;

        // step 2
        int got_intersection_id = -1;
        for (int j = segment_ids[i].first + 1; j < segment_ids[i].second; ++j)
        {
            Eigen::Vector3d ctrl_pts_law(ctrl_pts[j+1] - ctrl_pts[j-1]), intersection_point;
            int Astar_id = a_star_pathes[i].size() / 2, last_Astar_id; // Let "Astar_id = id_of_the_most_far_away_Astar_point" will be better, but it needs more computation
            double val = (a_star_pathes[i][Astar_id] - ctrl_pts[j]).dot(ctrl_pts_law), last_val = val;
            while (Astar_id >= 0 && Astar_id < (int)a_star_pathes[i].size())
            {
                last_Astar_id = Astar_id;

                if (val >= 0)
                    --Astar_id;
                else
                    ++Astar_id;

                val = (a_star_pathes[i][Astar_id] - ctrl_pts[j]).dot(ctrl_pts_law);

                if (val * last_val <= 0 && (abs(val) > 0 || abs(last_val) > 0)) // val = last_val = 0.0 is not allowed
                {
                    intersection_point =
                        a_star_pathes[i][Astar_id] +
                        ((a_star_pathes[i][Astar_id] - a_star_pathes[i][last_Astar_id]) *
                        (ctrl_pts_law.dot(ctrl_pts[j] - a_star_pathes[i][Astar_id]) / ctrl_pts_law.dot(a_star_pathes[i][Astar_id] - a_star_pathes[i][last_Astar_id])) // = t
                        );

                    //cout << "i=" << i << " j=" << j << " Astar_id=" << Astar_id << " last_Astar_id=" << last_Astar_id << " intersection_point = " << intersection_point.transpose() << endl;

                    got_intersection_id = j;
                    break;
                }
            }

            if (got_intersection_id >= 0)
            {
                temp_flags[j] = true;
                double length = (intersection_point - ctrl_pts[j]).norm();
                if (length > 1e-5)
                {
                    for (double a = length; a >= 0.0; a -= resolution)
                    {
                        occ = checkCollision((a / length) * intersection_point + (1 - a / length) * ctrl_pts[j]);

                        if (occ || a < resolution)
                        {
                            if (occ)
                            a += resolution;
                            base_pts[j].push_back((a / length) * intersection_point + (1 - a / length) * ctrl_pts[j]);
                            esc_directions[j].push_back((intersection_point - ctrl_pts[j]).normalized());
                            break;
                        }
                    }
                }
            }
        }

      /* Corner case: the segment length is too short. Here the control points may outside the A* path, leading to opposite gradient direction. So I have to take special care of it */
        if (segment_ids[i].second - segment_ids[i].first == 1)
        {
            // Eigen::Vector3d ctrl_pts_law(ctrl_pts[segment_ids[i].second] - ctrl_pts[segment_ids[i].first]), intersection_point;
            Eigen::Vector3d ctrl_pts_law(ctrl_pts[segment_ids[i].second] - ctrl_pts[segment_ids[i].first]), intersection_point;
            Eigen::Vector3d middle_point = (ctrl_pts[segment_ids[i].second] + ctrl_pts[segment_ids[i].first]) / 2;
            int Astar_id = a_star_pathes[i].size() / 2, last_Astar_id; // Let "Astar_id = id_of_the_most_far_away_Astar_point" will be better, but it needs more computation
            double val = (a_star_pathes[i][Astar_id] - middle_point).dot(ctrl_pts_law), last_val = val;
            while (Astar_id >= 0 && Astar_id < (int)a_star_pathes[i].size())
            {
                last_Astar_id = Astar_id;

                if (val >= 0)
                    --Astar_id;
                else
                    ++Astar_id;

                val = (a_star_pathes[i][Astar_id] - middle_point).dot(ctrl_pts_law);

                if (val * last_val <= 0 && (abs(val) > 0 || abs(last_val) > 0)) // val = last_val = 0.0 is not allowed
                {
                    intersection_point =
                        a_star_pathes[i][Astar_id] +
                        ((a_star_pathes[i][Astar_id] - a_star_pathes[i][last_Astar_id]) *
                        (ctrl_pts_law.dot(middle_point - a_star_pathes[i][Astar_id]) / ctrl_pts_law.dot(a_star_pathes[i][Astar_id] - a_star_pathes[i][last_Astar_id])) // = t
                        );

                    if ((intersection_point - middle_point).norm() > 0.5) // 1cm.
                    {

                        /// FLAG: You should consider if you use the ControlPoint class.
                        temp_flags[segment_ids[i].first] = true;
                        base_pts[segment_ids[i].first].push_back(ctrl_pts[segment_ids[i].first]);
                        esc_directions[segment_ids[i].first].push_back((intersection_point - middle_point).normalized());

                        got_intersection_id = segment_ids[i].first;
                    }
                    break;
                }
            }
        }

        //step 3
        if (got_intersection_id >= 0)
        {
            for (int j = got_intersection_id + 1; j <= final_segment_ids[i].second; ++j)
                if (!temp_flags[j])
                {
                    base_pts[j].push_back(base_pts[j - 1].back());
                    esc_directions[j].push_back(esc_directions[j - 1].back());
                }

            for (int j = got_intersection_id - 1; j >= final_segment_ids[i].first; --j)
                if (!temp_flags[j])
                {
                    base_pts[j].push_back(base_pts[j + 1].back());
                    esc_directions[j].push_back(esc_directions[j + 1].back());
                }
        }
        else
        {
            // Just ignore, it does not matter ^_^.
            // ROS_ERROR("Failed to generate direction! segment_id=%d", i);
        }
    }

    ///DEBUG:
    std::cout << "getBasePointsAndDirection: end" << std::endl;

    return true;
}

void PathPlanner::Optimize( std::vector<Eigen::Vector3d> &ctrl_pts, 
                            const std::vector<std::vector<Eigen::Vector3d>> &base_pts,
                            const std::vector<std::vector<Eigen::Vector3d>> &esc_directions)
{

    std::cout << "Optimize: start" << std::endl;
    
    ceres::Problem problem;

    problem.AddResidualBlock(
        new ceres::AutoDiffCostFunction<acc_smooth_residual_pre_1,3,3,3>(
            new acc_smooth_residual_pre_1(weight_s_acc,ctrl_pts[0],ctrl_pts[1])
        ),
        NULL,
        ctrl_pts[2].data(),ctrl_pts[3].data()
    );
    problem.AddResidualBlock(
        new ceres::AutoDiffCostFunction<acc_smooth_residual_pre_2,3,3,3,3>(
            new acc_smooth_residual_pre_2(weight_s_acc,ctrl_pts[1])
        ),
        NULL,
        ctrl_pts[2].data(),ctrl_pts[3].data(),ctrl_pts[4].data()
    );
    for (int i=3; i<=ctrl_pts.size()-6; i++)
    {
        problem.AddResidualBlock(
            new ceres::AutoDiffCostFunction<acc_smooth_residual,3,3,3,3,3>(
                new acc_smooth_residual(weight_s_acc)
            ),
            NULL,
            ctrl_pts[i].data(),ctrl_pts[i+1].data(),ctrl_pts[i+2].data(),ctrl_pts[i+3].data()
        );
    }
    problem.AddResidualBlock(
        new ceres::AutoDiffCostFunction<acc_smooth_residual_post_2,3,3,3,3>(
            new acc_smooth_residual_post_2(weight_s_acc,ctrl_pts[ctrl_pts.size()-2])
        ),
        NULL,
        ctrl_pts[ctrl_pts.size()-3].data(),ctrl_pts[ctrl_pts.size()-4].data(),ctrl_pts[ctrl_pts.size()-5].data()
    );

    problem.AddResidualBlock(
        new ceres::AutoDiffCostFunction<acc_smooth_residual_post_1,3,3,3>(
            new acc_smooth_residual_post_1(weight_s_acc,ctrl_pts[ctrl_pts.size()-1],ctrl_pts[ctrl_pts.size()-2])
        ),
        NULL,
        ctrl_pts[ctrl_pts.size()-3].data(),ctrl_pts[ctrl_pts.size()-4].data()
    );


    problem.AddResidualBlock(
        new ceres::AutoDiffCostFunction<smooth_residual_pre_1,3,3>(
            new smooth_residual_pre_1(weight_s, ctrl_pts[0], ctrl_pts[1])
        ),
        NULL,
        ctrl_pts[2].data()
    );

    std::cout << "Optimize: 1" << std::endl;
    
    problem.AddResidualBlock(
        new ceres::AutoDiffCostFunction<smooth_residual_pre_2,3,3,3>(
            new smooth_residual_pre_2(weight_s, ctrl_pts[1])
        ),
        NULL,
        ctrl_pts[2].data(),ctrl_pts[3].data()
    );

    for (int i=3; i<=ctrl_pts.size()-5; i++)
    {
        problem.AddResidualBlock(
            new ceres::AutoDiffCostFunction<smooth_residual,3,3,3,3>(
                new smooth_residual(weight_s)
            ),
            NULL,
            ctrl_pts[i].data(),ctrl_pts[i+1].data(),ctrl_pts[i+2].data()
        );
    }
    
    problem.AddResidualBlock(
        new ceres::AutoDiffCostFunction<smooth_residual_post_1,3,3>(
            new smooth_residual_post_1(weight_s, ctrl_pts[ctrl_pts.size()-1],ctrl_pts[ctrl_pts.size()-2])
        ),
        NULL,
        ctrl_pts[ctrl_pts.size()-3].data()
    );
    problem.AddResidualBlock(
        new ceres::AutoDiffCostFunction<smooth_residual_post_2,3,3,3>(
            new smooth_residual_post_2(weight_s, ctrl_pts[ctrl_pts.size()-2])
        ),
        NULL,
        ctrl_pts[ctrl_pts.size()-4].data(),ctrl_pts[ctrl_pts.size()-3].data()
    );

    for (int i=0; i<ctrl_pts.size();i++)
    {
        for (int j=0; j<base_pts[i].size(); i++)
        {
            problem.AddResidualBlock(
                new ceres::AutoDiffCostFunction<collision_residual,1,3>(
                    new collision_residual(weight_c, safe_dist, esc_directions[i][j],base_pts[i][j])
                ),
                NULL,
                ctrl_pts[i].data()
            );
        }
    }
    ceres::Solver::Options option;
    option.max_num_iterations=50;
    option.minimizer_progress_to_stdout = false;
    option.linear_solver_type=ceres::DENSE_QR;
    // option.trust_region_strategy_type=ceres::DOGLEG;
    option.logging_type=ceres::SILENT;

    ceres::Solver::Summary summary;
    ceres::Solve(option,&problem,&summary);

    std::cout << "Optimize: endl;" << std::endl;
    
    return;
}

bool PathPlanner::check_collision_and_rebound(const std::vector<Eigen::Vector3d> &ctrl_pts,
                                              std::vector<std::vector<Eigen::Vector3d>> &base_pts,
                                              std::vector<std::vector<Eigen::Vector3d>> &esc_directions)
{
    std::vector<bool> temp_flags(ctrl_pts.size(),false);
    int end_idx = ctrl_pts.size()-3;
    /*** Check and segment the initial trajectory according to obstacles ***/
    int in_id, out_id;
    vector<std::pair<int, int>> segment_ids;
    bool flag_new_obs_valid = false;
    int i_end = end_idx;
    for (int i = 2; i <= i_end; ++i)
    {
        bool occ = checkCollision(ctrl_pts[i]);

        /*** check if the new collision will be valid ***/
        // 如果发现与障碍物发生碰撞，对遍历该点的每个逃逸向量以及导航点计算是否逃逸当前障碍物，
        //      如果计算距离小于零则置occ标志位为false,不需要重新获取新的障碍物导航信息
        //      否则为新障碍物需要重新定义碰撞段，astar搜索无碰撞路径，并获取新的导航信息
        if (occ)
        {
            for (size_t k = 0; k < esc_directions[i].size(); ++k)
            {
                cout.precision(2);
                if ((ctrl_pts[i] - base_pts[i][k]).dot(esc_directions[i][k]) < 1 * resolution) // current point is outside all the collision_points.
                {
                    occ = false; // Not really takes effect, just for better hunman understanding.
                    break;
                }
            }
        }

        if (occ)
        {
            flag_new_obs_valid = true;

            int j;
            for (j = i - 1; j >= 0; --j)
            {
                occ = checkCollision(ctrl_pts[j]);
                if (!occ)
                {
                    in_id = j;
                    break;
                }
            }
            if (j < 0) // fail to get the obs free point
            {
                RCLCPP_ERROR(this->get_logger(), "ERROR! the robot is in obstacle. This should not happen.");
                in_id = 0;
            }

            for (j = i + 1; j < ctrl_pts.size(); ++j)
            {
                occ = checkCollision(ctrl_pts[j]);

                if (!occ)
                {
                    out_id = j;
                    break;
                }
            }
            if (j >= ctrl_pts.size()) // fail to get the obs free point
            {
                RCLCPP_ERROR(this->get_logger(), "WARN! terminal point of the current trajectory is in obstacle, skip this planning.");
                force_stop_type_ = STOP_FOR_ERROR;
                return true;
            }

            i = j + 1;

            segment_ids.push_back(std::pair<int, int>(in_id, out_id));
        }
    }

    if (flag_new_obs_valid)
    {
        vector<vector<Eigen::Vector3d>> a_star_pathes;
        for (size_t i = 0; i < segment_ids.size(); ++i)
        {
            /*** a star search ***/
            Eigen::Vector3d in(ctrl_pts[segment_ids[i].first]), out(ctrl_pts[segment_ids[i].second]);
            if (this->AstarSearch(/*(in-out).norm()/10+0.05*/ resolution, in, out))
            {
                a_star_pathes.push_back(this->getPath());
            }
            else
            {
                RCLCPP_ERROR(this->get_logger(), "a star error");
                segment_ids.erase(segment_ids.begin() + i);
                i--;
            }
        }

        /*** Assign parameters to each segment ***/
        for (size_t i = 0; i < segment_ids.size(); ++i)
        {
            // step 1
            for (int j = segment_ids[i].first; j <= segment_ids[i].second; ++j)
                temp_flags[j] = false;

            // step 2
            int got_intersection_id = -1;
            for (int j = segment_ids[i].first + 1; j < segment_ids[i].second; ++j)
            {
                Eigen::Vector3d ctrl_pts_law(ctrl_pts[segment_ids[i].second] - ctrl_pts[segment_ids[i].first]), intersection_point;
                int Astar_id = a_star_pathes[i].size() / 2, last_Astar_id; // Let "Astar_id = id_of_the_most_far_away_Astar_point" will be better, but it needs more computation
                double val = (a_star_pathes[i][Astar_id] - ctrl_pts[j]).dot(ctrl_pts_law), last_val = val;
                while (Astar_id >= 0 && Astar_id < (int)a_star_pathes[i].size())
                {
                    last_Astar_id = Astar_id;

                    if (val >= 0)
                        --Astar_id;
                    else
                        ++Astar_id;

                    val = (a_star_pathes[i][Astar_id] - ctrl_pts[j]).dot(ctrl_pts_law);

                    // cout << val << endl;

                    if (val * last_val <= 0 && (abs(val) > 0 || abs(last_val) > 0)) // val = last_val = 0.0 is not allowed
                    {
                        intersection_point =
                            a_star_pathes[i][Astar_id] +
                            ((a_star_pathes[i][Astar_id] - a_star_pathes[i][last_Astar_id]) *
                            (ctrl_pts_law.dot(ctrl_pts[j] - a_star_pathes[i][Astar_id]) / ctrl_pts_law.dot(a_star_pathes[i][Astar_id] - a_star_pathes[i][last_Astar_id])) // = t
                            );

                        got_intersection_id = j;
                        break;
                    }
                }

                if (got_intersection_id >= 0)
                {
                    temp_flags[j] = true;
                    double length = (intersection_point - ctrl_pts[j]).norm();
                    if (length > 1e-5)
                    {
                        for (double a = length; a >= 0.0; a -= resolution)
                        {
                            bool occ = this->checkCollision((a / length) * intersection_point + (1 - a / length) * ctrl_pts[j]);

                            if (occ || a < resolution)
                            {
                                if (occ)
                                a += resolution;
                                base_pts[j].push_back((a / length) * intersection_point + (1 - a / length) * ctrl_pts[j]);
                                esc_directions[j].push_back((intersection_point - ctrl_pts[j]).normalized());
                                break;
                            }
                        }
                    }
                    else
                    {
                        got_intersection_id = -1;
                    }
                }
            }

            //step 3
            if (got_intersection_id >= 0)
            {
                for (int j = got_intersection_id + 1; j <= segment_ids[i].second; ++j)
                    if (!temp_flags[j])
                    {
                        base_pts[j].push_back(base_pts[j - 1].back());
                        esc_directions[j].push_back(esc_directions[j - 1].back());
                    }

                for (int j = got_intersection_id - 1; j >= segment_ids[i].first; --j)
                    if (!temp_flags[j])
                    {
                        base_pts[j].push_back(base_pts[j + 1].back());
                        esc_directions[j].push_back(esc_directions[j + 1].back());
                    }
            }
            else
                RCLCPP_ERROR(this->get_logger(), "Failed to generate direction. It doesn't matter.");
        }

        force_stop_type_ = STOP_FOR_REBOUND;
        return false;
    }

    return true;
}

std::vector<Eigen::Vector3d> PathPlanner::getPath()
{
    std::vector<Eigen::Vector3d> path;

    for (auto ptr : gridPath_)
        path.push_back(Index2Coord_a_star(ptr->index));

    std::reverse(path.begin(), path.end());
    return path;
}

void PathPlanner::initGridMap(/* GridMap::Ptr occ_map, */const Eigen::Vector3i pool_size)
{
    POOL_SIZE_ = pool_size;
    CENTER_IDX_ = pool_size / 2;

    GridNodeMap_ = new GridNodePtr **[POOL_SIZE_(0)];
    for (int i = 0; i < POOL_SIZE_(0); i++)
    {
        GridNodeMap_[i] = new GridNodePtr *[POOL_SIZE_(1)];
        for (int j = 0; j < POOL_SIZE_(1); j++)
        {
            GridNodeMap_[i][j] = new GridNodePtr[POOL_SIZE_(2)];
            for (int k = 0; k < POOL_SIZE_(2); k++)
            {
                GridNodeMap_[i][j][k] = new GridNode;
            }
        }
    }

    // grid_map_ = occ_map;
}

bool PathPlanner::AstarSearch(const double step_size, Eigen::Vector3d start_pt, Eigen::Vector3d end_pt)
{
    ///DEBUG:
    std::cout << "AstarSearch: start" << std::endl;
    
    rclcpp::Time time_1 = this->now();
    ++rounds_;

    step_size_ = step_size;
    inv_step_size_ = 1 / step_size;
    center_ = (start_pt + end_pt) / 2;

    Eigen::Vector3i start_idx, end_idx;
    if (!ConvertToIndexAndAdjustStartEndPoints(start_pt, end_pt, start_idx, end_idx))
    {
        RCLCPP_ERROR(this->get_logger(), "无法找到碰撞段起点或终点在栅格地图下的无碰撞位置!");
        return false;
    }

    // if ( start_pt(0) > -1 && start_pt(0) < 0 )
    //     cout << "start_pt=" << start_pt.transpose() << " end_pt=" << end_pt.transpose() << endl;

    GridNodePtr startPtr = GridNodeMap_[start_idx(0)][start_idx(1)][start_idx(2)];
    GridNodePtr endPtr = GridNodeMap_[end_idx(0)][end_idx(1)][end_idx(2)];

    std::priority_queue<GridNodePtr, std::vector<GridNodePtr>, NodeComparator> empty;
    openSet_.swap(empty);

    GridNodePtr neighborPtr = NULL;
    GridNodePtr current = NULL;

    startPtr->index = start_idx;
    startPtr->rounds = rounds_;
    startPtr->gScore = 0;
    startPtr->fScore = getHeu(startPtr, endPtr);
    startPtr->state = GridNode::OPENSET; //put start node in open set
    startPtr->cameFrom = NULL;
    openSet_.push(startPtr); //put start in open set

    endPtr->index = end_idx;

    double tentative_gScore;

    ///DEBUG:
    double duration; 

    int num_iter = 0;
    while (!openSet_.empty())
    {
        num_iter++;
        current = openSet_.top();
        openSet_.pop();

        // if ( num_iter < 10000 )
        //     cout << "current=" << current->index.transpose() << endl;

        if (current->index(0) == endPtr->index(0) && current->index(1) == endPtr->index(1) && current->index(2) == endPtr->index(2))
        {
            // ros::Time time_2 = ros::Time::now();
            // printf("\033[34mA star iter:%d, time:%.3f\033[0m\n",num_iter, (time_2 - time_1).toSec()*1000);
            // if((time_2 - time_1).toSec() > 0.1)
            //     ROS_WARN("Time consume in A star path finding is %f", (time_2 - time_1).toSec() );
            gridPath_ = retrievePath(current);
            RCLCPP_INFO(this->get_logger(),"astar 搜索时间为: %f", duration);
            return true;
        }
        current->state = GridNode::CLOSEDSET; //move current node from open set to closed set.

        for (int dx = -1; dx <= 1; dx++)
            for (int dy = -1; dy <= 1; dy++)
                for (int dz = -1; dz <= 1; dz++)
                {
                    if (dx == 0 && dy == 0 && dz == 0)
                        continue;

                    Eigen::Vector3i neighborIdx;
                    neighborIdx(0) = (current->index)(0) + dx;
                    neighborIdx(1) = (current->index)(1) + dy;
                    neighborIdx(2) = (current->index)(2) + dz;

                    if (neighborIdx(0) < 1 || neighborIdx(0) >= POOL_SIZE_(0) - 1 || neighborIdx(1) < 1 || neighborIdx(1) >= POOL_SIZE_(1) - 1 || neighborIdx(2) < 1 || neighborIdx(2) >= POOL_SIZE_(2) - 1)
                    {
                        continue;
                    }

                    neighborPtr = GridNodeMap_[neighborIdx(0)][neighborIdx(1)][neighborIdx(2)];
                    neighborPtr->index = neighborIdx;

                    bool flag_explored = neighborPtr->rounds == rounds_;

                    if (flag_explored && neighborPtr->state == GridNode::CLOSEDSET)
                    {
                        continue; //in closed set.
                    }

                    neighborPtr->rounds = rounds_;

                    if (checkCollision(Index2Coord_a_star(neighborPtr->index)))
                    {
                        continue;
                    }

                    double static_cost = sqrt(dx * dx + dy * dy + dz * dz);
                    tentative_gScore = current->gScore + static_cost;

                    if (!flag_explored)
                    {
                        //discover a new node
                        neighborPtr->state = GridNode::OPENSET;
                        neighborPtr->cameFrom = current;
                        neighborPtr->gScore = tentative_gScore;
                        neighborPtr->fScore = tentative_gScore + getHeu(neighborPtr, endPtr);
                        openSet_.push(neighborPtr); //put neighbor in open set and record it.
                    }
                    else if (tentative_gScore < neighborPtr->gScore)
                    { //in open set and need update
                        neighborPtr->cameFrom = current;
                        neighborPtr->gScore = tentative_gScore;
                        neighborPtr->fScore = tentative_gScore + getHeu(neighborPtr, endPtr);
                    }
                }
        rclcpp::Time time_2 = this->now();

        ///DEBUG: 
        duration = (double)(time_2-time_1).seconds();

        if ((double)(time_2 - time_1).nanoseconds()/1e9 > 15.0)
        {
            RCLCPP_WARN(this->get_logger(), "Failed in A star path searching !!! 0.2 seconds time limit exceeded.");
            return false;
        }
    }

    rclcpp::Time time_2 = this->now();

    if ((time_2 - time_1).nanoseconds()/1e9 > 0.1)
        RCLCPP_WARN(this->get_logger(), "A_star路径搜索时间: %.3fs, iter=%d", (time_2 - time_1).seconds(), num_iter);

    return false;
}

bool PathPlanner::ConvertToIndexAndAdjustStartEndPoints(Eigen::Vector3d start_pt, Eigen::Vector3d end_pt, Eigen::Vector3i &start_idx, Eigen::Vector3i &end_idx)
{
    if (!Coord2Index_a_star(start_pt, start_idx) || !Coord2Index_a_star(end_pt, end_idx))
        return false;

    if (checkCollision(Index2Coord_a_star(start_idx)))
    {
        //ROS_WARN("Start point is inside an obstacle.");
        do
        {
            start_pt = (start_pt - end_pt).normalized() * step_size_ + start_pt;
            if (!Coord2Index_a_star(start_pt, start_idx))
                return false;
        } while (checkCollision(Index2Coord_a_star(start_idx)));
    }

    if (checkCollision(Index2Coord_a_star(end_idx)))
    {
        //ROS_WARN("End point is inside an obstacle.");
        do
        {
            end_pt = (end_pt - start_pt).normalized() * step_size_ + end_pt;
            if (!Coord2Index_a_star(end_pt, end_idx))
                return false;
        } while (checkCollision(Index2Coord_a_star(end_idx)));
    }

    return true;
}

double PathPlanner::getDiagHeu(GridNodePtr node1, GridNodePtr node2)
{
    double dx = abs(node1->index(0) - node2->index(0));
    double dy = abs(node1->index(1) - node2->index(1));
    double dz = abs(node1->index(2) - node2->index(2));

    double h = 0.0;
    int diag = min(min(dx, dy), dz);
    dx -= diag;
    dy -= diag;
    dz -= diag;

    if (dx == 0)
    {
        h = 1.0 * sqrt(3.0) * diag + sqrt(2.0) * min(dy, dz) + 1.0 * abs(dy - dz);
    }
    if (dy == 0)
    {
        h = 1.0 * sqrt(3.0) * diag + sqrt(2.0) * min(dx, dz) + 1.0 * abs(dx - dz);
    }
    if (dz == 0)
    {
        h = 1.0 * sqrt(3.0) * diag + sqrt(2.0) * min(dx, dy) + 1.0 * abs(dx - dy);
    }
    return h;
}

vector<GridNodePtr> PathPlanner::retrievePath(GridNodePtr current)
{
    vector<GridNodePtr> path;
    path.push_back(current);

    while (current->cameFrom != NULL)
    {
        current = current->cameFrom;
        path.push_back(current);
    }

    return path;
}

// Corrects points outside the boundary
void PathPlanner::boundCorrect(int &x, int &y, int &z)
{
    x = std::min(std::max(0,x), grid_map_size_x-1);
    y = std::min(std::max(0,y), grid_map_size_y-1);
    z = std::min(std::max(0,z), grid_map_size_z-1);
    return;
}

bool PathPlanner::checkCollision(const Eigen::Vector3d &coor)
{
    Eigen::Vector3i temp_index;
    bool flag = this->coorToIndex(coor, temp_index);
    if(!flag)
    {

        RCLCPP_ERROR(this->get_logger(), "exceed the bound of map");
    }
    return this->grid_map[temp_index.x()][temp_index.y()][temp_index.z()];
}

bool PathPlanner::coorToIndex(const Eigen::Vector3d &coor, Eigen::Vector3i &index)
{
    if (   coor.x() < grid_map_start_point.x()
        || coor.y() < grid_map_start_point.y()
        || coor.z() < grid_map_start_point.z()
        || coor.x() > grid_map_end_point.x()
        || coor.y() > grid_map_end_point.y()
        || coor.z() > grid_map_end_point.z())
    {
        RCLCPP_ERROR(this->get_logger(), "exceed the bound of map");
        return false;
    }
    index.x() = std::floor((coor.x()-grid_map_start_point.x())/resolution);
    index.y() = std::floor((coor.y()-grid_map_start_point.y())/resolution);
    index.z() = std::floor((coor.z()-grid_map_start_point.z())/resolution);
    return true;
}
