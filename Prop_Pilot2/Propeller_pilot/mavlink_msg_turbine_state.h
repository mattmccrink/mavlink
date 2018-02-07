#pragma once
// MESSAGE TURBINE_STATE PACKING

#define MAVLINK_MSG_ID_TURBINE_STATE 2399

MAVPACKED(
typedef struct __mavlink_turbine_state_t {
 uint32_t time_boot_ms; /*< Timestamp of the component clock since boot time in milliseconds.*/
 int32_t RPM; /*< Turbine RPM*/
 int16_t EGT; /*< Exhaust gas temperature*/
 int16_t FuelConsumed; /*< Total fuel consumed (mL)*/
 int16_t FuelFlow; /*< Fuel Flow in mL/min*/
 int16_t FuelRemaining; /*< Total fuel remaining (mL)*/
 int8_t State; /*< Turbine operational state*/
}) mavlink_turbine_state_t;

#define MAVLINK_MSG_ID_TURBINE_STATE_LEN 17
#define MAVLINK_MSG_ID_TURBINE_STATE_MIN_LEN 17
#define MAVLINK_MSG_ID_2399_LEN 17
#define MAVLINK_MSG_ID_2399_MIN_LEN 17

#define MAVLINK_MSG_ID_TURBINE_STATE_CRC 204
#define MAVLINK_MSG_ID_2399_CRC 204



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TURBINE_STATE { \
    2399, \
    "TURBINE_STATE", \
    7, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_turbine_state_t, time_boot_ms) }, \
         { "RPM", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_turbine_state_t, RPM) }, \
         { "EGT", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_turbine_state_t, EGT) }, \
         { "FuelConsumed", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_turbine_state_t, FuelConsumed) }, \
         { "FuelFlow", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_turbine_state_t, FuelFlow) }, \
         { "FuelRemaining", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_turbine_state_t, FuelRemaining) }, \
         { "State", NULL, MAVLINK_TYPE_INT8_T, 0, 16, offsetof(mavlink_turbine_state_t, State) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TURBINE_STATE { \
    "TURBINE_STATE", \
    7, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_turbine_state_t, time_boot_ms) }, \
         { "RPM", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_turbine_state_t, RPM) }, \
         { "EGT", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_turbine_state_t, EGT) }, \
         { "FuelConsumed", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_turbine_state_t, FuelConsumed) }, \
         { "FuelFlow", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_turbine_state_t, FuelFlow) }, \
         { "FuelRemaining", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_turbine_state_t, FuelRemaining) }, \
         { "State", NULL, MAVLINK_TYPE_INT8_T, 0, 16, offsetof(mavlink_turbine_state_t, State) }, \
         } \
}
#endif

