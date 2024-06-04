#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <sensor_msgs/msg/point_cloud.hpp>
#include <Eigen/Eigen>
#include "sophus/so3.hpp"
#include "sophus/se3.hpp"
#include "pcl/point_cloud.h"
#include "visualization_msgs/msg/marker.hpp"
#include "visualization_msgs/msg/marker_array.hpp"
#include <opencv2/core/eigen.hpp>
#include <opencv2/opencv.hpp>
#include "cv_bridge/cv_bridge.h"
#include "pcl_conversions/pcl_conversions.h"
#include "pcl/common/transforms.h"
#include <pcl/point_types.h>
#include <ceres/ceres.h>
#include "uniform_bspline.hpp"
#include "interface/srv/path_plan.hpp"

using namespace std::placeholders;

constexpr double inf = 1 >> 20;
struct GridNode;
typedef GridNode *GridNodePtr;

struct GridNode
{
    enum enum_state
    {
        OPENSET = 1,
        CLOSEDSET = 2,
        UNDEFINED = 3
    };

    int rounds{0}; // Distinguish every call
    enum enum_state state
    {
        UNDEFINED
    };
    // a_star 栅格地图下的索引
    Eigen::Vector3i index;

    double gScore{inf}, fScore{inf};
    GridNodePtr cameFrom{NULL};
};

class NodeComparator
{
public:
    bool operator()(GridNodePtr node1, GridNodePtr node2)
    {
        return node1->fScore > node2->fScore;
    }
};

class PathPlanner:public rclcpp::Node
{
private:

    // 用来判断是否接收障碍物点云并初始化了障碍物栅格地图标志位
    bool flag_get_map;

    // 优化函数有关的安全距离
    double safe_dist;
    // 碰撞项以及平滑项优化损失函数项权重系数
    double weight_s,weight_c,weight_s_acc;

    int grid_map_size_x,grid_map_size_z,grid_map_size_y;

    std::vector<std::vector<std::vector<bool>>> grid_map;

    double resolution;

    double inflation_radius;
    int inflation_radius_grid;

    Eigen::Vector3d grid_map_origin_point, grid_map_end_point, grid_map_start_point;

    double time_interval;
    // 初始化控制点间距
    double ctrl_pt_interval; 

    double min_plan_dist;

    int degree;

    int rounds_; // distinguish the round of a_star search;

    double tie_breaker_;

    Eigen::Vector3i POOL_SIZE_, CENTER_IDX_;

    GridNodePtr ***GridNodeMap_;

    std::priority_queue<GridNodePtr, std::vector<GridNodePtr>, NodeComparator> openSet_;

    double step_size_, inv_step_size_;
    Eigen::Vector3d center_;

    std::vector<GridNodePtr> gridPath_;
    // 声明路径规划服务端
    rclcpp::Service<interface::srv::PathPlan>::SharedPtr path_plan_service;
    rclcpp::Subscription<sensor_msgs::msg::PointCloud>::SharedPtr map_sub;
    rclcpp::Publisher<sensor_msgs::msg::PointCloud>::SharedPtr map_pub;
    rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr marker_pub;

    enum FORCE_STOP_OPTIMIZE_TYPE
    {
      DONT_STOP,
      STOP_FOR_REBOUND,
      STOP_FOR_ERROR
    } force_stop_type_;

