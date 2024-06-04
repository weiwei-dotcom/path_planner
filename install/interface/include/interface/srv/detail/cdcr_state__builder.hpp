// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interface:srv/CdcrState.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__SRV__DETAIL__CDCR_STATE__BUILDER_HPP_
#define INTERFACE__SRV__DETAIL__CDCR_STATE__BUILDER_HPP_

#include "interface/srv/detail/cdcr_state__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace interface
{

namespace srv
{

namespace builder
{

class Init_CdcrState_Request_base_pose_now
{
public:
  explicit Init_CdcrState_Request_base_pose_now(::interface::srv::CdcrState_Request & msg)
  : msg_(msg)
  {}
  ::interface::srv::CdcrState_Request base_pose_now(::interface::srv::CdcrState_Request::_base_pose_now_type arg)
  {
    msg_.base_pose_now = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interface::srv::CdcrState_Request msg_;
};

class Init_CdcrState_Request_theta_now
{
public:
  explicit Init_CdcrState_Request_theta_now(::interface::srv::CdcrState_Request & msg)
  : msg_(msg)
  {}
  Init_CdcrState_Request_base_pose_now theta_now(::interface::srv::CdcrState_Request::_theta_now_type arg)
  {
    msg_.theta_now = std::move(arg);
    return Init_CdcrState_Request_base_pose_now(msg_);
  }

private:
  ::interface::srv::CdcrState_Request msg_;
};

class Init_CdcrState_Request_alpha_now
{
public:
  Init_CdcrState_Request_alpha_now()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CdcrState_Request_theta_now alpha_now(::interface::srv::CdcrState_Request::_alpha_now_type arg)
  {
    msg_.alpha_now = std::move(arg);
    return Init_CdcrState_Request_theta_now(msg_);
  }

private:
  ::interface::srv::CdcrState_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interface::srv::CdcrState_Request>()
{
  return interface::srv::builder::Init_CdcrState_Request_alpha_now();
}

}  // namespace interface


namespace interface
{

namespace srv
{

namespace builder
{

class Init_CdcrState_Response_success
{
public:
  explicit Init_CdcrState_Response_success(::interface::srv::CdcrState_Response & msg)
  : msg_(msg)
  {}
  ::interface::srv::CdcrState_Response success(::interface::srv::CdcrState_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interface::srv::CdcrState_Response msg_;
};

class Init_CdcrState_Response_base_pose_tar
{
public:
  explicit Init_CdcrState_Response_base_pose_tar(::interface::srv::CdcrState_Response & msg)
  : msg_(msg)
  {}
  Init_CdcrState_Response_success base_pose_tar(::interface::srv::CdcrState_Response::_base_pose_tar_type arg)
  {
    msg_.base_pose_tar = std::move(arg);
    return Init_CdcrState_Response_success(msg_);
  }

private:
  ::interface::srv::CdcrState_Response msg_;
};

class Init_CdcrState_Response_theta_tar
{
public:
  explicit Init_CdcrState_Response_theta_tar(::interface::srv::CdcrState_Response & msg)
  : msg_(msg)
  {}
  Init_CdcrState_Response_base_pose_tar theta_tar(::interface::srv::CdcrState_Response::_theta_tar_type arg)
  {
    msg_.theta_tar = std::move(arg);
    return Init_CdcrState_Response_base_pose_tar(msg_);
  }

private:
  ::interface::srv::CdcrState_Response msg_;
};

class Init_CdcrState_Response_alpha_tar
{
public:
  Init_CdcrState_Response_alpha_tar()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CdcrState_Response_theta_tar alpha_tar(::interface::srv::CdcrState_Response::_alpha_tar_type arg)
  {
    msg_.alpha_tar = std::move(arg);
    return Init_CdcrState_Response_theta_tar(msg_);
  }

private:
  ::interface::srv::CdcrState_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interface::srv::CdcrState_Response>()
{
  return interface::srv::builder::Init_CdcrState_Response_alpha_tar();
}

}  // namespace interface

#endif  // INTERFACE__SRV__DETAIL__CDCR_STATE__BUILDER_HPP_