/**
 * @brief Pack a turbine_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms Timestamp of the component clock since boot time in milliseconds.
 * @param RPM Turbine RPM
 * @param EGT Exhaust gas temperature
 * @param FuelConsumed Total fuel consumed (mL)
 * @param FuelFlow Fuel Flow in mL/min
 * @param FuelRemaining Total fuel remaining (mL)
 * @param State Turbine operational state
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_turbine_state_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, int32_t RPM, int16_t EGT, int16_t FuelConsumed, int16_t FuelFlow, int16_t FuelRemaining, int8_t State)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TURBINE_STATE_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_int32_t(buf, 4, RPM);
    _mav_put_int16_t(buf, 8, EGT);
    _mav_put_int16_t(buf, 10, FuelConsumed);
    _mav_put_int16_t(buf, 12, FuelFlow);
    _mav_put_int16_t(buf, 14, FuelRemaining);
    _mav_put_int8_t(buf, 16, State);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TURBINE_STATE_LEN);
#else
    mavlink_turbine_state_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.RPM = RPM;
    packet.EGT = EGT;
    packet.FuelConsumed = FuelConsumed;
    packet.FuelFlow = FuelFlow;
    packet.FuelRemaining = FuelRemaining;
    packet.State = State;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TURBINE_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TURBINE_STATE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TURBINE_STATE_MIN_LEN, MAVLINK_MSG_ID_TURBINE_STATE_LEN, MAVLINK_MSG_ID_TURBINE_STATE_CRC);
}

/**
 * @brief Pack a turbine_state message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms Timestamp of the component clock since boot time in milliseconds.
 * @param RPM Turbine RPM
 * @param EGT Exhaust gas temperature
 * @param FuelConsumed Total fuel consumed (mL)
 * @param FuelFlow Fuel Flow in mL/min
 * @param FuelRemaining Total fuel remaining (mL)
 * @param State Turbine operational state
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_turbine_state_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_boot_ms,int32_t RPM,int16_t EGT,int16_t FuelConsumed,int16_t FuelFlow,int16_t FuelRemaining,int8_t State)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TURBINE_STATE_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_int32_t(buf, 4, RPM);
    _mav_put_int16_t(buf, 8, EGT);
    _mav_put_int16_t(buf, 10, FuelConsumed);
    _mav_put_int16_t(buf, 12, FuelFlow);
    _mav_put_int16_t(buf, 14, FuelRemaining);
    _mav_put_int8_t(buf, 16, State);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TURBINE_STATE_LEN);
#else
    mavlink_turbine_state_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.RPM = RPM;
    packet.EGT = EGT;
    packet.FuelConsumed = FuelConsumed;
    packet.FuelFlow = FuelFlow;
    packet.FuelRemaining = FuelRemaining;
    packet.State = State;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TURBINE_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TURBINE_STATE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TURBINE_STATE_MIN_LEN, MAVLINK_MSG_ID_TURBINE_STATE_LEN, MAVLINK_MSG_ID_TURBINE_STATE_CRC);
}

/**
 * @brief Encode a turbine_state struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param turbine_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_turbine_state_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_turbine_state_t* turbine_state)
{
    return mavlink_msg_turbine_state_pack(system_id, component_id, msg, turbine_state->time_boot_ms, turbine_state->RPM, turbine_state->EGT, turbine_state->FuelConsumed, turbine_state->FuelFlow, turbine_state->FuelRemaining, turbine_state->State);
}

/**
 * @brief Encode a turbine_state struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param turbine_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_turbine_state_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_turbine_state_t* turbine_state)
{
    return mavlink_msg_turbine_state_pack_chan(system_id, component_id, chan, msg, turbine_state->time_boot_ms, turbine_state->RPM, turbine_state->EGT, turbine_state->FuelConsumed, turbine_state->FuelFlow, turbine_state->FuelRemaining, turbine_state->State);
}

/**
 * @brief Send a turbine_state message
 * @param chan MAVLink channel to send the message
 *
 * @param time_boot_ms Timestamp of the component clock since boot time in milliseconds.
 * @param RPM Turbine RPM
 * @param EGT Exhaust gas temperature
 * @param FuelConsumed Total fuel consumed (mL)
 * @param FuelFlow Fuel Flow in mL/min
 * @param FuelRemaining Total fuel remaining (mL)
 * @param State Turbine operational state
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_turbine_state_send(mavlink_channel_t chan, uint32_t time_boot_ms, int32_t RPM, int16_t EGT, int16_t FuelConsumed, int16_t FuelFlow, int16_t FuelRemaining, int8_t State)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TURBINE_STATE_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_int32_t(buf, 4, RPM);
    _mav_put_int16_t(buf, 8, EGT);
    _mav_put_int16_t(buf, 10, FuelConsumed);
    _mav_put_int16_t(buf, 12, FuelFlow);
    _mav_put_int16_t(buf, 14, FuelRemaining);
    _mav_put_int8_t(buf, 16, State);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TURBINE_STATE, buf, MAVLINK_MSG_ID_TURBINE_STATE_MIN_LEN, MAVLINK_MSG_ID_TURBINE_STATE_LEN, MAVLINK_MSG_ID_TURBINE_STATE_CRC);
#else
    mavlink_turbine_state_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.RPM = RPM;
    packet.EGT = EGT;
    packet.FuelConsumed = FuelConsumed;
    packet.FuelFlow = FuelFlow;
    packet.FuelRemaining = FuelRemaining;
    packet.State = State;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TURBINE_STATE, (const char *)&packet, MAVLINK_MSG_ID_TURBINE_STATE_MIN_LEN, MAVLINK_MSG_ID_TURBINE_STATE_LEN, MAVLINK_MSG_ID_TURBINE_STATE_CRC);
#endif
}

/**
 * @brief Send a turbine_state message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_turbine_state_send_struct(mavlink_channel_t chan, const mavlink_turbine_state_t* turbine_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_turbine_state_send(chan, turbine_state->time_boot_ms, turbine_state->RPM, turbine_state->EGT, turbine_state->FuelConsumed, turbine_state->FuelFlow, turbine_state->FuelRemaining, turbine_state->State);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TURBINE_STATE, (const char *)turbine_state, MAVLINK_MSG_ID_TURBINE_STATE_MIN_LEN, MAVLINK_MSG_ID_TURBINE_STATE_LEN, MAVLINK_MSG_ID_TURBINE_STATE_CRC);
#endif
}

#if MAVLINK_MSG_ID_TURBINE_STATE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_turbine_state_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t time_boot_ms, int32_t RPM, int16_t EGT, int16_t FuelConsumed, int16_t FuelFlow, int16_t FuelRemaining, int8_t State)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_int32_t(buf, 4, RPM);
    _mav_put_int16_t(buf, 8, EGT);
    _mav_put_int16_t(buf, 10, FuelConsumed);
    _mav_put_int16_t(buf, 12, FuelFlow);
    _mav_put_int16_t(buf, 14, FuelRemaining);
    _mav_put_int8_t(buf, 16, State);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TURBINE_STATE, buf, MAVLINK_MSG_ID_TURBINE_STATE_MIN_LEN, MAVLINK_MSG_ID_TURBINE_STATE_LEN, MAVLINK_MSG_ID_TURBINE_STATE_CRC);
#else
    mavlink_turbine_state_t *packet = (mavlink_turbine_state_t *)msgbuf;
    packet->time_boot_ms = time_boot_ms;
    packet->RPM = RPM;
    packet->EGT = EGT;
    packet->FuelConsumed = FuelConsumed;
    packet->FuelFlow = FuelFlow;
    packet->FuelRemaining = FuelRemaining;
    packet->State = State;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TURBINE_STATE, (const char *)packet, MAVLINK_MSG_ID_TURBINE_STATE_MIN_LEN, MAVLINK_MSG_ID_TURBINE_STATE_LEN, MAVLINK_MSG_ID_TURBINE_STATE_CRC);
#endif
}
#endif

#endif

// MESSAGE TURBINE_STATE UNPACKING


/**
 * @brief Get field time_boot_ms from turbine_state message
 *
 * @return Timestamp of the component clock since boot time in milliseconds.
 */
