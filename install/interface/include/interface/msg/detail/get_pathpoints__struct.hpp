// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interface:msg/GetPathpoints.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__MSG__DETAIL__GET_PATHPOINTS__STRUCT_HPP_
#define INTERFACE__MSG__DETAIL__GET_PATHPOINTS__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'path_points'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__interface__msg__GetPathpoints __attribute__((deprecated))
#else
# define DEPRECATED__interface__msg__GetPathpoints __declspec(deprecated)
#endif

namespace interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GetPathpoints_
{
  using Type = GetPathpoints_<ContainerAllocator>;

  explicit GetPathpoints_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit GetPathpoints_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _path_points_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename ContainerAllocator::template rebind<geometry_msgs::msg::Point_<ContainerAllocator>>::other>;
  _path_points_type path_points;

  // setters for named parameter idiom
  Type & set__path_points(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename ContainerAllocator::template rebind<geometry_msgs::msg::Point_<ContainerAllocator>>::other> & _arg)
  {
    this->path_points = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interface::msg::GetPathpoints_<ContainerAllocator> *;
  using ConstRawPtr =
    const interface::msg::GetPathpoints_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interface::msg::GetPathpoints_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interface::msg::GetPathpoints_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interface::msg::GetPathpoints_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interface::msg::GetPathpoints_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interface::msg::GetPathpoints_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interface::msg::GetPathpoints_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interface::msg::GetPathpoints_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interface::msg::GetPathpoints_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interface__msg__GetPathpoints
    std::shared_ptr<interface::msg::GetPathpoints_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interface__msg__GetPathpoints
    std::shared_ptr<interface::msg::GetPathpoints_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetPathpoints_ & other) const
  {
    if (this->path_points != other.path_points) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetPathpoints_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetPathpoints_

// alias to use template instance with default allocator
using GetPathpoints =
  interface::msg::GetPathpoints_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interface

#endif  // INTERFACE__MSG__DETAIL__GET_PATHPOINTS__STRUCT_HPP_
