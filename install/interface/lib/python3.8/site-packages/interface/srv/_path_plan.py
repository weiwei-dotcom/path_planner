# generated from rosidl_generator_py/resource/_idl.py.em
# with input from interface:srv/PathPlan.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_PathPlan_Request(type):
    """Metaclass of message 'PathPlan_Request'."""

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
                'interface.srv.PathPlan_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__path_plan__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__path_plan__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__path_plan__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__path_plan__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__path_plan__request

            from geometry_msgs.msg import Point
            if Point.__class__._TYPE_SUPPORT is None:
                Point.__class__.__import_type_support__()

            from geometry_msgs.msg import Vector3
            if Vector3.__class__._TYPE_SUPPORT is None:
                Vector3.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PathPlan_Request(metaclass=Metaclass_PathPlan_Request):
    """Message class 'PathPlan_Request'."""

    __slots__ = [
        '_start_position',
        '_start_velocity',
        '_end_position',
        '_end_velocity',
    ]

    _fields_and_field_types = {
        'start_position': 'geometry_msgs/Point',
        'start_velocity': 'geometry_msgs/Vector3',
        'end_position': 'geometry_msgs/Point',
        'end_velocity': 'geometry_msgs/Vector3',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from geometry_msgs.msg import Point
        self.start_position = kwargs.get('start_position', Point())
        from geometry_msgs.msg import Vector3
        self.start_velocity = kwargs.get('start_velocity', Vector3())
        from geometry_msgs.msg import Point
        self.end_position = kwargs.get('end_position', Point())
        from geometry_msgs.msg import Vector3
        self.end_velocity = kwargs.get('end_velocity', Vector3())

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
        if self.start_position != other.start_position:
            return False
        if self.start_velocity != other.start_velocity:
            return False
        if self.end_position != other.end_position:
            return False
        if self.end_velocity != other.end_velocity:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def start_position(self):
        """Message field 'start_position'."""
        return self._start_position

    @start_position.setter
    def start_position(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            assert \
                isinstance(value, Point), \
                "The 'start_position' field must be a sub message of type 'Point'"
        self._start_position = value

    @property
    def start_velocity(self):
        """Message field 'start_velocity'."""
        return self._start_velocity

    @start_velocity.setter
    def start_velocity(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'start_velocity' field must be a sub message of type 'Vector3'"
        self._start_velocity = value

    @property
    def end_position(self):
        """Message field 'end_position'."""
        return self._end_position

    @end_position.setter
    def end_position(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            assert \
                isinstance(value, Point), \
                "The 'end_position' field must be a sub message of type 'Point'"
        self._end_position = value

    @property
    def end_velocity(self):
        """Message field 'end_velocity'."""
        return self._end_velocity

    @end_velocity.setter
    def end_velocity(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'end_velocity' field must be a sub message of type 'Vector3'"
        self._end_velocity = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_PathPlan_Response(type):
    """Metaclass of message 'PathPlan_Response'."""

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
                'interface.srv.PathPlan_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__path_plan__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__path_plan__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__path_plan__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__path_plan__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__path_plan__response

            from geometry_msgs.msg import Point
            if Point.__class__._TYPE_SUPPORT is None:
                Point.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PathPlan_Response(metaclass=Metaclass_PathPlan_Response):
    """Message class 'PathPlan_Response'."""

    __slots__ = [
        '_control_points',
        '_degree',
        '_knot_interval',
        '_success',
    ]

    _fields_and_field_types = {
        'control_points': 'sequence<geometry_msgs/Point>',
        'degree': 'int16',
        'knot_interval': 'double',
        'success': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point')),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.control_points = kwargs.get('control_points', [])
        self.degree = kwargs.get('degree', int())
        self.knot_interval = kwargs.get('knot_interval', float())
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
        if self.control_points != other.control_points:
            return False
        if self.degree != other.degree:
            return False
        if self.knot_interval != other.knot_interval:
            return False
        if self.success != other.success:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def control_points(self):
        """Message field 'control_points'."""
        return self._control_points

    @control_points.setter
    def control_points(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
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
                 all(isinstance(v, Point) for v in value) and
                 True), \
                "The 'control_points' field must be a set or sequence and each value of type 'Point'"
        self._control_points = value

    @property
    def degree(self):
        """Message field 'degree'."""
        return self._degree

    @degree.setter
    def degree(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'degree' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'degree' field must be an integer in [-32768, 32767]"
        self._degree = value

    @property
    def knot_interval(self):
        """Message field 'knot_interval'."""
        return self._knot_interval

    @knot_interval.setter
    def knot_interval(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'knot_interval' field must be of type 'float'"
        self._knot_interval = value

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


class Metaclass_PathPlan(type):
    """Metaclass of service 'PathPlan'."""

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
                'interface.srv.PathPlan')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__path_plan

            from interface.srv import _path_plan
            if _path_plan.Metaclass_PathPlan_Request._TYPE_SUPPORT is None:
                _path_plan.Metaclass_PathPlan_Request.__import_type_support__()
            if _path_plan.Metaclass_PathPlan_Response._TYPE_SUPPORT is None:
                _path_plan.Metaclass_PathPlan_Response.__import_type_support__()


class PathPlan(metaclass=Metaclass_PathPlan):
    from interface.srv._path_plan import PathPlan_Request as Request
    from interface.srv._path_plan import PathPlan_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
