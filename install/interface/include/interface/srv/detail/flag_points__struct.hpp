// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interface:srv/FlagPoints.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__SRV__DETAIL__FLAG_POINTS__STRUCT_HPP_
#define INTERFACE__SRV__DETAIL__FLAG_POINTS__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'points'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__interface__srv__FlagPoints_Request __attribute__((deprecated))
#else
# define DEPRECATED__interface__srv__FlagPoints_Request __declspec(deprecated)
#endif

namespace interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct FlagPoints_Request_
{
  using Type = FlagPoints_Request_<ContainerAllocator>;

  explicit FlagPoints_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit FlagPoints_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _points_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename ContainerAllocator::template rebind<geometry_msgs::msg::Point_<ContainerAllocator>>::other>;
  _points_type points;

  // setters for named parameter idiom
  Type & set__points(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename ContainerAllocator::template rebind<geometry_msgs::msg::Point_<ContainerAllocator>>::other> & _arg)
  {
    this->points = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interface::srv::FlagPoints_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const interface::srv::FlagPoints_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interface::srv::FlagPoints_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interface::srv::FlagPoints_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interface::srv::FlagPoints_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interface::srv::FlagPoints_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interface::srv::FlagPoints_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interface::srv::FlagPoints_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interface::srv::FlagPoints_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interface::srv::FlagPoints_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interface__srv__FlagPoints_Request
    std::shared_ptr<interface::srv::FlagPoints_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interface__srv__FlagPoints_Request
    std::shared_ptr<interface::srv::FlagPoints_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FlagPoints_Request_ & other) const
  {
    if (this->points != other.points) {
      return false;
    }
    return true;
  }
  bool operator!=(const FlagPoints_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FlagPoints_Request_

// alias to use template instance with default allocator
using FlagPoints_Request =
  interface::srv::FlagPoints_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace interface


#ifndef _WIN32
# define DEPRECATED__interface__srv__FlagPoints_Response __attribute__((deprecated))
#else
# define DEPRECATED__interface__srv__FlagPoints_Response __declspec(deprecated)
#endif

namespace interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct FlagPoints_Response_
{
  using Type = FlagPoints_Response_<ContainerAllocator>;

  explicit FlagPoints_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->flag = false;
    }
  }

  explicit FlagPoints_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->flag = false;
    }
  }

  // field types and members
  using _flag_type =
    bool;
  _flag_type flag;

  // setters for named parameter idiom
  Type & set__flag(
    const bool & _arg)
  {
    this->flag = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interface::srv::FlagPoints_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const interface::srv::FlagPoints_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interface::srv::FlagPoints_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interface::srv::FlagPoints_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interface::srv::FlagPoints_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interface::srv::FlagPoints_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interface::srv::FlagPoints_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interface::srv::FlagPoints_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interface::srv::FlagPoints_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interface::srv::FlagPoints_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interface__srv__FlagPoints_Response
    std::shared_ptr<interface::srv::FlagPoints_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interface__srv__FlagPoints_Response
    std::shared_ptr<interface::srv::FlagPoints_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FlagPoints_Response_ & other) const
  {
    if (this->flag != other.flag) {
      return false;
    }
    return true;
  }
  bool operator!=(const FlagPoints_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FlagPoints_Response_

// alias to use template instance with default allocator
using FlagPoints_Response =
  interface::srv::FlagPoints_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace interface

namespace interface
{

namespace srv
{

struct FlagPoints
{
  using Request = interface::srv::FlagPoints_Request;
  using Response = interface::srv::FlagPoints_Response;
};

}  // namespace srv

}  // namespace interface

#endif  // INTERFACE__SRV__DETAIL__FLAG_POINTS__STRUCT_HPP_
