// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interface:srv/PathPlan.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__SRV__DETAIL__PATH_PLAN__STRUCT_HPP_
#define INTERFACE__SRV__DETAIL__PATH_PLAN__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'start_position'
// Member 'end_position'
#include "geometry_msgs/msg/detail/point__struct.hpp"
// Member 'start_velocity'
// Member 'end_velocity'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__interface__srv__PathPlan_Request __attribute__((deprecated))
#else
# define DEPRECATED__interface__srv__PathPlan_Request __declspec(deprecated)
#endif

namespace interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct PathPlan_Request_
{
  using Type = PathPlan_Request_<ContainerAllocator>;

  explicit PathPlan_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : start_position(_init),
    start_velocity(_init),
    end_position(_init),
    end_velocity(_init)
  {
    (void)_init;
  }

  explicit PathPlan_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : start_position(_alloc, _init),
    start_velocity(_alloc, _init),
    end_position(_alloc, _init),
    end_velocity(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _start_position_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _start_position_type start_position;
  using _start_velocity_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _start_velocity_type start_velocity;
  using _end_position_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _end_position_type end_position;
  using _end_velocity_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _end_velocity_type end_velocity;

  // setters for named parameter idiom
  Type & set__start_position(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->start_position = _arg;
    return *this;
  }
  Type & set__start_velocity(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->start_velocity = _arg;
    return *this;
  }
  Type & set__end_position(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->end_position = _arg;
    return *this;
  }
  Type & set__end_velocity(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->end_velocity = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interface::srv::PathPlan_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const interface::srv::PathPlan_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interface::srv::PathPlan_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interface::srv::PathPlan_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interface::srv::PathPlan_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interface::srv::PathPlan_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interface::srv::PathPlan_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interface::srv::PathPlan_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interface::srv::PathPlan_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interface::srv::PathPlan_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interface__srv__PathPlan_Request
    std::shared_ptr<interface::srv::PathPlan_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interface__srv__PathPlan_Request
    std::shared_ptr<interface::srv::PathPlan_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PathPlan_Request_ & other) const
  {
    if (this->start_position != other.start_position) {
      return false;
    }
    if (this->start_velocity != other.start_velocity) {
      return false;
    }
    if (this->end_position != other.end_position) {
      return false;
    }
    if (this->end_velocity != other.end_velocity) {
      return false;
    }
    return true;
  }
  bool operator!=(const PathPlan_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PathPlan_Request_

// alias to use template instance with default allocator
using PathPlan_Request =
  interface::srv::PathPlan_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace interface


// Include directives for member types
// Member 'control_points'
// already included above
// #include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__interface__srv__PathPlan_Response __attribute__((deprecated))
#else
# define DEPRECATED__interface__srv__PathPlan_Response __declspec(deprecated)
#endif

namespace interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct PathPlan_Response_
{
  using Type = PathPlan_Response_<ContainerAllocator>;

  explicit PathPlan_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->degree = 0;
      this->knot_interval = 0.0;
      this->success = false;
    }
  }

  explicit PathPlan_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->degree = 0;
      this->knot_interval = 0.0;
      this->success = false;
    }
  }

  // field types and members
  using _control_points_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename ContainerAllocator::template rebind<geometry_msgs::msg::Point_<ContainerAllocator>>::other>;
  _control_points_type control_points;
  using _degree_type =
    int16_t;
  _degree_type degree;
  using _knot_interval_type =
    double;
  _knot_interval_type knot_interval;
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__control_points(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename ContainerAllocator::template rebind<geometry_msgs::msg::Point_<ContainerAllocator>>::other> & _arg)
  {
    this->control_points = _arg;
    return *this;
  }
  Type & set__degree(
    const int16_t & _arg)
  {
    this->degree = _arg;
    return *this;
  }
  Type & set__knot_interval(
    const double & _arg)
  {
    this->knot_interval = _arg;
    return *this;
  }
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interface::srv::PathPlan_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const interface::srv::PathPlan_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interface::srv::PathPlan_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interface::srv::PathPlan_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interface::srv::PathPlan_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interface::srv::PathPlan_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interface::srv::PathPlan_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interface::srv::PathPlan_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interface::srv::PathPlan_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interface::srv::PathPlan_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interface__srv__PathPlan_Response
    std::shared_ptr<interface::srv::PathPlan_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interface__srv__PathPlan_Response
    std::shared_ptr<interface::srv::PathPlan_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PathPlan_Response_ & other) const
  {
    if (this->control_points != other.control_points) {
      return false;
    }
    if (this->degree != other.degree) {
      return false;
    }
    if (this->knot_interval != other.knot_interval) {
      return false;
    }
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const PathPlan_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PathPlan_Response_

// alias to use template instance with default allocator
using PathPlan_Response =
  interface::srv::PathPlan_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace interface

namespace interface
{

namespace srv
{

struct PathPlan
{
  using Request = interface::srv::PathPlan_Request;
  using Response = interface::srv::PathPlan_Response;
};

}  // namespace srv

}  // namespace interface

#endif  // INTERFACE__SRV__DETAIL__PATH_PLAN__STRUCT_HPP_
