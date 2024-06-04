// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interface:srv/FlagPoints.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__SRV__DETAIL__FLAG_POINTS__BUILDER_HPP_
#define INTERFACE__SRV__DETAIL__FLAG_POINTS__BUILDER_HPP_

#include "interface/srv/detail/flag_points__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace interface
{

namespace srv
{

namespace builder
{

class Init_FlagPoints_Request_points
{
public:
  Init_FlagPoints_Request_points()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interface::srv::FlagPoints_Request points(::interface::srv::FlagPoints_Request::_points_type arg)
  {
    msg_.points = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interface::srv::FlagPoints_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interface::srv::FlagPoints_Request>()
{
  return interface::srv::builder::Init_FlagPoints_Request_points();
}

}  // namespace interface


namespace interface
{

namespace srv
{

namespace builder
{

class Init_FlagPoints_Response_flag
{
public:
  Init_FlagPoints_Response_flag()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interface::srv::FlagPoints_Response flag(::interface::srv::FlagPoints_Response::_flag_type arg)
  {
    msg_.flag = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interface::srv::FlagPoints_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interface::srv::FlagPoints_Response>()
{
  return interface::srv::builder::Init_FlagPoints_Response_flag();
}

}  // namespace interface

#endif  // INTERFACE__SRV__DETAIL__FLAG_POINTS__BUILDER_HPP_
