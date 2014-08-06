// MESSAGE COMPACT_STATE PACKING

#define MAVLINK_MSG_ID_COMPACT_STATE 190

typedef struct __mavlink_compact_state_t
{
 uint32_t time_boot_ms; ///< Timestamp of the component clock since boot time in milliseconds.
 int32_t q1; ///< Quaternion component 1, w (2^30 in null-rotation)
 int32_t q2; ///< Quaternion component 2, x (0 in null-rotation)
 int32_t q3; ///< Quaternion component 3, y (0 in null-rotation)
 int32_t q4; ///< Quaternion component 4, z (0 in null-rotation)
 int32_t x; ///< X Position in mm
 int32_t y; ///< Y Position in mm
 int32_t z; ///< Z Position in mm
 int32_t vx; ///< X Speed mm/s
 int32_t vy; ///< Y Speed mm/s
 int32_t vz; ///< Z Speed mm/s
 int32_t omegaZ; ///< Rotation rate deg/s*1000
 int32_t airspeed; ///< Current airspeed in mm/s
} mavlink_compact_state_t;

#define MAVLINK_MSG_ID_COMPACT_STATE_LEN 52
#define MAVLINK_MSG_ID_190_LEN 52

#define MAVLINK_MSG_ID_COMPACT_STATE_CRC 54
#define MAVLINK_MSG_ID_190_CRC 54



#define MAVLINK_MESSAGE_INFO_COMPACT_STATE { \
	"COMPACT_STATE", \
	13, \
	{  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_compact_state_t, time_boot_ms) }, \
         { "q1", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_compact_state_t, q1) }, \
         { "q2", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_compact_state_t, q2) }, \
         { "q3", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_compact_state_t, q3) }, \
         { "q4", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_compact_state_t, q4) }, \
         { "x", NULL, MAVLINK_TYPE_INT32_T, 0, 20, offsetof(mavlink_compact_state_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_INT32_T, 0, 24, offsetof(mavlink_compact_state_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_INT32_T, 0, 28, offsetof(mavlink_compact_state_t, z) }, \
         { "vx", NULL, MAVLINK_TYPE_INT32_T, 0, 32, offsetof(mavlink_compact_state_t, vx) }, \
         { "vy", NULL, MAVLINK_TYPE_INT32_T, 0, 36, offsetof(mavlink_compact_state_t, vy) }, \
         { "vz", NULL, MAVLINK_TYPE_INT32_T, 0, 40, offsetof(mavlink_compact_state_t, vz) }, \
         { "omegaZ", NULL, MAVLINK_TYPE_INT32_T, 0, 44, offsetof(mavlink_compact_state_t, omegaZ) }, \
         { "airspeed", NULL, MAVLINK_TYPE_INT32_T, 0, 48, offsetof(mavlink_compact_state_t, airspeed) }, \
         } \
}


