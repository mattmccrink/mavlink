<<<<<<< HEAD
=======
#pragma once
>>>>>>> 31e07fdfff352ae5ce4c37855956cc51d0f48012
// MESSAGE AUTH_KEY PACKING

#define MAVLINK_MSG_ID_AUTH_KEY 7

MAVPACKED(
typedef struct __mavlink_auth_key_t {
 char key[32]; /*< key*/
}) mavlink_auth_key_t;

#define MAVLINK_MSG_ID_AUTH_KEY_LEN 32
#define MAVLINK_MSG_ID_AUTH_KEY_MIN_LEN 32
#define MAVLINK_MSG_ID_7_LEN 32
#define MAVLINK_MSG_ID_7_MIN_LEN 32

#define MAVLINK_MSG_ID_AUTH_KEY_CRC 119
#define MAVLINK_MSG_ID_7_CRC 119

#define MAVLINK_MSG_AUTH_KEY_FIELD_KEY_LEN 32

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_AUTH_KEY { \
<<<<<<< HEAD
	7, \
	"AUTH_KEY", \
	1, \
	{  { "key", NULL, MAVLINK_TYPE_CHAR, 32, 0, offsetof(mavlink_auth_key_t, key) }, \
=======
    7, \
    "AUTH_KEY", \
    1, \
    {  { "key", NULL, MAVLINK_TYPE_CHAR, 32, 0, offsetof(mavlink_auth_key_t, key) }, \
>>>>>>> 31e07fdfff352ae5ce4c37855956cc51d0f48012
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_AUTH_KEY { \
<<<<<<< HEAD
	"AUTH_KEY", \
	1, \
	{  { "key", NULL, MAVLINK_TYPE_CHAR, 32, 0, offsetof(mavlink_auth_key_t, key) }, \
=======
    "AUTH_KEY", \
    1, \
    {  { "key", NULL, MAVLINK_TYPE_CHAR, 32, 0, offsetof(mavlink_auth_key_t, key) }, \
>>>>>>> 31e07fdfff352ae5ce4c37855956cc51d0f48012
         } \
}
#endif

/**
 * @brief Pack a auth_key message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param key key
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_auth_key_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
<<<<<<< HEAD
						       const char *key)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_AUTH_KEY_LEN];

	_mav_put_char_array(buf, 0, key, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AUTH_KEY_LEN);
#else
	mavlink_auth_key_t packet;

	mav_array_memcpy(packet.key, key, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AUTH_KEY_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_AUTH_KEY;
=======
                               const char *key)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AUTH_KEY_LEN];

    _mav_put_char_array(buf, 0, key, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AUTH_KEY_LEN);
#else
    mavlink_auth_key_t packet;

    mav_array_memcpy(packet.key, key, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AUTH_KEY_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AUTH_KEY;
>>>>>>> 31e07fdfff352ae5ce4c37855956cc51d0f48012
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_AUTH_KEY_MIN_LEN, MAVLINK_MSG_ID_AUTH_KEY_LEN, MAVLINK_MSG_ID_AUTH_KEY_CRC);
}

/**
 * @brief Pack a auth_key message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param key key
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_auth_key_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
<<<<<<< HEAD
							   mavlink_message_t* msg,
						           const char *key)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_AUTH_KEY_LEN];

	_mav_put_char_array(buf, 0, key, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AUTH_KEY_LEN);
#else
	mavlink_auth_key_t packet;

	mav_array_memcpy(packet.key, key, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AUTH_KEY_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_AUTH_KEY;
=======
                               mavlink_message_t* msg,
                                   const char *key)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AUTH_KEY_LEN];

    _mav_put_char_array(buf, 0, key, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AUTH_KEY_LEN);
#else
    mavlink_auth_key_t packet;

    mav_array_memcpy(packet.key, key, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AUTH_KEY_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AUTH_KEY;
>>>>>>> 31e07fdfff352ae5ce4c37855956cc51d0f48012
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_AUTH_KEY_MIN_LEN, MAVLINK_MSG_ID_AUTH_KEY_LEN, MAVLINK_MSG_ID_AUTH_KEY_CRC);
}

/**
 * @brief Encode a auth_key struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param auth_key C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_auth_key_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_auth_key_t* auth_key)
{
<<<<<<< HEAD
	return mavlink_msg_auth_key_pack(system_id, component_id, msg, auth_key->key);
=======
    return mavlink_msg_auth_key_pack(system_id, component_id, msg, auth_key->key);
>>>>>>> 31e07fdfff352ae5ce4c37855956cc51d0f48012
}

/**
 * @brief Encode a auth_key struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param auth_key C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_auth_key_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_auth_key_t* auth_key)
{
<<<<<<< HEAD
	return mavlink_msg_auth_key_pack_chan(system_id, component_id, chan, msg, auth_key->key);
=======
    return mavlink_msg_auth_key_pack_chan(system_id, component_id, chan, msg, auth_key->key);
>>>>>>> 31e07fdfff352ae5ce4c37855956cc51d0f48012
}

/**
 * @brief Send a auth_key message
 * @param chan MAVLink channel to send the message
 *
 * @param key key
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_auth_key_send(mavlink_channel_t chan, const char *key)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
<<<<<<< HEAD
	char buf[MAVLINK_MSG_ID_AUTH_KEY_LEN];

	_mav_put_char_array(buf, 0, key, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUTH_KEY, buf, MAVLINK_MSG_ID_AUTH_KEY_MIN_LEN, MAVLINK_MSG_ID_AUTH_KEY_LEN, MAVLINK_MSG_ID_AUTH_KEY_CRC);
#else
	mavlink_auth_key_t packet;

	mav_array_memcpy(packet.key, key, sizeof(char)*32);
=======
    char buf[MAVLINK_MSG_ID_AUTH_KEY_LEN];

    _mav_put_char_array(buf, 0, key, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUTH_KEY, buf, MAVLINK_MSG_ID_AUTH_KEY_MIN_LEN, MAVLINK_MSG_ID_AUTH_KEY_LEN, MAVLINK_MSG_ID_AUTH_KEY_CRC);
#else
    mavlink_auth_key_t packet;

    mav_array_memcpy(packet.key, key, sizeof(char)*32);
>>>>>>> 31e07fdfff352ae5ce4c37855956cc51d0f48012
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUTH_KEY, (const char *)&packet, MAVLINK_MSG_ID_AUTH_KEY_MIN_LEN, MAVLINK_MSG_ID_AUTH_KEY_LEN, MAVLINK_MSG_ID_AUTH_KEY_CRC);
#endif
}

/**
 * @brief Send a auth_key message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_auth_key_send_struct(mavlink_channel_t chan, const mavlink_auth_key_t* auth_key)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_auth_key_send(chan, auth_key->key);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUTH_KEY, (const char *)auth_key, MAVLINK_MSG_ID_AUTH_KEY_MIN_LEN, MAVLINK_MSG_ID_AUTH_KEY_LEN, MAVLINK_MSG_ID_AUTH_KEY_CRC);
#endif
}

#if MAVLINK_MSG_ID_AUTH_KEY_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_auth_key_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const char *key)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
<<<<<<< HEAD
	char *buf = (char *)msgbuf;

	_mav_put_char_array(buf, 0, key, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUTH_KEY, buf, MAVLINK_MSG_ID_AUTH_KEY_MIN_LEN, MAVLINK_MSG_ID_AUTH_KEY_LEN, MAVLINK_MSG_ID_AUTH_KEY_CRC);
#else
	mavlink_auth_key_t *packet = (mavlink_auth_key_t *)msgbuf;

	mav_array_memcpy(packet->key, key, sizeof(char)*32);
=======
    char *buf = (char *)msgbuf;

    _mav_put_char_array(buf, 0, key, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUTH_KEY, buf, MAVLINK_MSG_ID_AUTH_KEY_MIN_LEN, MAVLINK_MSG_ID_AUTH_KEY_LEN, MAVLINK_MSG_ID_AUTH_KEY_CRC);
#else
    mavlink_auth_key_t *packet = (mavlink_auth_key_t *)msgbuf;

    mav_array_memcpy(packet->key, key, sizeof(char)*32);
>>>>>>> 31e07fdfff352ae5ce4c37855956cc51d0f48012
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUTH_KEY, (const char *)packet, MAVLINK_MSG_ID_AUTH_KEY_MIN_LEN, MAVLINK_MSG_ID_AUTH_KEY_LEN, MAVLINK_MSG_ID_AUTH_KEY_CRC);
#endif
}
#endif

#endif

// MESSAGE AUTH_KEY UNPACKING


/**
 * @brief Get field key from auth_key message
 *
 * @return key
 */
static inline uint16_t mavlink_msg_auth_key_get_key(const mavlink_message_t* msg, char *key)
{
<<<<<<< HEAD
	return _MAV_RETURN_char_array(msg, key, 32,  0);
=======
    return _MAV_RETURN_char_array(msg, key, 32,  0);
>>>>>>> 31e07fdfff352ae5ce4c37855956cc51d0f48012
}

/**
 * @brief Decode a auth_key message into a struct
 *
 * @param msg The message to decode
 * @param auth_key C-struct to decode the message contents into
 */
static inline void mavlink_msg_auth_key_decode(const mavlink_message_t* msg, mavlink_auth_key_t* auth_key)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
<<<<<<< HEAD
	mavlink_msg_auth_key_get_key(msg, auth_key->key);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_AUTH_KEY_LEN? msg->len : MAVLINK_MSG_ID_AUTH_KEY_LEN;
        memset(auth_key, 0, MAVLINK_MSG_ID_AUTH_KEY_LEN);
	memcpy(auth_key, _MAV_PAYLOAD(msg), len);
=======
    mavlink_msg_auth_key_get_key(msg, auth_key->key);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_AUTH_KEY_LEN? msg->len : MAVLINK_MSG_ID_AUTH_KEY_LEN;
        memset(auth_key, 0, MAVLINK_MSG_ID_AUTH_KEY_LEN);
    memcpy(auth_key, _MAV_PAYLOAD(msg), len);
>>>>>>> 31e07fdfff352ae5ce4c37855956cc51d0f48012
#endif
}
