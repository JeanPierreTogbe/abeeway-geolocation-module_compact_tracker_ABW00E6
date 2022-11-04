/*!
 * \file aos_ble_common.h
 *
 * \brief common types and const for BLE module
 *
 * \copyright 2022, Abeeway (www.abeeway.com). All Rights Reserved.
 *
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#ifndef BIT
#define BIT(n) (1UL << (n))
#endif

#include "aos_common.h"

/*!
 * \defgroup aos_ble_common BLE core common defines
 *
 * \addtogroup aos_ble_common
 * @{
 */

/* BLE_services_bit_mask_t */

/*!
 * \enum BLE_services_bit_mask_t
 *
 * \brief BLE services bit mask
 */
enum {
	TX_POWER_SERVICE              = BIT(0),       //!< TX power service bit-mask
	DEVICE_INFORMATION_SERVICE    = BIT(1),       //!< Device information service bit-mask
	IMMEDIATE_ALERT_SERVICE       = BIT(2),       //!< Immediate alert service bit-mask
	LINK_LOSS_SERVICE             = BIT(3),       //!< Link loss service bit-mask
	BATTERY_SERVICE               = BIT(4),       //!< Battery service bit-mask
	ENVIRONMENTAL_SENSING_SERVICE = BIT(5),       //!< Environmental sensing service bit-mask
	CUSTOM_1_SERVICE              = BIT(6),       //!< Custom 1 service bit-mask
	CUSTOM_2_SERVICE              = BIT(7),       //!< Custom 2 service bit-mask
	CUSTOM_3_SERVICE              = BIT(8),       //!< Custom 3 service bit-mask
	CUSTOM_4_SERVICE              = BIT(9),       //!< Custom 4 service bit-mask
	CUSTOM_5_SERVICE              = BIT(10),      //!< Custom 5 service bit-mask
	CUSTOM_6_SERVICE              = BIT(11),      //!< Custom 6 service bit-mask
	CUSTOM_7_SERVICE              = BIT(12),      //!< Custom 7 service bit-mask
	CUSTOM_8_SERVICE              = BIT(13),      //!< Custom 8 service bit-mask
	CUSTOM_9_SERVICE              = BIT(14),      //!< Custom 9 service bit-mask
	CUSTOM_10_SERVICE             = BIT(15)       //!< Custom 10 service bit-mask
};

/*!
 * \struct aos_ble_core_fw_version_t
 *
 * \brief BLE stack and FUS versions
 */
typedef struct {
	// Wireless Info
	uint8_t stack_major;
	uint8_t stack_minor;
	uint8_t stack_sub;
	// Fus Info
	uint8_t fus_major;
	uint8_t fus_minor;
	uint8_t fus_sub;
} aos_ble_core_fw_version_t;

/*!
 * \struct aos_ble_app_data_t
 *
 * \brief Application data to send to the BLE to update
 *        characteristic data
 */
typedef struct {
	uint8_t deveui[AOS_PROVISIONING_EUI_SIZE];
	uint32_t app_version;
	aos_ble_core_fw_version_t fw_version;
	uint16_t ble_services_mask;   /* refer to BLE_services_bit_mask_t */
} aos_ble_app_data_t;


/*! @}*/
#ifdef __cplusplus
}
#endif