static inline uint32_t mavlink_msg_turbine_state_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field RPM from turbine_state message
 *
 * @return Turbine RPM
 */
static inline int32_t mavlink_msg_turbine_state_get_RPM(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field EGT from turbine_state message
 *
 * @return Exhaust gas temperature
 */
static inline int16_t mavlink_msg_turbine_state_get_EGT(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  8);
}

/**
 * @brief Get field FuelConsumed from turbine_state message
 *
 * @return Total fuel consumed (mL)
 */
static inline int16_t mavlink_msg_turbine_state_get_FuelConsumed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  10);
}

/**
 * @brief Get field FuelFlow from turbine_state message
 *
 * @return Fuel Flow in mL/min
 */
static inline int16_t mavlink_msg_turbine_state_get_FuelFlow(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  12);
}

/**
 * @brief Get field FuelRemaining from turbine_state message
 *
 * @return Total fuel remaining (mL)
 */
static inline int16_t mavlink_msg_turbine_state_get_FuelRemaining(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  14);
}

/**
 * @brief Get field State from turbine_state message
 *
 * @return Turbine operational state
 */
static inline int8_t mavlink_msg_turbine_state_get_State(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  16);
}

/**
 * @brief Decode a turbine_state message into a struct
 *
 * @param msg The message to decode
 * @param turbine_state C-struct to decode the message contents into
 */
static inline void mavlink_msg_turbine_state_decode(const mavlink_message_t* msg, mavlink_turbine_state_t* turbine_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    turbine_state->time_boot_ms = mavlink_msg_turbine_state_get_time_boot_ms(msg);
    turbine_state->RPM = mavlink_msg_turbine_state_get_RPM(msg);
    turbine_state->EGT = mavlink_msg_turbine_state_get_EGT(msg);
    turbine_state->FuelConsumed = mavlink_msg_turbine_state_get_FuelConsumed(msg);
    turbine_state->FuelFlow = mavlink_msg_turbine_state_get_FuelFlow(msg);
    turbine_state->FuelRemaining = mavlink_msg_turbine_state_get_FuelRemaining(msg);
    turbine_state->State = mavlink_msg_turbine_state_get_State(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TURBINE_STATE_LEN? msg->len : MAVLINK_MSG_ID_TURBINE_STATE_LEN;
        memset(turbine_state, 0, MAVLINK_MSG_ID_TURBINE_STATE_LEN);
    memcpy(turbine_state, _MAV_PAYLOAD(msg), len);
#endif
}
