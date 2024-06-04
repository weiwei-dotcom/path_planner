# generated from rosidl_generator_py/resource/_idl.py.em
# with input from interface:srv/CdcrState.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'alpha_now'
# Member 'theta_now'
import array  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CdcrState_Request(type):
    """Metaclass of message 'CdcrState_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('interface')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'interface.srv.CdcrState_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__cdcr_state__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__cdcr_state__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__cdcr_state__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__cdcr_state__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__cdcr_state__request

            from geometry_msgs.msg import Pose
            if Pose.__class__._TYPE_SUPPORT is None:
                Pose.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class CdcrState_Request(metaclass=Metaclass_CdcrState_Request):
    """Message class 'CdcrState_Request'."""

    __slots__ = [
        '_alpha_now',
        '_theta_now',
        '_base_pose_now',
    ]

    _fields_and_field_types = {
        'alpha_now': 'sequence<double>',
        'theta_now': 'sequence<double>',
        'base_pose_now': 'geometry_msgs/Pose',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.alpha_now = array.array('d', kwargs.get('alpha_now', []))
        self.theta_now = array.array('d', kwargs.get('theta_now', []))
        from geometry_msgs.msg import Pose
        self.base_pose_now = kwargs.get('base_pose_now', Pose())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.alpha_now != other.alpha_now:
            return False
        if self.theta_now != other.theta_now:
            return False
        if self.base_pose_now != other.base_pose_now:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def alpha_now(self):
        """Message field 'alpha_now'."""
        return self._alpha_now

    @alpha_now.setter
    def alpha_now(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'alpha_now' array.array() must have the type code of 'd'"
            self._alpha_now = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'alpha_now' field must be a set or sequence and each value of type 'float'"
        self._alpha_now = array.array('d', value)

    @property
    def theta_now(self):
        """Message field 'theta_now'."""
        return self._theta_now

    @theta_now.setter
    def theta_now(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'theta_now' array.array() must have the type code of 'd'"
            self._theta_now = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'theta_now' field must be a set or sequence and each value of type 'float'"
        self._theta_now = array.array('d', value)

    @property
    def base_pose_now(self):
        """Message field 'base_pose_now'."""
        return self._base_pose_now

    @base_pose_now.setter
    def base_pose_now(self, value):
        if __debug__:
            from geometry_msgs.msg import Pose
            assert \
                isinstance(value, Pose), \
                "The 'base_pose_now' field must be a sub message of type 'Pose'"
        self._base_pose_now = value


# Import statements for member types

# Member 'alpha_tar'
# Member 'theta_tar'
# already imported above
# import array

# already imported above
# import rosidl_parser.definition


class Metaclass_CdcrState_Response(type):
    """Metaclass of message 'CdcrState_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('interface')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'interface.srv.CdcrState_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__cdcr_state__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__cdcr_state__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__cdcr_state__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__cdcr_state__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__cdcr_state__response

            from geometry_msgs.msg import Pose
            if Pose.__class__._TYPE_SUPPORT is None:
                Pose.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class CdcrState_Response(metaclass=Metaclass_CdcrState_Response):
    """Message class 'CdcrState_Response'."""

    __slots__ = [
        '_alpha_tar',
        '_theta_tar',
        '_base_pose_tar',
        '_success',
    ]

    _fields_and_field_types = {
        'alpha_tar': 'sequence<double>',
        'theta_tar': 'sequence<double>',
        'base_pose_tar': 'geometry_msgs/Pose',
        'success': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.alpha_tar = array.array('d', kwargs.get('alpha_tar', []))
        self.theta_tar = array.array('d', kwargs.get('theta_tar', []))
        from geometry_msgs.msg import Pose
        self.base_pose_tar = kwargs.get('base_pose_tar', Pose())
        self.success = kwargs.get('success', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.alpha_tar != other.alpha_tar:
            return False
        if self.theta_tar != other.theta_tar:
            return False
        if self.base_pose_tar != other.base_pose_tar:
            return False
        if self.success != other.success:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def alpha_tar(self):
        """Message field 'alpha_tar'."""
        return self._alpha_tar

    @alpha_tar.setter
    def alpha_tar(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'alpha_tar' array.array() must have the type code of 'd'"
            self._alpha_tar = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'alpha_tar' field must be a set or sequence and each value of type 'float'"
        self._alpha_tar = array.array('d', value)

    @property
    def theta_tar(self):
        """Message field 'theta_tar'."""
        return self._theta_tar

    @theta_tar.setter
    def theta_tar(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'theta_tar' array.array() must have the type code of 'd'"
            self._theta_tar = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'theta_tar' field must be a set or sequence and each value of type 'float'"
        self._theta_tar = array.array('d', value)

    @property
    def base_pose_tar(self):
        """Message field 'base_pose_tar'."""
        return self._base_pose_tar

    @base_pose_tar.setter
    def base_pose_tar(self, value):
        if __debug__:
            from geometry_msgs.msg import Pose
            assert \
                isinstance(value, Pose), \
                "The 'base_pose_tar' field must be a sub message of type 'Pose'"
        self._base_pose_tar = value

    @property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value


class Metaclass_CdcrState(type):
    """Metaclass of service 'CdcrState'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('interface')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'interface.srv.CdcrState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__cdcr_state

            from interface.srv import _cdcr_state
            if _cdcr_state.Metaclass_CdcrState_Request._TYPE_SUPPORT is None:
                _cdcr_state.Metaclass_CdcrState_Request.__import_type_support__()
            if _cdcr_state.Metaclass_CdcrState_Response._TYPE_SUPPORT is None:
                _cdcr_state.Metaclass_CdcrState_Response.__import_type_support__()


class CdcrState(metaclass=Metaclass_CdcrState):
    from interface.srv._cdcr_state import CdcrState_Request as Request
    from interface.srv._cdcr_state import CdcrState_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