    // 加速度平滑性损失函数结构体
	struct acc_smooth_residual{
		acc_smooth_residual(double weight_acc_smooth):ws(weight_acc_smooth) {}
		template <typename T> 
		bool operator()(const T* const ctrl_pt_1, const T* const ctrl_pt_2, const T* const ctrl_pt_3, const T* const ctrl_pt_4, T* residual) const {
            residual[0] = sqrt(ws)*9.0*((ctrl_pt_4[0]-ctrl_pt_3[0]-ctrl_pt_3[0]+ctrl_pt_2[0])-(ctrl_pt_3[0]-ctrl_pt_2[0]-ctrl_pt_2[0]+ctrl_pt_1[0]));
            residual[1] = sqrt(ws)*9.0*((ctrl_pt_4[1]-ctrl_pt_3[1]-ctrl_pt_3[1]+ctrl_pt_2[1])-(ctrl_pt_3[1]-ctrl_pt_2[1]-ctrl_pt_2[1]+ctrl_pt_1[1]));
            residual[2] = sqrt(ws)*9.0*((ctrl_pt_4[2]-ctrl_pt_3[2]-ctrl_pt_3[2]+ctrl_pt_2[2])-(ctrl_pt_3[2]-ctrl_pt_2[2]-ctrl_pt_2[2]+ctrl_pt_1[2]));
			return true;
		}
	private: 
		const double ws; 
	};
    // 加速度平滑性损失函数结构体
	struct acc_smooth_residual_pre_1{
		acc_smooth_residual_pre_1(double weight_acc_smooth, Eigen::Vector3d ctrl_pt_0, Eigen::Vector3d ctrl_pt_1):
            ws(weight_acc_smooth), ctrl_pt_0_(ctrl_pt_0), ctrl_pt_1_(ctrl_pt_1){}
		template <typename T> 
		bool operator()(const T* const ctrl_pt_2, const T* const ctrl_pt_3, T* residual) const {
            residual[0] = sqrt(ws)*9.0*((ctrl_pt_0_.x()-ctrl_pt_1_.x()-ctrl_pt_1_.x()+ctrl_pt_2[0])-(ctrl_pt_1_.x()-ctrl_pt_2[0]-ctrl_pt_2[0]+ctrl_pt_3[0]));
            residual[1] = sqrt(ws)*9.0*((ctrl_pt_0_.y()-ctrl_pt_1_.y()-ctrl_pt_1_.y()+ctrl_pt_2[1])-(ctrl_pt_1_.y()-ctrl_pt_2[1]-ctrl_pt_2[1]+ctrl_pt_3[1]));
            residual[2] = sqrt(ws)*9.0*((ctrl_pt_0_.z()-ctrl_pt_1_.z()-ctrl_pt_1_.z()+ctrl_pt_2[2])-(ctrl_pt_1_.z()-ctrl_pt_2[2]-ctrl_pt_2[2]+ctrl_pt_3[2]));
			return true;
		}
	private: 
		const double ws; 
        const Eigen::Vector3d ctrl_pt_0_; 
		const Eigen::Vector3d ctrl_pt_1_; 
	};
    // 加速度平滑性损失函数结构体
	struct acc_smooth_residual_pre_2{
		acc_smooth_residual_pre_2(double weight_acc_smooth, Eigen::Vector3d ctrl_pt_1):
            ws(weight_acc_smooth), ctrl_pt_1_(ctrl_pt_1){}
		template <typename T> 
		bool operator()(const T* const ctrl_pt_2, const T* const ctrl_pt_3, const T* const ctrl_pt_4, T* residual) const {
            residual[0] = sqrt(ws)*9.0*((ctrl_pt_1_.x()-ctrl_pt_2[0]-ctrl_pt_2[0]+ctrl_pt_3[0])-(ctrl_pt_2[0]-ctrl_pt_3[0]-ctrl_pt_3[0]+ctrl_pt_4[0]));
            residual[1] = sqrt(ws)*9.0*((ctrl_pt_1_.y()-ctrl_pt_2[1]-ctrl_pt_2[1]+ctrl_pt_3[1])-(ctrl_pt_2[1]-ctrl_pt_3[1]-ctrl_pt_3[1]+ctrl_pt_4[1]));
            residual[2] = sqrt(ws)*9.0*((ctrl_pt_1_.z()-ctrl_pt_2[2]-ctrl_pt_2[2]+ctrl_pt_3[2])-(ctrl_pt_2[2]-ctrl_pt_3[2]-ctrl_pt_3[2]+ctrl_pt_4[2]));
			return true;
		}
	private: 
		const double ws; 
		const Eigen::Vector3d ctrl_pt_1_; 
	};
    // 加速度平滑性损失函数结构体
	struct acc_smooth_residual_post_2{
		acc_smooth_residual_post_2(double weight_acc_smooth, Eigen::Vector3d ctrl_pt_2):
            ws(weight_acc_smooth), ctrl_pt_2_(ctrl_pt_2){}
		template <typename T> 
		bool operator()(const T* const ctrl_pt_3, const T* const ctrl_pt_4, const T* const ctrl_pt_5, T* residual) const {
            residual[0] = sqrt(ws)*9.0*((ctrl_pt_5[0]-ctrl_pt_4[0]-ctrl_pt_4[0]+ctrl_pt_3[0])-(ctrl_pt_4[0]-ctrl_pt_3[0]-ctrl_pt_3[0]+ctrl_pt_2_.x()));
            residual[1] = sqrt(ws)*9.0*((ctrl_pt_5[1]-ctrl_pt_4[1]-ctrl_pt_4[1]+ctrl_pt_3[1])-(ctrl_pt_4[1]-ctrl_pt_3[1]-ctrl_pt_3[1]+ctrl_pt_2_.y()));
            residual[2] = sqrt(ws)*9.0*((ctrl_pt_5[2]-ctrl_pt_4[2]-ctrl_pt_4[2]+ctrl_pt_3[2])-(ctrl_pt_4[2]-ctrl_pt_3[2]-ctrl_pt_3[2]+ctrl_pt_2_.z()));
			return true;
		}
	private: 
		const double ws; 
		const Eigen::Vector3d ctrl_pt_2_; 
	};
    // 加速度平滑性损失函数结构体
	struct acc_smooth_residual_post_1{
		acc_smooth_residual_post_1(double weight_acc_smooth, Eigen::Vector3d ctrl_pt_1, Eigen::Vector3d ctrl_pt_2):
            ws(weight_acc_smooth), ctrl_pt_1_(ctrl_pt_1), ctrl_pt_2_(ctrl_pt_2){}
		template <typename T> 
		bool operator()(const T* const ctrl_pt_3, const T* const ctrl_pt_4, T* residual) const {
            residual[0] = sqrt(ws)*9.0*((ctrl_pt_4[0]-ctrl_pt_3[0]-ctrl_pt_3[0]+ctrl_pt_2_.x())-(ctrl_pt_3[0]-ctrl_pt_2_.x()-ctrl_pt_2_.x()+ctrl_pt_1_.x()));
            residual[1] = sqrt(ws)*9.0*((ctrl_pt_4[1]-ctrl_pt_3[1]-ctrl_pt_3[1]+ctrl_pt_2_.y())-(ctrl_pt_3[1]-ctrl_pt_2_.y()-ctrl_pt_2_.y()+ctrl_pt_1_.y()));
            residual[2] = sqrt(ws)*9.0*((ctrl_pt_4[2]-ctrl_pt_3[2]-ctrl_pt_3[2]+ctrl_pt_2_.z())-(ctrl_pt_3[2]-ctrl_pt_2_.z()-ctrl_pt_2_.z()+ctrl_pt_1_.z()));
			return true;
		}
	private: 
		const double ws; 
		const Eigen::Vector3d ctrl_pt_1_; 
		const Eigen::Vector3d ctrl_pt_2_; 
	};
	// 平滑性损失函数结构体
	struct smooth_residual{
		smooth_residual(double weight_smooth):ws(weight_smooth) {}
		template <typename T> 
		bool operator()(const T* const ctrl_pt_pre, const T* const ctrl_pt_mid, const T* const ctrl_pt_post, T* residual) const {
            residual[0] = sqrt(ws)*3.0*(ctrl_pt_pre[0]-ctrl_pt_mid[0]+ctrl_pt_post[0]-ctrl_pt_mid[0]);
            residual[1] = sqrt(ws)*3.0*(ctrl_pt_pre[1]-ctrl_pt_mid[1]+ctrl_pt_post[1]-ctrl_pt_mid[1]);
            residual[2] = sqrt(ws)*3.0*(ctrl_pt_pre[2]-ctrl_pt_mid[2]+ctrl_pt_post[2]-ctrl_pt_mid[2]);
			return true;
		}
	private: 
		const double ws; 
	};

