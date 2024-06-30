#include "map_node.hpp"


MapNode::MapNode():Node("map")
{
    flag_build_map = false;
    cv::FileStorage file_read("/home/weiwei/Desktop/project/path_planner/src/map/map.yaml", cv::FileStorage::READ);
    build_step = file_read["build_step"];
    double x1 = file_read["map_flag_point1_x"];
    double y1 = file_read["map_flag_point1_y"];
    double z1 = file_read["map_flag_point1_z"];
    double x2 = file_read["map_flag_point2_x"];
    double y2 = file_read["map_flag_point2_y"];
    double z2 = file_read["map_flag_point2_z"];
    double x3 = file_read["map_flag_point3_x"];
    double y3 = file_read["map_flag_point3_y"];
    double z3 = file_read["map_flag_point3_z"];

    Eigen::Vector3d flag_point1(x1,y1,z1);
    Eigen::Vector3d flag_point2(x2,y2,z2);
    Eigen::Vector3d flag_point3(x3,y3,z3);
    if (flag_point1.norm()<1e-4)
    {
        while(rclcpp::sleep_for(std::chrono::seconds(2)))
            RCLCPP_ERROR(this->get_logger(),"未输入障碍物地图标记点！");
    }

    buildMap(flag_point1,flag_point2,flag_point3);
    obstacle_pub = this->create_publisher<sensor_msgs::msg::PointCloud>("obs_pcl",10);                  
    pub_map_timer = this->create_wall_timer(std::chrono::seconds(2),std::bind(&MapNode::pubMapCallback,this));
    return;
}

void MapNode::pubMapCallback()
{
    if (!flag_build_map)
    {
        RCLCPP_WARN(this->get_logger(),"未成功构建地图，退出中！");
        return;
    }
    obstacle_pub->publish(obs_pcl_msg);
    RCLCPP_INFO(this->get_logger(),"成功发布地图！");
}

