/*!
 * \file aos_ble_services.h
 *
 * \brief BLE services related API
 *
 * \copyright 2022, Abeeway (www.abeeway.com). All Rights Reserved.
 *
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#pragma once



#ifdef __cplusplus
extern "C" {
#endif

#include "stdint.h"
#include "aos_common.h"
#include "aos_ble_common.h"
/*!
 * \defgroup aos_ble_services BLE core service
 *
 * \addtogroup aos_ble_services
 * @{
 */

/* Exported macros -----------------------------------------------------------*/
#define DISAPP_MANUFACTURER_NAME              "MURATA"    //!< Device Manufacturer name
#define DISAPP_MODEL_NUMBER                   "Module"    //!< Device model name
#define DISAPP_HARDWARE_REVISION_NUMBER       "1.0"       //!< Device hardware revision number
#define DISAPP_FIRMWARE_REVISION_NUMBER       "1.0"       //!< Device BLE firmware version
#define DISAPP_OUI                            0x123456    //!< Device system ID information part 1
#define DISAPP_MANUFACTURER_ID                0x9ABCDE    //!< Device system ID information part 2

/* Exported functions ------------------------------------------------------- */

/*!
 * \fn void DISAPP_Init(void)
 *
 * \brief Initialize Device Information Service
 *
 * \param app_info provide device information data characteristic data
 *
 */
void DISAPP_Init(aos_ble_app_data_t *app_info);

/*!
 * \fn void IASAPP_Init(void)
 *
 * \brief Initialize Immediate Alert Service characteristic data
 *
 */
void IASAPP_Init(void);

/*!
 * \fn void LLSAPP_Init(void)
 *
 * \brief Initialize Link Loss Service characteristic data
 *
 */
void LLSAPP_Init(void);

/*!
 * \fn void TPSAPP_Init(void)
 *
 * \brief Initialize Tx Power Service characteristic data
 *
 * \param tx_power BLE tx power to initialize
 *
 */
void TPSAPP_Init(int8_t tx_power);

/*!
 * \fn void BASAPP_Init(void)
 *
 * \brief Initialize Battery Service characteristic data
 *
 */
void BASAPP_Init(void);

/*!
 * \fn void ESSAPP_Init(void)
 *
 * \brief Initialize Environmental Sensing Service characteristic data
 *
 */
void ESSAPP_Init(void);


/*! @}*/
#ifdef __cplusplus
}
#endif
