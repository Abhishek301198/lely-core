cdef extern from "lely/can/can.h":
    enum can_state:
        _CAN_STATE_ACTIVE "CAN_STATE_ACTIVE"
        _CAN_STATE_PASSIVE "CAN_STATE_PASSIVE"
        _CAN_STATE_BUSOFF "CAN_STATE_BUSOFF"

    enum can_error:
        _CAN_ERROR_BIT "CAN_ERROR_BIT"
        _CAN_ERROR_STUFF "CAN_ERROR_STUFF"
        _CAN_ERROR_CRC "CAN_ERROR_CRC"
        _CAN_ERROR_FORM "CAN_ERROR_FORM"
        _CAN_ERROR_ACK "CAN_ERROR_ACK"
        _CAN_ERROR_OTHER "CAN_ERROR_OTHER"

