/** @file
<<<<<<< HEAD
 *	@brief MAVLink comm protocol built from Propeller_pilot.xml
 *	@see http://mavlink.org
 */
#ifndef MAVLINK_H
#define MAVLINK_H

=======
 *  @brief MAVLink comm protocol built from Propeller_pilot.xml
 *  @see http://mavlink.org
 */
#pragma once
#ifndef MAVLINK_H
#define MAVLINK_H

#define MAVLINK_PRIMARY_XML_IDX 0

>>>>>>> 31e07fdfff352ae5ce4c37855956cc51d0f48012
#ifndef MAVLINK_STX
#define MAVLINK_STX 254
#endif

#ifndef MAVLINK_ENDIAN
#define MAVLINK_ENDIAN MAVLINK_LITTLE_ENDIAN
#endif

#ifndef MAVLINK_ALIGNED_FIELDS
#define MAVLINK_ALIGNED_FIELDS 1
#endif

#ifndef MAVLINK_CRC_EXTRA
#define MAVLINK_CRC_EXTRA 1
#endif

#ifndef MAVLINK_COMMAND_24BIT
#define MAVLINK_COMMAND_24BIT 0
#endif

#include "version.h"
#include "Propeller_pilot.h"

#endif // MAVLINK_H