	// 第2个控制点与第0个以及第1个控制点构建的平滑性损失函数结构体
	struct smooth_residual_pre_1{
		smooth_residual_pre_1(double weight_smooth,
                             Eigen::Vector3d ctrl_pt_0,
                             Eigen::Vector3d ctrl_pt_1):
                             ws_(weight_smooth) ,
                             ctrl_pt_0_(ctrl_pt_0),
                             ctrl_pt_1_(ctrl_pt_1){}
		template <typename T> 
		bool operator()(const T* const ctrl_pt, T* residual) const {
            residual[0] = sqrt(ws_)*3.0*(ctrl_pt_0_.x()-ctrl_pt_1_.x()+ctrl_pt[0]-ctrl_pt_1_.x());
            residual[1] = sqrt(ws_)*3.0*(ctrl_pt_0_.y()-ctrl_pt_1_.y()+ctrl_pt[1]-ctrl_pt_1_.y());
            residual[2] = sqrt(ws_)*3.0*(ctrl_pt_0_.z()-ctrl_pt_1_.z()+ctrl_pt[2]-ctrl_pt_1_.z());
			return true;
		}
	private: 
		const double ws_; 
		const Eigen::Vector3d ctrl_pt_0_; 
		const Eigen::Vector3d ctrl_pt_1_; 
	};
	// 第2个控制点与第1个控制点以及第3个控制点构建的平滑性损失函数结构体
	struct smooth_residual_pre_2{
		smooth_residual_pre_2(double weight_smooth,
                             Eigen::Vector3d ctrl_pt_1):
                             ws_(weight_smooth),
                             ctrl_pt_1_(ctrl_pt_1){}
		template <typename T> 
		bool operator()(const T* const ctrl_pt_2,const T* const ctrl_pt_3, T* residual) const {
            residual[0] = sqrt(ws_)*3.0*(ctrl_pt_1_.x()-ctrl_pt_2[0]+ctrl_pt_3[0]-ctrl_pt_2[0]);
            residual[1] = sqrt(ws_)*3.0*(ctrl_pt_1_.y()-ctrl_pt_2[1]+ctrl_pt_3[1]-ctrl_pt_2[1]);
            residual[2] = sqrt(ws_)*3.0*(ctrl_pt_1_.z()-ctrl_pt_2[2]+ctrl_pt_3[2]-ctrl_pt_2[2]);
			return true;
		}
	private: 
		const double ws_; 
		const Eigen::Vector3d ctrl_pt_1_; 
	};
	// 倒数第2个控制点与倒数第1个控制点以及倒数第3个控制点构建的平滑性损失函数结构体
	struct smooth_residual_post_1{
		smooth_residual_post_1(double weight_smooth,
                             Eigen::Vector3d ctrl_pt_back_1,
                             Eigen::Vector3d ctrl_pt_back_2):
                             ws_(weight_smooth),
                             ctrl_pt_back_1_(ctrl_pt_back_1),
                             ctrl_pt_back_2_(ctrl_pt_back_2){}
		template <typename T> 
		bool operator()(const T* const ctrl_pt_back_3, T* residual) const {
            residual[0] = sqrt(ws_)*3.0*(ctrl_pt_back_3[0]-ctrl_pt_back_2_.x()+ctrl_pt_back_1_.x()-ctrl_pt_back_2_.x());
            residual[1] = sqrt(ws_)*3.0*(ctrl_pt_back_3[1]-ctrl_pt_back_2_.y()+ctrl_pt_back_1_.y()-ctrl_pt_back_2_.y());
            residual[2] = sqrt(ws_)*3.0*(ctrl_pt_back_3[2]-ctrl_pt_back_2_.z()+ctrl_pt_back_1_.z()-ctrl_pt_back_2_.z());
			return true;
		}
	private: 
		const double ws_; 
		const Eigen::Vector3d ctrl_pt_back_1_,ctrl_pt_back_2_; 
	};
	// 倒数第2个控制点与倒数第1个控制点以及倒数第3个控制点构建的平滑性损失函数结构体
	struct smooth_residual_post_2{
		smooth_residual_post_2(double weight_smooth,
                             Eigen::Vector3d ctrl_pt_back_2):
                             ws_(weight_smooth),
                             ctrl_pt_back_2_(ctrl_pt_back_2) {}
		template <typename T> 
		bool operator()(const T* const ctrl_pt_back_4,const T* const ctrl_pt_back_3, T* residual) const {
            residual[0] = sqrt(ws_)*3.0*(ctrl_pt_back_4[0]-ctrl_pt_back_3[0]+ctrl_pt_back_2_.x()-ctrl_pt_back_3[0]);
            residual[1] = sqrt(ws_)*3.0*(ctrl_pt_back_4[1]-ctrl_pt_back_3[1]+ctrl_pt_back_2_.y()-ctrl_pt_back_3[1]);
            residual[2] = sqrt(ws_)*3.0*(ctrl_pt_back_4[2]-ctrl_pt_back_3[2]+ctrl_pt_back_2_.z()-ctrl_pt_back_3[2]);
			return true;
		}
	private: 
		const double ws_; 
		const Eigen::Vector3d ctrl_pt_back_2_; 
	};

