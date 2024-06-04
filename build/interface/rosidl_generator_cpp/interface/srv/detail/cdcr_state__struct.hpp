// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interface:srv/CdcrState.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__SRV__DETAIL__CDCR_STATE__STRUCT_HPP_
#define INTERFACE__SRV__DETAIL__CDCR_STATE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'base_pose_now'
#include "geometry_msgs/msg/detail/pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__interface__srv__CdcrState_Request __attribute__((deprecated))
#else
# define DEPRECATED__interface__srv__CdcrState_Request __declspec(deprecated)
#endif

namespace interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CdcrState_Request_
{
  using Type = CdcrState_Request_<ContainerAllocator>;

  explicit CdcrState_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : base_pose_now(_init)
  {
    (void)_init;
  }

  explicit CdcrState_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : base_pose_now(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _alpha_now_type =
    std::vector<double, typename ContainerAllocator::template rebind<double>::other>;
  _alpha_now_type alpha_now;
  using _theta_now_type =
    std::vector<double, typename ContainerAllocator::template rebind<double>::other>;
  _theta_now_type theta_now;
  using _base_pose_now_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _base_pose_now_type base_pose_now;

  // setters for named parameter idiom
  Type & set__alpha_now(
    const std::vector<double, typename ContainerAllocator::template rebind<double>::other> & _arg)
  {
    this->alpha_now = _arg;
    return *this;
  }
  Type & set__theta_now(
    const std::vector<double, typename ContainerAllocator::template rebind<double>::other> & _arg)
  {
    this->theta_now = _arg;
    return *this;
  }
  Type & set__base_pose_now(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->base_pose_now = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interface::srv::CdcrState_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const interface::srv::CdcrState_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interface::srv::CdcrState_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interface::srv::CdcrState_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interface::srv::CdcrState_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interface::srv::CdcrState_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interface::srv::CdcrState_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interface::srv::CdcrState_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interface::srv::CdcrState_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interface::srv::CdcrState_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interface__srv__CdcrState_Request
    std::shared_ptr<interface::srv::CdcrState_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interface__srv__CdcrState_Request
    std::shared_ptr<interface::srv::CdcrState_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CdcrState_Request_ & other) const
  {
    if (this->alpha_now != other.alpha_now) {
      return false;
    }
    if (this->theta_now != other.theta_now) {
      return false;
    }
    if (this->base_pose_now != other.base_pose_now) {
      return false;
    }
    return true;
  }
  bool operator!=(const CdcrState_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CdcrState_Request_

// alias to use template instance with default allocator
using CdcrState_Request =
  interface::srv::CdcrState_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace interface


// Include directives for member types
// Member 'base_pose_tar'
// already included above
// #include "geometry_msgs/msg/detail/pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__interface__srv__CdcrState_Response __attribute__((deprecated))
#else
# define DEPRECATED__interface__srv__CdcrState_Response __declspec(deprecated)
#endif

namespace interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CdcrState_Response_
{
  using Type = CdcrState_Response_<ContainerAllocator>;

  explicit CdcrState_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : base_pose_tar(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit CdcrState_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : base_pose_tar(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _alpha_tar_type =
    std::vector<double, typename ContainerAllocator::template rebind<double>::other>;
  _alpha_tar_type alpha_tar;
  using _theta_tar_type =
    std::vector<double, typename ContainerAllocator::template rebind<double>::other>;
  _theta_tar_type theta_tar;
  using _base_pose_tar_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _base_pose_tar_type base_pose_tar;
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__alpha_tar(
    const std::vector<double, typename ContainerAllocator::template rebind<double>::other> & _arg)
  {
    this->alpha_tar = _arg;
    return *this;
  }
  Type & set__theta_tar(
    const std::vector<double, typename ContainerAllocator::template rebind<double>::other> & _arg)
  {
    this->theta_tar = _arg;
    return *this;
  }
  Type & set__base_pose_tar(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->base_pose_tar = _arg;
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
    interface::srv::CdcrState_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const interface::srv::CdcrState_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interface::srv::CdcrState_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interface::srv::CdcrState_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interface::srv::CdcrState_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interface::srv::CdcrState_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interface::srv::CdcrState_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interface::srv::CdcrState_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interface::srv::CdcrState_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interface::srv::CdcrState_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interface__srv__CdcrState_Response
    std::shared_ptr<interface::srv::CdcrState_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interface__srv__CdcrState_Response
    std::shared_ptr<interface::srv::CdcrState_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CdcrState_Response_ & other) const
  {
    if (this->alpha_tar != other.alpha_tar) {
      return false;
    }
    if (this->theta_tar != other.theta_tar) {
      return false;
    }
    if (this->base_pose_tar != other.base_pose_tar) {
      return false;
    }
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const CdcrState_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CdcrState_Response_

// alias to use template instance with default allocator
using CdcrState_Response =
  interface::srv::CdcrState_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace interface

namespace interface
{

namespace srv
{

struct CdcrState
{
  using Request = interface::srv::CdcrState_Request;
  using Response = interface::srv::CdcrState_Response;
};

}  // namespace srv

}  // namespace interface

#endif  // INTERFACE__SRV__DETAIL__CDCR_STATE__STRUCT_HPP_
