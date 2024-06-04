// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interface:srv/ConnectFlag.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__SRV__DETAIL__CONNECT_FLAG__TRAITS_HPP_
#define INTERFACE__SRV__DETAIL__CONNECT_FLAG__TRAITS_HPP_

#include "interface/srv/detail/connect_flag__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interface::srv::ConnectFlag_Request>()
{
  return "interface::srv::ConnectFlag_Request";
}

template<>
inline const char * name<interface::srv::ConnectFlag_Request>()
{
  return "interface/srv/ConnectFlag_Request";
}

template<>
struct has_fixed_size<interface::srv::ConnectFlag_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interface::srv::ConnectFlag_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interface::srv::ConnectFlag_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interface::srv::ConnectFlag_Response>()
{
  return "interface::srv::ConnectFlag_Response";
}

template<>
inline const char * name<interface::srv::ConnectFlag_Response>()
{
  return "interface/srv/ConnectFlag_Response";
}

template<>
struct has_fixed_size<interface::srv::ConnectFlag_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interface::srv::ConnectFlag_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interface::srv::ConnectFlag_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interface::srv::ConnectFlag>()
{
  return "interface::srv::ConnectFlag";
}

template<>
inline const char * name<interface::srv::ConnectFlag>()
{
  return "interface/srv/ConnectFlag";
}

template<>
struct has_fixed_size<interface::srv::ConnectFlag>
  : std::integral_constant<
    bool,
    has_fixed_size<interface::srv::ConnectFlag_Request>::value &&
    has_fixed_size<interface::srv::ConnectFlag_Response>::value
  >
{
};

template<>
struct has_bounded_size<interface::srv::ConnectFlag>
  : std::integral_constant<
    bool,
    has_bounded_size<interface::srv::ConnectFlag_Request>::value &&
    has_bounded_size<interface::srv::ConnectFlag_Response>::value
  >
{
};

template<>
struct is_service<interface::srv::ConnectFlag>
  : std::true_type
{
};

template<>
struct is_service_request<interface::srv::ConnectFlag_Request>
  : std::true_type
{
};

template<>
struct is_service_response<interface::srv::ConnectFlag_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // INTERFACE__SRV__DETAIL__CONNECT_FLAG__TRAITS_HPP_
