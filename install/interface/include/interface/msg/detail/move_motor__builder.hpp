// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interface:msg/MoveMotor.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__MSG__DETAIL__MOVE_MOTOR__BUILDER_HPP_
#define INTERFACE__MSG__DETAIL__MOVE_MOTOR__BUILDER_HPP_

#include "interface/msg/detail/move_motor__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace interface
{

namespace msg
{

namespace builder
{

class Init_MoveMotor_kd
{
public:
  explicit Init_MoveMotor_kd(::interface::msg::MoveMotor & msg)
  : msg_(msg)
  {}
  ::interface::msg::MoveMotor kd(::interface::msg::MoveMotor::_kd_type arg)
  {
    msg_.kd = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interface::msg::MoveMotor msg_;
};

class Init_MoveMotor_kp
{
public:
  explicit Init_MoveMotor_kp(::interface::msg::MoveMotor & msg)
  : msg_(msg)
  {}
  Init_MoveMotor_kd kp(::interface::msg::MoveMotor::_kp_type arg)
  {
    msg_.kp = std::move(arg);
    return Init_MoveMotor_kd(msg_);
  }

private:
  ::interface::msg::MoveMotor msg_;
};

class Init_MoveMotor_tor
{
public:
  explicit Init_MoveMotor_tor(::interface::msg::MoveMotor & msg)
  : msg_(msg)
  {}
  Init_MoveMotor_kp tor(::interface::msg::MoveMotor::_tor_type arg)
  {
    msg_.tor = std::move(arg);
    return Init_MoveMotor_kp(msg_);
  }

private:
  ::interface::msg::MoveMotor msg_;
};

class Init_MoveMotor_vel
{
public:
  explicit Init_MoveMotor_vel(::interface::msg::MoveMotor & msg)
  : msg_(msg)
  {}
  Init_MoveMotor_tor vel(::interface::msg::MoveMotor::_vel_type arg)
  {
    msg_.vel = std::move(arg);
    return Init_MoveMotor_tor(msg_);
  }

private:
  ::interface::msg::MoveMotor msg_;
};

class Init_MoveMotor_pos
{
public:
  explicit Init_MoveMotor_pos(::interface::msg::MoveMotor & msg)
  : msg_(msg)
  {}
  Init_MoveMotor_vel pos(::interface::msg::MoveMotor::_pos_type arg)
  {
    msg_.pos = std::move(arg);
    return Init_MoveMotor_vel(msg_);
  }

private:
  ::interface::msg::MoveMotor msg_;
};

class Init_MoveMotor_motor_id
{
public:
  Init_MoveMotor_motor_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveMotor_pos motor_id(::interface::msg::MoveMotor::_motor_id_type arg)
  {
    msg_.motor_id = std::move(arg);
    return Init_MoveMotor_pos(msg_);
  }

private:
  ::interface::msg::MoveMotor msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interface::msg::MoveMotor>()
{
  return interface::msg::builder::Init_MoveMotor_motor_id();
}

}  // namespace interface

#endif  // INTERFACE__MSG__DETAIL__MOVE_MOTOR__BUILDER_HPP_
