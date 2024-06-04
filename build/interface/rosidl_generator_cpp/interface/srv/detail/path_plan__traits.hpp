// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interface:srv/PathPlan.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__SRV__DETAIL__PATH_PLAN__TRAITS_HPP_
#define INTERFACE__SRV__DETAIL__PATH_PLAN__TRAITS_HPP_

#include "interface/srv/detail/path_plan__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'start_position'
// Member 'end_position'
#include "geometry_msgs/msg/detail/point__traits.hpp"
// Member 'start_velocity'
// Member 'end_velocity'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interface::srv::PathPlan_Request>()
{
  return "interface::srv::PathPlan_Request";
}

template<>
inline const char * name<interface::srv::PathPlan_Request>()
{
  return "interface/srv/PathPlan_Request";
}

template<>
struct has_fixed_size<interface::srv::PathPlan_Request>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value && has_fixed_size<geometry_msgs::msg::Vector3>::value> {};

template<>
struct has_bounded_size<interface::srv::PathPlan_Request>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value && has_bounded_size<geometry_msgs::msg::Vector3>::value> {};

template<>
struct is_message<interface::srv::PathPlan_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interface::srv::PathPlan_Response>()
{
  return "interface::srv::PathPlan_Response";
}

template<>
inline const char * name<interface::srv::PathPlan_Response>()
{
  return "interface/srv/PathPlan_Response";
}

template<>
struct has_fixed_size<interface::srv::PathPlan_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<interface::srv::PathPlan_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<interface::srv::PathPlan_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interface::srv::PathPlan>()
{
  return "interface::srv::PathPlan";
}

template<>
inline const char * name<interface::srv::PathPlan>()
{
  return "interface/srv/PathPlan";
}

template<>
struct has_fixed_size<interface::srv::PathPlan>
  : std::integral_constant<
    bool,
    has_fixed_size<interface::srv::PathPlan_Request>::value &&
    has_fixed_size<interface::srv::PathPlan_Response>::value
  >
{
};

template<>
struct has_bounded_size<interface::srv::PathPlan>
  : std::integral_constant<
    bool,
    has_bounded_size<interface::srv::PathPlan_Request>::value &&
    has_bounded_size<interface::srv::PathPlan_Response>::value
  >
{
};

template<>
struct is_service<interface::srv::PathPlan>
  : std::true_type
{
};

template<>
struct is_service_request<interface::srv::PathPlan_Request>
  : std::true_type
{
};

template<>
struct is_service_response<interface::srv::PathPlan_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // INTERFACE__SRV__DETAIL__PATH_PLAN__TRAITS_HPP_
