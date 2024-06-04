// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interface:msg/GetPathpoints.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__MSG__DETAIL__GET_PATHPOINTS__BUILDER_HPP_
#define INTERFACE__MSG__DETAIL__GET_PATHPOINTS__BUILDER_HPP_

#include "interface/msg/detail/get_pathpoints__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace interface
{

namespace msg
{

namespace builder
{

class Init_GetPathpoints_path_points
{
public:
  Init_GetPathpoints_path_points()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interface::msg::GetPathpoints path_points(::interface::msg::GetPathpoints::_path_points_type arg)
  {
    msg_.path_points = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interface::msg::GetPathpoints msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interface::msg::GetPathpoints>()
{
  return interface::msg::builder::Init_GetPathpoints_path_points();
}

}  // namespace interface

#endif  // INTERFACE__MSG__DETAIL__GET_PATHPOINTS__BUILDER_HPP_