	// 碰撞损失函数
	struct collision_residual{
		collision_residual(double weight_collision,
                          double safe_distance,
                          Eigen::Vector3d esc_direct,
                          Eigen::Vector3d base_point
                          ):
                          wc_(weight_collision),
                          sd_(safe_distance),
                          esc_direct_(esc_direct),
                          base_point_(base_point) {}
		template <typename T> 
		bool operator()(const T* const ctrl_pt, T* residual) const {

            T d = esc_direct_.x()*(ctrl_pt[0]-base_point_.x())+esc_direct_.y()*(ctrl_pt[1]-base_point_.y())+esc_direct_.z()*(ctrl_pt[2]-base_point_.z());
            T c = sd_ - d;
            if (c > sd_) {
                residual[0] = sqrt(wc_)*(3.0*sd_*pow(c,2)-3*pow(sd_,2)*c+pow(sd_,3));
            }
            else if (0.0<c<=sd_) {
                residual[0] = sqrt(wc_)*pow(c,3);
            }
            else {
                // residual[0] = (T)0.0;
            }
			return true;
		}
	private: 
		const double wc_; 
		const double sd_; 
		const Eigen::Vector3d esc_direct_;
        const Eigen::Vector3d base_point_; 
	};
    
    inline double getHeu(GridNodePtr node1, GridNodePtr node2);
    inline bool Coord2Index_a_star(const Eigen::Vector3d &pt, Eigen::Vector3i &idx) const;
    inline Eigen::Vector3d Index2Coord_a_star(const Eigen::Vector3i &index) const;

public:
    PathPlanner();

