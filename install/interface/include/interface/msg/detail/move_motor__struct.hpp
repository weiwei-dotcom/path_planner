// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interface:msg/MoveMotor.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__MSG__DETAIL__MOVE_MOTOR__STRUCT_HPP_
#define INTERFACE__MSG__DETAIL__MOVE_MOTOR__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__interface__msg__MoveMotor __attribute__((deprecated))
#else
# define DEPRECATED__interface__msg__MoveMotor __declspec(deprecated)
#endif

namespace interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MoveMotor_
{
  using Type = MoveMotor_<ContainerAllocator>;

  explicit MoveMotor_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->motor_id = 0ll;
      this->pos = 0ll;
      this->vel = 0ll;
      this->tor = 0ll;
      this->kp = 0ll;
      this->kd = 0ll;
    }
  }

  explicit MoveMotor_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->motor_id = 0ll;
      this->pos = 0ll;
      this->vel = 0ll;
      this->tor = 0ll;
      this->kp = 0ll;
      this->kd = 0ll;
    }
  }

  // field types and members
  using _motor_id_type =
    int64_t;
  _motor_id_type motor_id;
  using _pos_type =
    int64_t;
  _pos_type pos;
  using _vel_type =
    int64_t;
  _vel_type vel;
  using _tor_type =
    int64_t;
  _tor_type tor;
  using _kp_type =
    int64_t;
  _kp_type kp;
  using _kd_type =
    int64_t;
  _kd_type kd;

  // setters for named parameter idiom
  Type & set__motor_id(
    const int64_t & _arg)
  {
    this->motor_id = _arg;
    return *this;
  }
  Type & set__pos(
    const int64_t & _arg)
  {
    this->pos = _arg;
    return *this;
  }
  Type & set__vel(
    const int64_t & _arg)
  {
    this->vel = _arg;
    return *this;
  }
  Type & set__tor(
    const int64_t & _arg)
  {
    this->tor = _arg;
    return *this;
  }
  Type & set__kp(
    const int64_t & _arg)
  {
    this->kp = _arg;
    return *this;
  }
  Type & set__kd(
    const int64_t & _arg)
  {
    this->kd = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interface::msg::MoveMotor_<ContainerAllocator> *;
  using ConstRawPtr =
    const interface::msg::MoveMotor_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interface::msg::MoveMotor_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interface::msg::MoveMotor_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interface::msg::MoveMotor_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interface::msg::MoveMotor_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interface::msg::MoveMotor_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interface::msg::MoveMotor_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interface::msg::MoveMotor_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interface::msg::MoveMotor_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interface__msg__MoveMotor
    std::shared_ptr<interface::msg::MoveMotor_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interface__msg__MoveMotor
    std::shared_ptr<interface::msg::MoveMotor_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveMotor_ & other) const
  {
    if (this->motor_id != other.motor_id) {
      return false;
    }
    if (this->pos != other.pos) {
      return false;
    }
    if (this->vel != other.vel) {
      return false;
    }
    if (this->tor != other.tor) {
      return false;
    }
    if (this->kp != other.kp) {
      return false;
    }
    if (this->kd != other.kd) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoveMotor_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveMotor_

// alias to use template instance with default allocator
using MoveMotor =
  interface::msg::MoveMotor_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interface

#endif  // INTERFACE__MSG__DETAIL__MOVE_MOTOR__STRUCT_HPP_