void MapNode::buildMap(const Eigen::Vector3d &flag_point1, const Eigen::Vector3d &flag_point2, const Eigen::Vector3d &flag_point3)
{
    // 开始构建障碍物结构
    RCLCPP_INFO(this->get_logger(), "开始构建障碍物结构件点云");
    // 赋值特殊结构尺寸，例如中间障碍物板子的通道宽度
    double zSize = 440.0,xSize = 440.0,ySize = 735.0;
    double circle_radius = 100.0, structureGapSize1 = 260.0, structureGapSize2 = 250.0;
    double frontToStructureSize1 = 185.0, frontToStructureSize2 = 410.0;
    // 根据标记点开始构建坐标系
    Eigen::Vector3d x_axis = flag_point2-flag_point1;
    Eigen::Vector3d y_axis = flag_point3-flag_point1;
    x_axis.normalize();
    y_axis.normalize();
    Eigen::Vector3d z_axis = x_axis.cross(y_axis);
    Eigen::Vector3d obs_centre = x_axis * 0.5 * xSize + flag_point1 - z_axis * 0.5 * zSize;

    // 首先根据障碍物圆心点以及结构尺寸确定各个结构点位置坐标
    Eigen::Vector3d frontLeftUnder,frontLeftUp,frontRightUnder,backLeftUnder,structureLeftUnder1,structureLeftUnder2;
    frontLeftUnder = obs_centre-xSize*0.5*x_axis-zSize*0.5*z_axis;
    frontLeftUp = flag_point1;
    frontRightUnder = obs_centre+xSize*0.5*x_axis-zSize*0.5*z_axis;
    backLeftUnder = obs_centre-xSize*0.5*x_axis-zSize*0.5*z_axis+ySize*y_axis;
    structureLeftUnder1 = obs_centre+frontToStructureSize1*y_axis-xSize*0.5*x_axis-zSize*0.5*z_axis;
    structureLeftUnder2 = obs_centre+frontToStructureSize2*y_axis-xSize*0.5*x_axis-zSize*0.5*z_axis;

    // 计算构建结构点云时的步进数量
    int buildStepNum_x = ceil(xSize/build_step);
    int buildStepNum_z = ceil(zSize/build_step);
    int buildStepNum_y = ceil(ySize/build_step);
    // 构建前面板结构
    for (int i=1;i<buildStepNum_z;i++)
    {  
        for(int j=1;j<buildStepNum_x;j++)
        {
            Eigen::Vector3d pointPosition = frontLeftUnder+(frontLeftUp-frontLeftUnder)*((double)i/(double)buildStepNum_z)+(frontRightUnder-frontLeftUnder)*((double)j/(double)buildStepNum_x);
            if ((pointPosition-obs_centre).norm() < circle_radius)
                continue;
            pcl::PointXYZ point((float)pointPosition.x(),(float)pointPosition.y(),(float)pointPosition.z());

            geometry_msgs::msg::Point32 temp_point;
            temp_point.x = point.x;
            temp_point.y = point.y;
            temp_point.z = point.z;
            obs_pcl_msg.points.push_back(temp_point);
        }
    }
    // 构建后板结构
    for (int i=1;i<buildStepNum_z;i++)
    {  
        for(int j=1;j<buildStepNum_x;j++)
        {
            Eigen::Vector3d pointPosition = backLeftUnder+(frontLeftUp-frontLeftUnder)*((double)i/(double)buildStepNum_z)+(frontRightUnder-frontLeftUnder)*((double)j/(double)buildStepNum_x);
            pcl::PointXYZ point((float)pointPosition.x(),(float)pointPosition.y(),(float)pointPosition.z());
            geometry_msgs::msg::Point32 temp_point;
            temp_point.x = point.x;
            temp_point.y = point.y;
            temp_point.z = point.z;
            obs_pcl_msg.points.push_back(temp_point);
        }
    }
    // 构建左边板子结构
    for (int i=1;i<buildStepNum_z;i++)
    {  
        for(int j=1;j<buildStepNum_y;j++)
        {
            Eigen::Vector3d pointPosition = frontLeftUnder+(frontLeftUp-frontLeftUnder)*((double)i/(double)buildStepNum_z)+(backLeftUnder-frontLeftUnder)*((double)j/(double)buildStepNum_y);
            pcl::PointXYZ point((float)pointPosition.x(),(float)pointPosition.y(),(float)pointPosition.z());
            geometry_msgs::msg::Point32 temp_point;
            temp_point.x = point.x;
            temp_point.y = point.y;
            temp_point.z = point.z;
            obs_pcl_msg.points.push_back(temp_point);
        }
    }
    // 构建上板
    for (int i=1;i<buildStepNum_x;i++)
    {  
        for(int j=1;j<buildStepNum_y;j++)
        {
            Eigen::Vector3d pointPosition = frontLeftUp+(frontRightUnder-frontLeftUnder)*((double)i/(double)buildStepNum_x)+(backLeftUnder-frontLeftUnder)*((double)j/(double)buildStepNum_y);
            pcl::PointXYZ point((float)pointPosition.x(),(float)pointPosition.y(),(float)pointPosition.z());
            geometry_msgs::msg::Point32 temp_point;
            temp_point.x = point.x;
            temp_point.y = point.y;
            temp_point.z = point.z;
            obs_pcl_msg.points.push_back(temp_point);
        }
    }
    // 构建右板
    for (int i=1;i<buildStepNum_z;i++)
    {  
        for(int j=1;j<buildStepNum_y;j++)
        {
            Eigen::Vector3d pointPosition = frontRightUnder+(frontLeftUp-frontLeftUnder)*((double)i/(double)buildStepNum_z)+(backLeftUnder-frontLeftUnder)*((double)j/(double)buildStepNum_y);
            pcl::PointXYZ point((float)pointPosition.x(),(float)pointPosition.y(),(float)pointPosition.z());
            geometry_msgs::msg::Point32 temp_point;
            temp_point.x = point.x;
            temp_point.y = point.y;
            temp_point.z = point.z;
            obs_pcl_msg.points.push_back(temp_point);
        }
    }
    // 构建下板pclToGridMap
    for (int i=1;i<buildStepNum_x;i++)
    {  
        for(int j=1;j<buildStepNum_y;j++)
        {
            Eigen::Vector3d pointPosition = frontLeftUnder+(frontRightUnder-frontLeftUnder)*((double)i/(double)buildStepNum_x)+(backLeftUnder-frontLeftUnder)*((double)j/(double)buildStepNum_y);
            pcl::PointXYZ point((float)pointPosition.x(),(float)pointPosition.y(),(float)pointPosition.z());
            geometry_msgs::msg::Point32 temp_point;
            temp_point.x = point.x;
            temp_point.y = point.y;
            temp_point.z = point.z;
            obs_pcl_msg.points.push_back(temp_point);
        }
    }
    // 构建障碍物中间前板
    for (int i=1;i<buildStepNum_z;i++)
    {  
        for(int j=1;j<buildStepNum_x;j++)
        {
            Eigen::Vector3d pointPosition = structureLeftUnder1+(frontLeftUp-frontLeftUnder)*((double)i/(double)buildStepNum_z)+(frontRightUnder-frontLeftUnder)*((double)j/(double)buildStepNum_x);
            if ((double)i>(zSize-structureGapSize1)/build_step && (double)j<structureGapSize1/build_step)
                continue;
            pcl::PointXYZ point((float)pointPosition.x(),(float)pointPosition.y(),(float)pointPosition.z());
            geometry_msgs::msg::Point32 temp_point;
            temp_point.x = point.x;
            temp_point.y = point.y;
            temp_point.z = point.z;
            obs_pcl_msg.points.push_back(temp_point);
        }
    }
    // 构建障碍物中间后板
    for (int i=1;i<buildStepNum_z;i++)
    {  
        for(int j=1;j<buildStepNum_x;j++)
        {
            Eigen::Vector3d pointPosition = structureLeftUnder2+(frontLeftUp-frontLeftUnder)*((double)i/(double)buildStepNum_z)+(frontRightUnder-frontLeftUnder)*((double)j/(double)buildStepNum_x);
            if ((double)i<structureGapSize2/build_step && (double)j>(xSize-structureGapSize2)/build_step)
                continue;
            pcl::PointXYZ point((float)pointPosition.x(),(float)pointPosition.y(),(float)pointPosition.z());
            geometry_msgs::msg::Point32 temp_point;
            temp_point.x = point.x;
            temp_point.y = point.y;
            temp_point.z = point.z;
            obs_pcl_msg.points.push_back(temp_point);
        }
    }
    flag_build_map = true;
    return;
}