    void planPathCallback(const interface::srv::PathPlan::Request::SharedPtr request,
                        const interface::srv::PathPlan::Response::SharedPtr response);
    void mapCallback(const sensor_msgs::msg::PointCloud::SharedPtr map_msg);
    void boundCorrect(int &x, int &y, int &z);

    std::vector<Eigen::Vector3d> initControlPoints(const Eigen::Vector3d &start_pos, const Eigen::Vector3d &end_pos,
                                                    const Eigen::Vector3d &start_dir, const Eigen::Vector3d &end_dir);

    bool getBasePointsAndDirection(const std::vector<Eigen::Vector3d> &ctrl_pts, 
                                    std::vector<std::vector<Eigen::Vector3d>> &base_pts,
                                    std::vector<std::vector<Eigen::Vector3d>> &esc_directions);

    void Optimize(std::vector<Eigen::Vector3d> &ctrl_pts, 
                  const std::vector<std::vector<Eigen::Vector3d>> &base_pts,
                  const std::vector<std::vector<Eigen::Vector3d>> &esc_directions);

    bool checkCollision(const Eigen::Vector3d &coor);

    bool coorToIndex(const Eigen::Vector3d &coor, Eigen::Vector3i &index);

    bool AstarSearch(const double step_size, Eigen::Vector3d start_pt, Eigen::Vector3d end_pt);

    std::vector<Eigen::Vector3d> getPath();

    bool ConvertToIndexAndAdjustStartEndPoints(Eigen::Vector3d start_pt, Eigen::Vector3d end_pt, Eigen::Vector3i &start_idx, Eigen::Vector3i &end_idx);

    void initGridMap(/* GridMap::Ptr occ_map, */const Eigen::Vector3i pool_size);

    double getDiagHeu(GridNodePtr node1, GridNodePtr node2);

    vector<GridNodePtr> retrievePath(GridNodePtr current);

    bool check_collision_and_rebound(const std::vector<Eigen::Vector3d> &ctrl_pts,
                                     std::vector<std::vector<Eigen::Vector3d>> &base_pts,
                                     std::vector<std::vector<Eigen::Vector3d>> &esc_directions);
};

inline Eigen::Vector3d PathPlanner::Index2Coord_a_star(const Eigen::Vector3i &index) const
{
    return ((index - CENTER_IDX_).cast<double>() * step_size_) + center_;
};

inline bool PathPlanner::Coord2Index_a_star(const Eigen::Vector3d &pt, Eigen::Vector3i &idx) const
{
    ///TODO: 这里改动是否合理有待考证
    // idx = ((pt - center_) * inv_step_size_ + Eigen::Vector3d(0.5, 0.5, 0.5)).cast<int>() + CENTER_IDX_;
    idx.x() = std::floor(((pt - center_) * inv_step_size_ + Eigen::Vector3d(0.5, 0.5, 0.5)).x()) + CENTER_IDX_.x();
    idx.y() = std::floor(((pt - center_) * inv_step_size_ + Eigen::Vector3d(0.5, 0.5, 0.5)).y()) + CENTER_IDX_.y();
    idx.z() = std::floor(((pt - center_) * inv_step_size_ + Eigen::Vector3d(0.5, 0.5, 0.5)).z()) + CENTER_IDX_.z();

    if (idx(0) < 0 || idx(0) >= POOL_SIZE_(0) || idx(1) < 0 || idx(1) >= POOL_SIZE_(1) || idx(2) < 0 || idx(2) >= POOL_SIZE_(2))
    {
        RCLCPP_ERROR(this->get_logger(), "Ran out of pool, index=%d %d %d", idx(0), idx(1), idx(2));
        return false;
    }
    return true;
};

inline double PathPlanner::getHeu(GridNodePtr node1, GridNodePtr node2)
{
    return tie_breaker_ * getDiagHeu(node1, node2);
}