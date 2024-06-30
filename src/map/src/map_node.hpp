#include "rclcpp/rclcpp.hpp"
#include "Eigen/Eigen"
#include "Eigen/Dense"
#include "sophus/se3.hpp"
#include "sophus/so3.hpp"
#include "visualization_msgs/msg/marker_array.hpp"
#include "pcl/point_cloud.h"
#include <opencv2/core/eigen.hpp>
#include "pcl_conversions/pcl_conversions.h"
#include "pcl/common/transforms.h"
#include <pcl/point_types.h>
#include <cmath>
#include <visualization_msgs/msg/marker.hpp>
#include <std_msgs/msg/float64.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <sensor_msgs/msg/point_cloud.hpp>
#include "cv_bridge/cv_bridge.h"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>

class MapNode:public rclcpp::Node
{
private:
    bool flag_build_map;
    double build_step;

    sensor_msgs::msg::PointCloud obs_pcl_msg;
    rclcpp::Publisher<sensor_msgs::msg::PointCloud>::SharedPtr obstacle_pub;
    rclcpp::TimerBase::SharedPtr pub_map_timer;

public:
    MapNode();
    void buildMap(const Eigen::Vector3d &flag_point1, const Eigen::Vector3d &flag_point2, const Eigen::Vector3d &flag_point3);
    void pubMapCallback();
};