/**
 * @brief Pack a compact_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms Timestamp of the component clock since boot time in milliseconds.
 * @param q1 Quaternion component 1, w (2^30 in null-rotation)
 * @param q2 Quaternion component 2, x (0 in null-rotation)
 * @param q3 Quaternion component 3, y (0 in null-rotation)
 * @param q4 Quaternion component 4, z (0 in null-rotation)
 * @param x X Position in mm
 * @param y Y Position in mm
 * @param z Z Position in mm
 * @param vx X Speed mm/s
 * @param vy Y Speed mm/s
 * @param vz Z Speed mm/s
 * @param omegaZ Rotation rate deg/s*1000
 * @param airspeed Current airspeed in mm/s
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_compact_state_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint32_t time_boot_ms, int32_t q1, int32_t q2, int32_t q3, int32_t q4, int32_t x, int32_t y, int32_t z, int32_t vx, int32_t vy, int32_t vz, int32_t omegaZ, int32_t airspeed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_COMPACT_STATE_LEN];
	_mav_put_uint32_t(buf, 0, time_boot_ms);
	_mav_put_int32_t(buf, 4, q1);
	_mav_put_int32_t(buf, 8, q2);
	_mav_put_int32_t(buf, 12, q3);
	_mav_put_int32_t(buf, 16, q4);
	_mav_put_int32_t(buf, 20, x);
	_mav_put_int32_t(buf, 24, y);
	_mav_put_int32_t(buf, 28, z);
	_mav_put_int32_t(buf, 32, vx);
	_mav_put_int32_t(buf, 36, vy);
	_mav_put_int32_t(buf, 40, vz);
	_mav_put_int32_t(buf, 44, omegaZ);
	_mav_put_int32_t(buf, 48, airspeed);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_COMPACT_STATE_LEN);
#else
	mavlink_compact_state_t packet;
	packet.time_boot_ms = time_boot_ms;
	packet.q1 = q1;
	packet.q2 = q2;
	packet.q3 = q3;
	packet.q4 = q4;
	packet.x = x;
	packet.y = y;
	packet.z = z;
	packet.vx = vx;
	packet.vy = vy;
	packet.vz = vz;
	packet.omegaZ = omegaZ;
	packet.airspeed = airspeed;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_COMPACT_STATE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_COMPACT_STATE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_COMPACT_STATE_LEN, MAVLINK_MSG_ID_COMPACT_STATE_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_COMPACT_STATE_LEN);
#endif
}

/**
 * @brief Pack a compact_state message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms Timestamp of the component clock since boot time in milliseconds.
 * @param q1 Quaternion component 1, w (2^30 in null-rotation)
 * @param q2 Quaternion component 2, x (0 in null-rotation)
 * @param q3 Quaternion component 3, y (0 in null-rotation)
 * @param q4 Quaternion component 4, z (0 in null-rotation)
 * @param x X Position in mm
 * @param y Y Position in mm
 * @param z Z Position in mm
 * @param vx X Speed mm/s
 * @param vy Y Speed mm/s
 * @param vz Z Speed mm/s
 * @param omegaZ Rotation rate deg/s*1000
 * @param airspeed Current airspeed in mm/s
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_compact_state_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint32_t time_boot_ms,int32_t q1,int32_t q2,int32_t q3,int32_t q4,int32_t x,int32_t y,int32_t z,int32_t vx,int32_t vy,int32_t vz,int32_t omegaZ,int32_t airspeed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_COMPACT_STATE_LEN];
	_mav_put_uint32_t(buf, 0, time_boot_ms);
	_mav_put_int32_t(buf, 4, q1);
	_mav_put_int32_t(buf, 8, q2);
	_mav_put_int32_t(buf, 12, q3);
	_mav_put_int32_t(buf, 16, q4);
	_mav_put_int32_t(buf, 20, x);
	_mav_put_int32_t(buf, 24, y);
	_mav_put_int32_t(buf, 28, z);
	_mav_put_int32_t(buf, 32, vx);
	_mav_put_int32_t(buf, 36, vy);
	_mav_put_int32_t(buf, 40, vz);
	_mav_put_int32_t(buf, 44, omegaZ);
	_mav_put_int32_t(buf, 48, airspeed);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_COMPACT_STATE_LEN);
#else
	mavlink_compact_state_t packet;
	packet.time_boot_ms = time_boot_ms;
	packet.q1 = q1;
	packet.q2 = q2;
	packet.q3 = q3;
	packet.q4 = q4;
	packet.x = x;
	packet.y = y;
	packet.z = z;
	packet.vx = vx;
	packet.vy = vy;
	packet.vz = vz;
	packet.omegaZ = omegaZ;
	packet.airspeed = airspeed;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_COMPACT_STATE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_COMPACT_STATE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_COMPACT_STATE_LEN, MAVLINK_MSG_ID_COMPACT_STATE_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_COMPACT_STATE_LEN);
#endif
}

/**
 * @brief Encode a compact_state struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param compact_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_compact_state_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_compact_state_t* compact_state)
{
	return mavlink_msg_compact_state_pack(system_id, component_id, msg, compact_state->time_boot_ms, compact_state->q1, compact_state->q2, compact_state->q3, compact_state->q4, compact_state->x, compact_state->y, compact_state->z, compact_state->vx, compact_state->vy, compact_state->vz, compact_state->omegaZ, compact_state->airspeed);
}

/**
 * @brief Encode a compact_state struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param compact_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_compact_state_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_compact_state_t* compact_state)
{
	return mavlink_msg_compact_state_pack_chan(system_id, component_id, chan, msg, compact_state->time_boot_ms, compact_state->q1, compact_state->q2, compact_state->q3, compact_state->q4, compact_state->x, compact_state->y, compact_state->z, compact_state->vx, compact_state->vy, compact_state->vz, compact_state->omegaZ, compact_state->airspeed);
}

/**
 * @brief Send a compact_state message
 * @param chan MAVLink channel to send the message
 *
 * @param time_boot_ms Timestamp of the component clock since boot time in milliseconds.
 * @param q1 Quaternion component 1, w (2^30 in null-rotation)
 * @param q2 Quaternion component 2, x (0 in null-rotation)
 * @param q3 Quaternion component 3, y (0 in null-rotation)
 * @param q4 Quaternion component 4, z (0 in null-rotation)
 * @param x X Position in mm
 * @param y Y Position in mm
 * @param z Z Position in mm
 * @param vx X Speed mm/s
 * @param vy Y Speed mm/s
 * @param vz Z Speed mm/s
 * @param omegaZ Rotation rate deg/s*1000
 * @param airspeed Current airspeed in mm/s
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_compact_state_send(mavlink_channel_t chan, uint32_t time_boot_ms, int32_t q1, int32_t q2, int32_t q3, int32_t q4, int32_t x, int32_t y, int32_t z, int32_t vx, int32_t vy, int32_t vz, int32_t omegaZ, int32_t airspeed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_COMPACT_STATE_LEN];
	_mav_put_uint32_t(buf, 0, time_boot_ms);
	_mav_put_int32_t(buf, 4, q1);
	_mav_put_int32_t(buf, 8, q2);
	_mav_put_int32_t(buf, 12, q3);
	_mav_put_int32_t(buf, 16, q4);
	_mav_put_int32_t(buf, 20, x);
	_mav_put_int32_t(buf, 24, y);
	_mav_put_int32_t(buf, 28, z);
	_mav_put_int32_t(buf, 32, vx);
	_mav_put_int32_t(buf, 36, vy);
	_mav_put_int32_t(buf, 40, vz);
	_mav_put_int32_t(buf, 44, omegaZ);
	_mav_put_int32_t(buf, 48, airspeed);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMPACT_STATE, buf, MAVLINK_MSG_ID_COMPACT_STATE_LEN, MAVLINK_MSG_ID_COMPACT_STATE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMPACT_STATE, buf, MAVLINK_MSG_ID_COMPACT_STATE_LEN);
#endif
#else
	mavlink_compact_state_t packet;
	packet.time_boot_ms = time_boot_ms;
	packet.q1 = q1;
	packet.q2 = q2;
	packet.q3 = q3;
	packet.q4 = q4;
	packet.x = x;
	packet.y = y;
	packet.z = z;
	packet.vx = vx;
	packet.vy = vy;
	packet.vz = vz;
	packet.omegaZ = omegaZ;
	packet.airspeed = airspeed;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMPACT_STATE, (const char *)&packet, MAVLINK_MSG_ID_COMPACT_STATE_LEN, MAVLINK_MSG_ID_COMPACT_STATE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMPACT_STATE, (const char *)&packet, MAVLINK_MSG_ID_COMPACT_STATE_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_COMPACT_STATE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_compact_state_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t time_boot_ms, int32_t q1, int32_t q2, int32_t q3, int32_t q4, int32_t x, int32_t y, int32_t z, int32_t vx, int32_t vy, int32_t vz, int32_t omegaZ, int32_t airspeed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint32_t(buf, 0, time_boot_ms);
	_mav_put_int32_t(buf, 4, q1);
	_mav_put_int32_t(buf, 8, q2);
	_mav_put_int32_t(buf, 12, q3);
	_mav_put_int32_t(buf, 16, q4);
	_mav_put_int32_t(buf, 20, x);
	_mav_put_int32_t(buf, 24, y);
	_mav_put_int32_t(buf, 28, z);
	_mav_put_int32_t(buf, 32, vx);
	_mav_put_int32_t(buf, 36, vy);
	_mav_put_int32_t(buf, 40, vz);
	_mav_put_int32_t(buf, 44, omegaZ);
	_mav_put_int32_t(buf, 48, airspeed);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMPACT_STATE, buf, MAVLINK_MSG_ID_COMPACT_STATE_LEN, MAVLINK_MSG_ID_COMPACT_STATE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMPACT_STATE, buf, MAVLINK_MSG_ID_COMPACT_STATE_LEN);
#endif
#else
	mavlink_compact_state_t *packet = (mavlink_compact_state_t *)msgbuf;
	packet->time_boot_ms = time_boot_ms;
	packet->q1 = q1;
	packet->q2 = q2;
	packet->q3 = q3;
	packet->q4 = q4;
	packet->x = x;
	packet->y = y;
	packet->z = z;
	packet->vx = vx;
	packet->vy = vy;
	packet->vz = vz;
	packet->omegaZ = omegaZ;
	packet->airspeed = airspeed;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMPACT_STATE, (const char *)packet, MAVLINK_MSG_ID_COMPACT_STATE_LEN, MAVLINK_MSG_ID_COMPACT_STATE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMPACT_STATE, (const char *)packet, MAVLINK_MSG_ID_COMPACT_STATE_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE COMPACT_STATE UNPACKING


/**
 * @brief Get field time_boot_ms from compact_state message
 *
 * @return Timestamp of the component clock since boot time in milliseconds.
 */
