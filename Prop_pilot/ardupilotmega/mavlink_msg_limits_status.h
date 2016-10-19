<<<<<<< HEAD
=======
#pragma once
>>>>>>> 31e07fdfff352ae5ce4c37855956cc51d0f48012
// MESSAGE LIMITS_STATUS PACKING

#define MAVLINK_MSG_ID_LIMITS_STATUS 167

MAVPACKED(
typedef struct __mavlink_limits_status_t {
 uint32_t last_trigger; /*< time of last breach in milliseconds since boot*/
 uint32_t last_action; /*< time of last recovery action in milliseconds since boot*/
 uint32_t last_recovery; /*< time of last successful recovery in milliseconds since boot*/
 uint32_t last_clear; /*< time of last all-clear in milliseconds since boot*/
 uint16_t breach_count; /*< number of fence breaches*/
 uint8_t limits_state; /*< state of AP_Limits, (see enum LimitState, LIMITS_STATE)*/
 uint8_t mods_enabled; /*< AP_Limit_Module bitfield of enabled modules, (see enum moduleid or LIMIT_MODULE)*/
 uint8_t mods_required; /*< AP_Limit_Module bitfield of required modules, (see enum moduleid or LIMIT_MODULE)*/
 uint8_t mods_triggered; /*< AP_Limit_Module bitfield of triggered modules, (see enum moduleid or LIMIT_MODULE)*/
}) mavlink_limits_status_t;

#define MAVLINK_MSG_ID_LIMITS_STATUS_LEN 22
#define MAVLINK_MSG_ID_LIMITS_STATUS_MIN_LEN 22
#define MAVLINK_MSG_ID_167_LEN 22
#define MAVLINK_MSG_ID_167_MIN_LEN 22

