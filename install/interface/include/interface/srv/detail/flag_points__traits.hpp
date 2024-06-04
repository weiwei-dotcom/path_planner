// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interface:srv/FlagPoints.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__SRV__DETAIL__FLAG_POINTS__TRAITS_HPP_
#define INTERFACE__SRV__DETAIL__FLAG_POINTS__TRAITS_HPP_

#include "interface/srv/detail/flag_points__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interface::srv::FlagPoints_Request>()
{
  return "interface::srv::FlagPoints_Request";
}

template<>
inline const char * name<interface::srv::FlagPoints_Request>()
{
  return "interface/srv/FlagPoints_Request";
}

template<>
struct has_fixed_size<interface::srv::FlagPoints_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<interface::srv::FlagPoints_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<interface::srv::FlagPoints_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interface::srv::FlagPoints_Response>()
{
  return "interface::srv::FlagPoints_Response";
}

template<>
inline const char * name<interface::srv::FlagPoints_Response>()
{
  return "interface/srv/FlagPoints_Response";
}

template<>
struct has_fixed_size<interface::srv::FlagPoints_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interface::srv::FlagPoints_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interface::srv::FlagPoints_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interface::srv::FlagPoints>()
{
  return "interface::srv::FlagPoints";
}

template<>
inline const char * name<interface::srv::FlagPoints>()
{
  return "interface/srv/FlagPoints";
}

template<>
struct has_fixed_size<interface::srv::FlagPoints>
  : std::integral_constant<
    bool,
    has_fixed_size<interface::srv::FlagPoints_Request>::value &&
    has_fixed_size<interface::srv::FlagPoints_Response>::value
  >
{
};

template<>
struct has_bounded_size<interface::srv::FlagPoints>
  : std::integral_constant<
    bool,
    has_bounded_size<interface::srv::FlagPoints_Request>::value &&
    has_bounded_size<interface::srv::FlagPoints_Response>::value
  >
{
};

template<>
struct is_service<interface::srv::FlagPoints>
  : std::true_type
{
};

template<>
struct is_service_request<interface::srv::FlagPoints_Request>
  : std::true_type
{
};

template<>
struct is_service_response<interface::srv::FlagPoints_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // INTERFACE__SRV__DETAIL__FLAG_POINTS__TRAITS_HPP_
