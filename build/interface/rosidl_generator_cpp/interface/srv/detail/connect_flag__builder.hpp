// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interface:srv/ConnectFlag.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__SRV__DETAIL__CONNECT_FLAG__BUILDER_HPP_
#define INTERFACE__SRV__DETAIL__CONNECT_FLAG__BUILDER_HPP_

#include "interface/srv/detail/connect_flag__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace interface
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interface::srv::ConnectFlag_Request>()
{
  return ::interface::srv::ConnectFlag_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace interface


namespace interface
{

namespace srv
{

namespace builder
{

class Init_ConnectFlag_Response_flag_connected
{
public:
  Init_ConnectFlag_Response_flag_connected()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interface::srv::ConnectFlag_Response flag_connected(::interface::srv::ConnectFlag_Response::_flag_connected_type arg)
  {
    msg_.flag_connected = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interface::srv::ConnectFlag_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interface::srv::ConnectFlag_Response>()
{
  return interface::srv::builder::Init_ConnectFlag_Response_flag_connected();
}

}  // namespace interface

#endif  // INTERFACE__SRV__DETAIL__CONNECT_FLAG__BUILDER_HPP_