#define MAVLINK_MSG_ID_LIMITS_STATUS_CRC 144
#define MAVLINK_MSG_ID_167_CRC 144



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_LIMITS_STATUS { \
<<<<<<< HEAD
	167, \
	"LIMITS_STATUS", \
	9, \
	{  { "last_trigger", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_limits_status_t, last_trigger) }, \
=======
    167, \
    "LIMITS_STATUS", \
    9, \
    {  { "last_trigger", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_limits_status_t, last_trigger) }, \
>>>>>>> 31e07fdfff352ae5ce4c37855956cc51d0f48012
         { "last_action", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_limits_status_t, last_action) }, \
         { "last_recovery", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_limits_status_t, last_recovery) }, \
         { "last_clear", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_limits_status_t, last_clear) }, \
         { "breach_count", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_limits_status_t, breach_count) }, \
         { "limits_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 18, offsetof(mavlink_limits_status_t, limits_state) }, \
         { "mods_enabled", NULL, MAVLINK_TYPE_UINT8_T, 0, 19, offsetof(mavlink_limits_status_t, mods_enabled) }, \
         { "mods_required", NULL, MAVLINK_TYPE_UINT8_T, 0, 20, offsetof(mavlink_limits_status_t, mods_required) }, \
         { "mods_triggered", NULL, MAVLINK_TYPE_UINT8_T, 0, 21, offsetof(mavlink_limits_status_t, mods_triggered) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_LIMITS_STATUS { \
<<<<<<< HEAD
	"LIMITS_STATUS", \
	9, \
	{  { "last_trigger", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_limits_status_t, last_trigger) }, \
=======
    "LIMITS_STATUS", \
    9, \
    {  { "last_trigger", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_limits_status_t, last_trigger) }, \
>>>>>>> 31e07fdfff352ae5ce4c37855956cc51d0f48012
         { "last_action", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_limits_status_t, last_action) }, \
         { "last_recovery", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_limits_status_t, last_recovery) }, \
         { "last_clear", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_limits_status_t, last_clear) }, \
         { "breach_count", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_limits_status_t, breach_count) }, \
         { "limits_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 18, offsetof(mavlink_limits_status_t, limits_state) }, \
         { "mods_enabled", NULL, MAVLINK_TYPE_UINT8_T, 0, 19, offsetof(mavlink_limits_status_t, mods_enabled) }, \
         { "mods_required", NULL, MAVLINK_TYPE_UINT8_T, 0, 20, offsetof(mavlink_limits_status_t, mods_required) }, \
         { "mods_triggered", NULL, MAVLINK_TYPE_UINT8_T, 0, 21, offsetof(mavlink_limits_status_t, mods_triggered) }, \
         } \
}
#endif

/**
 * @brief Pack a limits_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param limits_state state of AP_Limits, (see enum LimitState, LIMITS_STATE)
 * @param last_trigger time of last breach in milliseconds since boot
 * @param last_action time of last recovery action in milliseconds since boot
 * @param last_recovery time of last successful recovery in milliseconds since boot
 * @param last_clear time of last all-clear in milliseconds since boot
 * @param breach_count number of fence breaches
 * @param mods_enabled AP_Limit_Module bitfield of enabled modules, (see enum moduleid or LIMIT_MODULE)
 * @param mods_required AP_Limit_Module bitfield of required modules, (see enum moduleid or LIMIT_MODULE)
 * @param mods_triggered AP_Limit_Module bitfield of triggered modules, (see enum moduleid or LIMIT_MODULE)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_limits_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
<<<<<<< HEAD
						       uint8_t limits_state, uint32_t last_trigger, uint32_t last_action, uint32_t last_recovery, uint32_t last_clear, uint16_t breach_count, uint8_t mods_enabled, uint8_t mods_required, uint8_t mods_triggered)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_LIMITS_STATUS_LEN];
	_mav_put_uint32_t(buf, 0, last_trigger);
	_mav_put_uint32_t(buf, 4, last_action);
	_mav_put_uint32_t(buf, 8, last_recovery);
	_mav_put_uint32_t(buf, 12, last_clear);
	_mav_put_uint16_t(buf, 16, breach_count);
	_mav_put_uint8_t(buf, 18, limits_state);
	_mav_put_uint8_t(buf, 19, mods_enabled);
	_mav_put_uint8_t(buf, 20, mods_required);
	_mav_put_uint8_t(buf, 21, mods_triggered);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LIMITS_STATUS_LEN);
#else
	mavlink_limits_status_t packet;
	packet.last_trigger = last_trigger;
	packet.last_action = last_action;
	packet.last_recovery = last_recovery;
	packet.last_clear = last_clear;
	packet.breach_count = breach_count;
	packet.limits_state = limits_state;
	packet.mods_enabled = mods_enabled;
	packet.mods_required = mods_required;
	packet.mods_triggered = mods_triggered;
=======
                               uint8_t limits_state, uint32_t last_trigger, uint32_t last_action, uint32_t last_recovery, uint32_t last_clear, uint16_t breach_count, uint8_t mods_enabled, uint8_t mods_required, uint8_t mods_triggered)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LIMITS_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, last_trigger);
    _mav_put_uint32_t(buf, 4, last_action);
    _mav_put_uint32_t(buf, 8, last_recovery);
    _mav_put_uint32_t(buf, 12, last_clear);
    _mav_put_uint16_t(buf, 16, breach_count);
    _mav_put_uint8_t(buf, 18, limits_state);
    _mav_put_uint8_t(buf, 19, mods_enabled);
    _mav_put_uint8_t(buf, 20, mods_required);
    _mav_put_uint8_t(buf, 21, mods_triggered);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LIMITS_STATUS_LEN);
#else
    mavlink_limits_status_t packet;
    packet.last_trigger = last_trigger;
    packet.last_action = last_action;
    packet.last_recovery = last_recovery;
    packet.last_clear = last_clear;
    packet.breach_count = breach_count;
    packet.limits_state = limits_state;
    packet.mods_enabled = mods_enabled;
    packet.mods_required = mods_required;
    packet.mods_triggered = mods_triggered;
>>>>>>> 31e07fdfff352ae5ce4c37855956cc51d0f48012

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LIMITS_STATUS_LEN);
#endif

<<<<<<< HEAD
	msg->msgid = MAVLINK_MSG_ID_LIMITS_STATUS;
=======
    msg->msgid = MAVLINK_MSG_ID_LIMITS_STATUS;
>>>>>>> 31e07fdfff352ae5ce4c37855956cc51d0f48012
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_LIMITS_STATUS_MIN_LEN, MAVLINK_MSG_ID_LIMITS_STATUS_LEN, MAVLINK_MSG_ID_LIMITS_STATUS_CRC);
}

/**
 * @brief Pack a limits_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param limits_state state of AP_Limits, (see enum LimitState, LIMITS_STATE)
 * @param last_trigger time of last breach in milliseconds since boot
 * @param last_action time of last recovery action in milliseconds since boot
 * @param last_recovery time of last successful recovery in milliseconds since boot
 * @param last_clear time of last all-clear in milliseconds since boot
 * @param breach_count number of fence breaches
 * @param mods_enabled AP_Limit_Module bitfield of enabled modules, (see enum moduleid or LIMIT_MODULE)
 * @param mods_required AP_Limit_Module bitfield of required modules, (see enum moduleid or LIMIT_MODULE)
 * @param mods_triggered AP_Limit_Module bitfield of triggered modules, (see enum moduleid or LIMIT_MODULE)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_limits_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
<<<<<<< HEAD
							   mavlink_message_t* msg,
						           uint8_t limits_state,uint32_t last_trigger,uint32_t last_action,uint32_t last_recovery,uint32_t last_clear,uint16_t breach_count,uint8_t mods_enabled,uint8_t mods_required,uint8_t mods_triggered)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_LIMITS_STATUS_LEN];
	_mav_put_uint32_t(buf, 0, last_trigger);
	_mav_put_uint32_t(buf, 4, last_action);
	_mav_put_uint32_t(buf, 8, last_recovery);
	_mav_put_uint32_t(buf, 12, last_clear);
	_mav_put_uint16_t(buf, 16, breach_count);
	_mav_put_uint8_t(buf, 18, limits_state);
	_mav_put_uint8_t(buf, 19, mods_enabled);
	_mav_put_uint8_t(buf, 20, mods_required);
	_mav_put_uint8_t(buf, 21, mods_triggered);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LIMITS_STATUS_LEN);
#else
	mavlink_limits_status_t packet;
	packet.last_trigger = last_trigger;
	packet.last_action = last_action;
	packet.last_recovery = last_recovery;
	packet.last_clear = last_clear;
	packet.breach_count = breach_count;
	packet.limits_state = limits_state;
	packet.mods_enabled = mods_enabled;
	packet.mods_required = mods_required;
	packet.mods_triggered = mods_triggered;
=======
                               mavlink_message_t* msg,
                                   uint8_t limits_state,uint32_t last_trigger,uint32_t last_action,uint32_t last_recovery,uint32_t last_clear,uint16_t breach_count,uint8_t mods_enabled,uint8_t mods_required,uint8_t mods_triggered)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LIMITS_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, last_trigger);
    _mav_put_uint32_t(buf, 4, last_action);
    _mav_put_uint32_t(buf, 8, last_recovery);
    _mav_put_uint32_t(buf, 12, last_clear);
    _mav_put_uint16_t(buf, 16, breach_count);
    _mav_put_uint8_t(buf, 18, limits_state);
    _mav_put_uint8_t(buf, 19, mods_enabled);
    _mav_put_uint8_t(buf, 20, mods_required);
    _mav_put_uint8_t(buf, 21, mods_triggered);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LIMITS_STATUS_LEN);
#else
    mavlink_limits_status_t packet;
    packet.last_trigger = last_trigger;
    packet.last_action = last_action;
    packet.last_recovery = last_recovery;
    packet.last_clear = last_clear;
    packet.breach_count = breach_count;
    packet.limits_state = limits_state;
    packet.mods_enabled = mods_enabled;
    packet.mods_required = mods_required;
    packet.mods_triggered = mods_triggered;
>>>>>>> 31e07fdfff352ae5ce4c37855956cc51d0f48012

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LIMITS_STATUS_LEN);
#endif

<<<<<<< HEAD
	msg->msgid = MAVLINK_MSG_ID_LIMITS_STATUS;
=======
    msg->msgid = MAVLINK_MSG_ID_LIMITS_STATUS;
>>>>>>> 31e07fdfff352ae5ce4c37855956cc51d0f48012
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_LIMITS_STATUS_MIN_LEN, MAVLINK_MSG_ID_LIMITS_STATUS_LEN, MAVLINK_MSG_ID_LIMITS_STATUS_CRC);
}

/**
 * @brief Encode a limits_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param limits_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_limits_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_limits_status_t* limits_status)
{
<<<<<<< HEAD
	return mavlink_msg_limits_status_pack(system_id, component_id, msg, limits_status->limits_state, limits_status->last_trigger, limits_status->last_action, limits_status->last_recovery, limits_status->last_clear, limits_status->breach_count, limits_status->mods_enabled, limits_status->mods_required, limits_status->mods_triggered);
=======
    return mavlink_msg_limits_status_pack(system_id, component_id, msg, limits_status->limits_state, limits_status->last_trigger, limits_status->last_action, limits_status->last_recovery, limits_status->last_clear, limits_status->breach_count, limits_status->mods_enabled, limits_status->mods_required, limits_status->mods_triggered);
>>>>>>> 31e07fdfff352ae5ce4c37855956cc51d0f48012
}

/**
 * @brief Encode a limits_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param limits_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_limits_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_limits_status_t* limits_status)
{
<<<<<<< HEAD
	return mavlink_msg_limits_status_pack_chan(system_id, component_id, chan, msg, limits_status->limits_state, limits_status->last_trigger, limits_status->last_action, limits_status->last_recovery, limits_status->last_clear, limits_status->breach_count, limits_status->mods_enabled, limits_status->mods_required, limits_status->mods_triggered);
=======
    return mavlink_msg_limits_status_pack_chan(system_id, component_id, chan, msg, limits_status->limits_state, limits_status->last_trigger, limits_status->last_action, limits_status->last_recovery, limits_status->last_clear, limits_status->breach_count, limits_status->mods_enabled, limits_status->mods_required, limits_status->mods_triggered);
>>>>>>> 31e07fdfff352ae5ce4c37855956cc51d0f48012
}

/**
 * @brief Send a limits_status message
 * @param chan MAVLink channel to send the message
 *
 * @param limits_state state of AP_Limits, (see enum LimitState, LIMITS_STATE)
 * @param last_trigger time of last breach in milliseconds since boot
 * @param last_action time of last recovery action in milliseconds since boot
 * @param last_recovery time of last successful recovery in milliseconds since boot
 * @param last_clear time of last all-clear in milliseconds since boot
 * @param breach_count number of fence breaches
 * @param mods_enabled AP_Limit_Module bitfield of enabled modules, (see enum moduleid or LIMIT_MODULE)
 * @param mods_required AP_Limit_Module bitfield of required modules, (see enum moduleid or LIMIT_MODULE)
 * @param mods_triggered AP_Limit_Module bitfield of triggered modules, (see enum moduleid or LIMIT_MODULE)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_limits_status_send(mavlink_channel_t chan, uint8_t limits_state, uint32_t last_trigger, uint32_t last_action, uint32_t last_recovery, uint32_t last_clear, uint16_t breach_count, uint8_t mods_enabled, uint8_t mods_required, uint8_t mods_triggered)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
<<<<<<< HEAD
	char buf[MAVLINK_MSG_ID_LIMITS_STATUS_LEN];
	_mav_put_uint32_t(buf, 0, last_trigger);
	_mav_put_uint32_t(buf, 4, last_action);
	_mav_put_uint32_t(buf, 8, last_recovery);
	_mav_put_uint32_t(buf, 12, last_clear);
	_mav_put_uint16_t(buf, 16, breach_count);
	_mav_put_uint8_t(buf, 18, limits_state);
	_mav_put_uint8_t(buf, 19, mods_enabled);
	_mav_put_uint8_t(buf, 20, mods_required);
	_mav_put_uint8_t(buf, 21, mods_triggered);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LIMITS_STATUS, buf, MAVLINK_MSG_ID_LIMITS_STATUS_MIN_LEN, MAVLINK_MSG_ID_LIMITS_STATUS_LEN, MAVLINK_MSG_ID_LIMITS_STATUS_CRC);
#else
	mavlink_limits_status_t packet;
	packet.last_trigger = last_trigger;
	packet.last_action = last_action;
	packet.last_recovery = last_recovery;
	packet.last_clear = last_clear;
	packet.breach_count = breach_count;
	packet.limits_state = limits_state;
	packet.mods_enabled = mods_enabled;
	packet.mods_required = mods_required;
	packet.mods_triggered = mods_triggered;
=======
    char buf[MAVLINK_MSG_ID_LIMITS_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, last_trigger);
    _mav_put_uint32_t(buf, 4, last_action);
    _mav_put_uint32_t(buf, 8, last_recovery);
    _mav_put_uint32_t(buf, 12, last_clear);
    _mav_put_uint16_t(buf, 16, breach_count);
    _mav_put_uint8_t(buf, 18, limits_state);
    _mav_put_uint8_t(buf, 19, mods_enabled);
    _mav_put_uint8_t(buf, 20, mods_required);
    _mav_put_uint8_t(buf, 21, mods_triggered);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LIMITS_STATUS, buf, MAVLINK_MSG_ID_LIMITS_STATUS_MIN_LEN, MAVLINK_MSG_ID_LIMITS_STATUS_LEN, MAVLINK_MSG_ID_LIMITS_STATUS_CRC);
#else
    mavlink_limits_status_t packet;
    packet.last_trigger = last_trigger;
    packet.last_action = last_action;
    packet.last_recovery = last_recovery;
    packet.last_clear = last_clear;
    packet.breach_count = breach_count;
    packet.limits_state = limits_state;
    packet.mods_enabled = mods_enabled;
    packet.mods_required = mods_required;
    packet.mods_triggered = mods_triggered;
>>>>>>> 31e07fdfff352ae5ce4c37855956cc51d0f48012

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LIMITS_STATUS, (const char *)&packet, MAVLINK_MSG_ID_LIMITS_STATUS_MIN_LEN, MAVLINK_MSG_ID_LIMITS_STATUS_LEN, MAVLINK_MSG_ID_LIMITS_STATUS_CRC);
#endif
}

/**
 * @brief Send a limits_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_limits_status_send_struct(mavlink_channel_t chan, const mavlink_limits_status_t* limits_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_limits_status_send(chan, limits_status->limits_state, limits_status->last_trigger, limits_status->last_action, limits_status->last_recovery, limits_status->last_clear, limits_status->breach_count, limits_status->mods_enabled, limits_status->mods_required, limits_status->mods_triggered);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LIMITS_STATUS, (const char *)limits_status, MAVLINK_MSG_ID_LIMITS_STATUS_MIN_LEN, MAVLINK_MSG_ID_LIMITS_STATUS_LEN, MAVLINK_MSG_ID_LIMITS_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_LIMITS_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_limits_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t limits_state, uint32_t last_trigger, uint32_t last_action, uint32_t last_recovery, uint32_t last_clear, uint16_t breach_count, uint8_t mods_enabled, uint8_t mods_required, uint8_t mods_triggered)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
<<<<<<< HEAD
	char *buf = (char *)msgbuf;
	_mav_put_uint32_t(buf, 0, last_trigger);
	_mav_put_uint32_t(buf, 4, last_action);
	_mav_put_uint32_t(buf, 8, last_recovery);
	_mav_put_uint32_t(buf, 12, last_clear);
	_mav_put_uint16_t(buf, 16, breach_count);
	_mav_put_uint8_t(buf, 18, limits_state);
	_mav_put_uint8_t(buf, 19, mods_enabled);
	_mav_put_uint8_t(buf, 20, mods_required);
	_mav_put_uint8_t(buf, 21, mods_triggered);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LIMITS_STATUS, buf, MAVLINK_MSG_ID_LIMITS_STATUS_MIN_LEN, MAVLINK_MSG_ID_LIMITS_STATUS_LEN, MAVLINK_MSG_ID_LIMITS_STATUS_CRC);
#else
	mavlink_limits_status_t *packet = (mavlink_limits_status_t *)msgbuf;
	packet->last_trigger = last_trigger;
	packet->last_action = last_action;
	packet->last_recovery = last_recovery;
	packet->last_clear = last_clear;
	packet->breach_count = breach_count;
	packet->limits_state = limits_state;
	packet->mods_enabled = mods_enabled;
	packet->mods_required = mods_required;
	packet->mods_triggered = mods_triggered;
=======
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, last_trigger);
    _mav_put_uint32_t(buf, 4, last_action);
    _mav_put_uint32_t(buf, 8, last_recovery);
    _mav_put_uint32_t(buf, 12, last_clear);
    _mav_put_uint16_t(buf, 16, breach_count);
    _mav_put_uint8_t(buf, 18, limits_state);
    _mav_put_uint8_t(buf, 19, mods_enabled);
    _mav_put_uint8_t(buf, 20, mods_required);
    _mav_put_uint8_t(buf, 21, mods_triggered);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LIMITS_STATUS, buf, MAVLINK_MSG_ID_LIMITS_STATUS_MIN_LEN, MAVLINK_MSG_ID_LIMITS_STATUS_LEN, MAVLINK_MSG_ID_LIMITS_STATUS_CRC);
#else
    mavlink_limits_status_t *packet = (mavlink_limits_status_t *)msgbuf;
    packet->last_trigger = last_trigger;
    packet->last_action = last_action;
    packet->last_recovery = last_recovery;
    packet->last_clear = last_clear;
    packet->breach_count = breach_count;
    packet->limits_state = limits_state;
    packet->mods_enabled = mods_enabled;
    packet->mods_required = mods_required;
    packet->mods_triggered = mods_triggered;
>>>>>>> 31e07fdfff352ae5ce4c37855956cc51d0f48012

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LIMITS_STATUS, (const char *)packet, MAVLINK_MSG_ID_LIMITS_STATUS_MIN_LEN, MAVLINK_MSG_ID_LIMITS_STATUS_LEN, MAVLINK_MSG_ID_LIMITS_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE LIMITS_STATUS UNPACKING


/**
 * @brief Get field limits_state from limits_status message
 *
 * @return state of AP_Limits, (see enum LimitState, LIMITS_STATE)
 */
static inline uint8_t mavlink_msg_limits_status_get_limits_state(const mavlink_message_t* msg)
{
<<<<<<< HEAD
	return _MAV_RETURN_uint8_t(msg,  18);
=======
    return _MAV_RETURN_uint8_t(msg,  18);
>>>>>>> 31e07fdfff352ae5ce4c37855956cc51d0f48012
}

/**
 * @brief Get field last_trigger from limits_status message
 *
 * @return time of last breach in milliseconds since boot
 */
static inline uint32_t mavlink_msg_limits_status_get_last_trigger(const mavlink_message_t* msg)
{
<<<<<<< HEAD
	return _MAV_RETURN_uint32_t(msg,  0);
=======
    return _MAV_RETURN_uint32_t(msg,  0);
>>>>>>> 31e07fdfff352ae5ce4c37855956cc51d0f48012
}

/**
 * @brief Get field last_action from limits_status message
 *
 * @return time of last recovery action in milliseconds since boot
 */
static inline uint32_t mavlink_msg_limits_status_get_last_action(const mavlink_message_t* msg)
{
<<<<<<< HEAD
	return _MAV_RETURN_uint32_t(msg,  4);
=======
    return _MAV_RETURN_uint32_t(msg,  4);
>>>>>>> 31e07fdfff352ae5ce4c37855956cc51d0f48012
}

/**
 * @brief Get field last_recovery from limits_status message
 *
 * @return time of last successful recovery in milliseconds since boot
 */
static inline uint32_t mavlink_msg_limits_status_get_last_recovery(const mavlink_message_t* msg)
{
<<<<<<< HEAD
	return _MAV_RETURN_uint32_t(msg,  8);
=======
    return _MAV_RETURN_uint32_t(msg,  8);
>>>>>>> 31e07fdfff352ae5ce4c37855956cc51d0f48012
}

/**
 * @brief Get field last_clear from limits_status message
 *
 * @return time of last all-clear in milliseconds since boot
 */
static inline uint32_t mavlink_msg_limits_status_get_last_clear(const mavlink_message_t* msg)
{
<<<<<<< HEAD
	return _MAV_RETURN_uint32_t(msg,  12);
=======
    return _MAV_RETURN_uint32_t(msg,  12);
>>>>>>> 31e07fdfff352ae5ce4c37855956cc51d0f48012
}

/**
 * @brief Get field breach_count from limits_status message
 *
 * @return number of fence breaches
 */
static inline uint16_t mavlink_msg_limits_status_get_breach_count(const mavlink_message_t* msg)
{
<<<<<<< HEAD
	return _MAV_RETURN_uint16_t(msg,  16);
=======
    return _MAV_RETURN_uint16_t(msg,  16);
>>>>>>> 31e07fdfff352ae5ce4c37855956cc51d0f48012
}

/**
 * @brief Get field mods_enabled from limits_status message
 *
 * @return AP_Limit_Module bitfield of enabled modules, (see enum moduleid or LIMIT_MODULE)
 */
static inline uint8_t mavlink_msg_limits_status_get_mods_enabled(const mavlink_message_t* msg)
{
<<<<<<< HEAD
	return _MAV_RETURN_uint8_t(msg,  19);
=======
    return _MAV_RETURN_uint8_t(msg,  19);
>>>>>>> 31e07fdfff352ae5ce4c37855956cc51d0f48012
}

/**
 * @brief Get field mods_required from limits_status message
 *
 * @return AP_Limit_Module bitfield of required modules, (see enum moduleid or LIMIT_MODULE)
 */
static inline uint8_t mavlink_msg_limits_status_get_mods_required(const mavlink_message_t* msg)
{
<<<<<<< HEAD
	return _MAV_RETURN_uint8_t(msg,  20);
=======
    return _MAV_RETURN_uint8_t(msg,  20);
>>>>>>> 31e07fdfff352ae5ce4c37855956cc51d0f48012
}

/**
 * @brief Get field mods_triggered from limits_status message
 *
 * @return AP_Limit_Module bitfield of triggered modules, (see enum moduleid or LIMIT_MODULE)
 */
static inline uint8_t mavlink_msg_limits_status_get_mods_triggered(const mavlink_message_t* msg)
{
<<<<<<< HEAD
	return _MAV_RETURN_uint8_t(msg,  21);
=======
    return _MAV_RETURN_uint8_t(msg,  21);
>>>>>>> 31e07fdfff352ae5ce4c37855956cc51d0f48012
}

/**
 * @brief Decode a limits_status message into a struct
 *
 * @param msg The message to decode
 * @param limits_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_limits_status_decode(const mavlink_message_t* msg, mavlink_limits_status_t* limits_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
<<<<<<< HEAD
	limits_status->last_trigger = mavlink_msg_limits_status_get_last_trigger(msg);
	limits_status->last_action = mavlink_msg_limits_status_get_last_action(msg);
	limits_status->last_recovery = mavlink_msg_limits_status_get_last_recovery(msg);
	limits_status->last_clear = mavlink_msg_limits_status_get_last_clear(msg);
	limits_status->breach_count = mavlink_msg_limits_status_get_breach_count(msg);
	limits_status->limits_state = mavlink_msg_limits_status_get_limits_state(msg);
	limits_status->mods_enabled = mavlink_msg_limits_status_get_mods_enabled(msg);
	limits_status->mods_required = mavlink_msg_limits_status_get_mods_required(msg);
	limits_status->mods_triggered = mavlink_msg_limits_status_get_mods_triggered(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_LIMITS_STATUS_LEN? msg->len : MAVLINK_MSG_ID_LIMITS_STATUS_LEN;
        memset(limits_status, 0, MAVLINK_MSG_ID_LIMITS_STATUS_LEN);
	memcpy(limits_status, _MAV_PAYLOAD(msg), len);
=======
    limits_status->last_trigger = mavlink_msg_limits_status_get_last_trigger(msg);
    limits_status->last_action = mavlink_msg_limits_status_get_last_action(msg);
    limits_status->last_recovery = mavlink_msg_limits_status_get_last_recovery(msg);
    limits_status->last_clear = mavlink_msg_limits_status_get_last_clear(msg);
    limits_status->breach_count = mavlink_msg_limits_status_get_breach_count(msg);
    limits_status->limits_state = mavlink_msg_limits_status_get_limits_state(msg);
    limits_status->mods_enabled = mavlink_msg_limits_status_get_mods_enabled(msg);
    limits_status->mods_required = mavlink_msg_limits_status_get_mods_required(msg);
    limits_status->mods_triggered = mavlink_msg_limits_status_get_mods_triggered(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_LIMITS_STATUS_LEN? msg->len : MAVLINK_MSG_ID_LIMITS_STATUS_LEN;
        memset(limits_status, 0, MAVLINK_MSG_ID_LIMITS_STATUS_LEN);
    memcpy(limits_status, _MAV_PAYLOAD(msg), len);
>>>>>>> 31e07fdfff352ae5ce4c37855956cc51d0f48012
#endif
}