static inline uint32_t mavlink_msg_compact_state_get_time_boot_ms(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field q1 from compact_state message
 *
 * @return Quaternion component 1, w (2^30 in null-rotation)
 */
static inline int32_t mavlink_msg_compact_state_get_q1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field q2 from compact_state message
 *
 * @return Quaternion component 2, x (0 in null-rotation)
 */
static inline int32_t mavlink_msg_compact_state_get_q2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field q3 from compact_state message
 *
 * @return Quaternion component 3, y (0 in null-rotation)
 */
static inline int32_t mavlink_msg_compact_state_get_q3(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field q4 from compact_state message
 *
 * @return Quaternion component 4, z (0 in null-rotation)
 */
static inline int32_t mavlink_msg_compact_state_get_q4(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  16);
}

/**
 * @brief Get field x from compact_state message
 *
 * @return X Position in mm
 */
static inline int32_t mavlink_msg_compact_state_get_x(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  20);
}

/**
 * @brief Get field y from compact_state message
 *
 * @return Y Position in mm
 */
static inline int32_t mavlink_msg_compact_state_get_y(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  24);
}

/**
 * @brief Get field z from compact_state message
 *
 * @return Z Position in mm
 */
static inline int32_t mavlink_msg_compact_state_get_z(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  28);
}

