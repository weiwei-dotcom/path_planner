# generated from rosidl_generator_py/resource/_idl.py.em
# with input from interface:msg/MoveMotor.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MoveMotor(type):
    """Metaclass of message 'MoveMotor'."""

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
                'interface.msg.MoveMotor')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__move_motor
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__move_motor
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__move_motor
            cls._TYPE_SUPPORT = module.type_support_msg__msg__move_motor
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__move_motor

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MoveMotor(metaclass=Metaclass_MoveMotor):
    """Message class 'MoveMotor'."""

    __slots__ = [
        '_motor_id',
        '_pos',
        '_vel',
        '_tor',
        '_kp',
        '_kd',
    ]

    _fields_and_field_types = {
        'motor_id': 'int64',
        'pos': 'int64',
        'vel': 'int64',
        'tor': 'int64',
        'kp': 'int64',
        'kd': 'int64',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.motor_id = kwargs.get('motor_id', int())
        self.pos = kwargs.get('pos', int())
        self.vel = kwargs.get('vel', int())
        self.tor = kwargs.get('tor', int())
        self.kp = kwargs.get('kp', int())
        self.kd = kwargs.get('kd', int())

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
        if self.motor_id != other.motor_id:
            return False
        if self.pos != other.pos:
            return False
        if self.vel != other.vel:
            return False
        if self.tor != other.tor:
            return False
        if self.kp != other.kp:
            return False
        if self.kd != other.kd:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def motor_id(self):
        """Message field 'motor_id'."""
        return self._motor_id

    @motor_id.setter
    def motor_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'motor_id' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'motor_id' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._motor_id = value

    @property
    def pos(self):
        """Message field 'pos'."""
        return self._pos

    @pos.setter
    def pos(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'pos' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'pos' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._pos = value

    @property
    def vel(self):
        """Message field 'vel'."""
        return self._vel

    @vel.setter
    def vel(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'vel' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'vel' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._vel = value

    @property
    def tor(self):
        """Message field 'tor'."""
        return self._tor

    @tor.setter
    def tor(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'tor' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'tor' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._tor = value

    @property
    def kp(self):
        """Message field 'kp'."""
        return self._kp

    @kp.setter
    def kp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'kp' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'kp' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._kp = value

    @property
    def kd(self):
        """Message field 'kd'."""
        return self._kd

    @kd.setter
    def kd(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'kd' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'kd' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._kd = value
