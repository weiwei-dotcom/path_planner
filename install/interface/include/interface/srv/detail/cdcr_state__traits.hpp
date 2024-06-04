// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interface:srv/CdcrState.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__SRV__DETAIL__CDCR_STATE__TRAITS_HPP_
#define INTERFACE__SRV__DETAIL__CDCR_STATE__TRAITS_HPP_

#include "interface/srv/detail/cdcr_state__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'base_pose_now'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interface::srv::CdcrState_Request>()
{
  return "interface::srv::CdcrState_Request";
}

template<>
inline const char * name<interface::srv::CdcrState_Request>()
{
  return "interface/srv/CdcrState_Request";
}

template<>
struct has_fixed_size<interface::srv::CdcrState_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<interface::srv::CdcrState_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<interface::srv::CdcrState_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'base_pose_tar'
// already included above
// #include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interface::srv::CdcrState_Response>()
{
  return "interface::srv::CdcrState_Response";
}

template<>
inline const char * name<interface::srv::CdcrState_Response>()
{
  return "interface/srv/CdcrState_Response";
}

template<>
struct has_fixed_size<interface::srv::CdcrState_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<interface::srv::CdcrState_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<interface::srv::CdcrState_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interface::srv::CdcrState>()
{
  return "interface::srv::CdcrState";
}

template<>
inline const char * name<interface::srv::CdcrState>()
{
  return "interface/srv/CdcrState";
}

template<>
struct has_fixed_size<interface::srv::CdcrState>
  : std::integral_constant<
    bool,
    has_fixed_size<interface::srv::CdcrState_Request>::value &&
    has_fixed_size<interface::srv::CdcrState_Response>::value
  >
{
};

template<>
struct has_bounded_size<interface::srv::CdcrState>
  : std::integral_constant<
    bool,
    has_bounded_size<interface::srv::CdcrState_Request>::value &&
    has_bounded_size<interface::srv::CdcrState_Response>::value
  >
{
};

template<>
struct is_service<interface::srv::CdcrState>
  : std::true_type
{
};

template<>
struct is_service_request<interface::srv::CdcrState_Request>
  : std::true_type
{
};

template<>
struct is_service_response<interface::srv::CdcrState_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // INTERFACE__SRV__DETAIL__CDCR_STATE__TRAITS_HPP_