/**
 * @brief Get field vx from compact_state message
 *
 * @return X Speed mm/s
 */
static inline int32_t mavlink_msg_compact_state_get_vx(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  32);
}

/**
 * @brief Get field vy from compact_state message
 *
 * @return Y Speed mm/s
 */
static inline int32_t mavlink_msg_compact_state_get_vy(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  36);
}

/**
 * @brief Get field vz from compact_state message
 *
 * @return Z Speed mm/s
 */
static inline int32_t mavlink_msg_compact_state_get_vz(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  40);
}

/**
 * @brief Get field omegaZ from compact_state message
 *
 * @return Rotation rate deg/s*1000
 */
static inline int32_t mavlink_msg_compact_state_get_omegaZ(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  44);
}

/**
 * @brief Get field airspeed from compact_state message
 *
 * @return Current airspeed in mm/s
 */
static inline int32_t mavlink_msg_compact_state_get_airspeed(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  48);
}

/**
 * @brief Decode a compact_state message into a struct
 *
 * @param msg The message to decode
 * @param compact_state C-struct to decode the message contents into
 */
static inline void mavlink_msg_compact_state_decode(const mavlink_message_t* msg, mavlink_compact_state_t* compact_state)
{
#if MAVLINK_NEED_BYTE_SWAP
	compact_state->time_boot_ms = mavlink_msg_compact_state_get_time_boot_ms(msg);
	compact_state->q1 = mavlink_msg_compact_state_get_q1(msg);
	compact_state->q2 = mavlink_msg_compact_state_get_q2(msg);
	compact_state->q3 = mavlink_msg_compact_state_get_q3(msg);
	compact_state->q4 = mavlink_msg_compact_state_get_q4(msg);
	compact_state->x = mavlink_msg_compact_state_get_x(msg);
	compact_state->y = mavlink_msg_compact_state_get_y(msg);
	compact_state->z = mavlink_msg_compact_state_get_z(msg);
	compact_state->vx = mavlink_msg_compact_state_get_vx(msg);
	compact_state->vy = mavlink_msg_compact_state_get_vy(msg);
	compact_state->vz = mavlink_msg_compact_state_get_vz(msg);
	compact_state->omegaZ = mavlink_msg_compact_state_get_omegaZ(msg);
	compact_state->airspeed = mavlink_msg_compact_state_get_airspeed(msg);
#else
	memcpy(compact_state, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_COMPACT_STATE_LEN);
#endif
}
