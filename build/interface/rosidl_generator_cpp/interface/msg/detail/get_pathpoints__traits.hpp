// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interface:msg/GetPathpoints.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__MSG__DETAIL__GET_PATHPOINTS__TRAITS_HPP_
#define INTERFACE__MSG__DETAIL__GET_PATHPOINTS__TRAITS_HPP_

#include "interface/msg/detail/get_pathpoints__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interface::msg::GetPathpoints>()
{
  return "interface::msg::GetPathpoints";
}

template<>
inline const char * name<interface::msg::GetPathpoints>()
{
  return "interface/msg/GetPathpoints";
}

template<>
struct has_fixed_size<interface::msg::GetPathpoints>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<interface::msg::GetPathpoints>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<interface::msg::GetPathpoints>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // INTERFACE__MSG__DETAIL__GET_PATHPOINTS__TRAITS_HPP_
