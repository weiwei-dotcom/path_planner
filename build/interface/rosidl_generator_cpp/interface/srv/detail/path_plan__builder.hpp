// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interface:srv/PathPlan.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__SRV__DETAIL__PATH_PLAN__BUILDER_HPP_
#define INTERFACE__SRV__DETAIL__PATH_PLAN__BUILDER_HPP_

#include "interface/srv/detail/path_plan__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace interface
{

namespace srv
{

namespace builder
{

class Init_PathPlan_Request_end_velocity
{
public:
  explicit Init_PathPlan_Request_end_velocity(::interface::srv::PathPlan_Request & msg)
  : msg_(msg)
  {}
  ::interface::srv::PathPlan_Request end_velocity(::interface::srv::PathPlan_Request::_end_velocity_type arg)
  {
    msg_.end_velocity = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interface::srv::PathPlan_Request msg_;
};

class Init_PathPlan_Request_end_position
{
public:
  explicit Init_PathPlan_Request_end_position(::interface::srv::PathPlan_Request & msg)
  : msg_(msg)
  {}
  Init_PathPlan_Request_end_velocity end_position(::interface::srv::PathPlan_Request::_end_position_type arg)
  {
    msg_.end_position = std::move(arg);
    return Init_PathPlan_Request_end_velocity(msg_);
  }

private:
  ::interface::srv::PathPlan_Request msg_;
};

class Init_PathPlan_Request_start_velocity
{
public:
  explicit Init_PathPlan_Request_start_velocity(::interface::srv::PathPlan_Request & msg)
  : msg_(msg)
  {}
  Init_PathPlan_Request_end_position start_velocity(::interface::srv::PathPlan_Request::_start_velocity_type arg)
  {
    msg_.start_velocity = std::move(arg);
    return Init_PathPlan_Request_end_position(msg_);
  }

private:
  ::interface::srv::PathPlan_Request msg_;
};

class Init_PathPlan_Request_start_position
{
public:
  Init_PathPlan_Request_start_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PathPlan_Request_start_velocity start_position(::interface::srv::PathPlan_Request::_start_position_type arg)
  {
    msg_.start_position = std::move(arg);
    return Init_PathPlan_Request_start_velocity(msg_);
  }

private:
  ::interface::srv::PathPlan_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interface::srv::PathPlan_Request>()
{
  return interface::srv::builder::Init_PathPlan_Request_start_position();
}

}  // namespace interface


namespace interface
{

namespace srv
{

namespace builder
{

class Init_PathPlan_Response_success
{
public:
  explicit Init_PathPlan_Response_success(::interface::srv::PathPlan_Response & msg)
  : msg_(msg)
  {}
  ::interface::srv::PathPlan_Response success(::interface::srv::PathPlan_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interface::srv::PathPlan_Response msg_;
};

class Init_PathPlan_Response_knot_interval
{
public:
  explicit Init_PathPlan_Response_knot_interval(::interface::srv::PathPlan_Response & msg)
  : msg_(msg)
  {}
  Init_PathPlan_Response_success knot_interval(::interface::srv::PathPlan_Response::_knot_interval_type arg)
  {
    msg_.knot_interval = std::move(arg);
    return Init_PathPlan_Response_success(msg_);
  }

private:
  ::interface::srv::PathPlan_Response msg_;
};

class Init_PathPlan_Response_degree
{
public:
  explicit Init_PathPlan_Response_degree(::interface::srv::PathPlan_Response & msg)
  : msg_(msg)
  {}
  Init_PathPlan_Response_knot_interval degree(::interface::srv::PathPlan_Response::_degree_type arg)
  {
    msg_.degree = std::move(arg);
    return Init_PathPlan_Response_knot_interval(msg_);
  }

private:
  ::interface::srv::PathPlan_Response msg_;
};

class Init_PathPlan_Response_control_points
{
public:
  Init_PathPlan_Response_control_points()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PathPlan_Response_degree control_points(::interface::srv::PathPlan_Response::_control_points_type arg)
  {
    msg_.control_points = std::move(arg);
    return Init_PathPlan_Response_degree(msg_);
  }

private:
  ::interface::srv::PathPlan_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interface::srv::PathPlan_Response>()
{
  return interface::srv::builder::Init_PathPlan_Response_control_points();
}

}  // namespace interface

#endif  // INTERFACE__SRV__DETAIL__PATH_PLAN__BUILDER_HPP_
