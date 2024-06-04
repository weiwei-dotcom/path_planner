// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interface:msg/MoveMotor.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__MSG__DETAIL__MOVE_MOTOR__TRAITS_HPP_
#define INTERFACE__MSG__DETAIL__MOVE_MOTOR__TRAITS_HPP_

#include "interface/msg/detail/move_motor__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interface::msg::MoveMotor>()
{
  return "interface::msg::MoveMotor";
}

template<>
inline const char * name<interface::msg::MoveMotor>()
{
  return "interface/msg/MoveMotor";
}

template<>
struct has_fixed_size<interface::msg::MoveMotor>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interface::msg::MoveMotor>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interface::msg::MoveMotor>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // INTERFACE__MSG__DETAIL__MOVE_MOTOR__TRAITS_HPP_
