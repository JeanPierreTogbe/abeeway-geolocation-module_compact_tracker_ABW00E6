/**
  ******************************************************************************
  * @file    bas.h
  * @author  MCD Application Team
  * @brief   Header for bas.c module
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2018-2021 STMicroelectronics.
  * All rights reserved.
  *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BAS_H
#define __BAS_H

#ifdef __cplusplus
extern "C" 
{
#endif

/* Includes ------------------------------------------------------------------*/


/*!
 * \defgroup BAS Battery service
 *
 * \addtogroup BAS
 * @{
 */

/* Exported types ------------------------------------------------------------*/
/*!
 * \enum BAS_Opcode_Notification_evt_t
 *
 * \brief Battery service event
 */

typedef enum {
	BAS_LEVEL_NOT_ENABLED_EVT,     //!< Battery level notification enabled event
	BAS_LEVEL_NOT_DISABLED_EVT,    //!< Battery level notification disabled event
	BAS_POWER_NOT_ENABLED_EVT,     //!< Battery power notification enabled event
	BAS_POWER_NOT_DISABLED_EVT,    //!< Battery power notification disabled event
	BAS_LEVEL_READ_EVT,            //!< Battery level read event
	BAS_POWER_READ_EVT             //!< Battery power read event
} BAS_Opcode_Notification_evt_t;

/*!
 * \struct BAS_Notification_evt_t
 *
 * \brief Battery service event struct
 */
typedef struct {
	BAS_Opcode_Notification_evt_t  BAS_Evt_Opcode;  //!< BAS notification event code
} BAS_Notification_evt_t;


/* Exported constants --------------------------------------------------------*/
/* External variables --------------------------------------------------------*/
/* Exported macros -----------------------------------------------------------*/


/* Exported functions ------------------------------------------------------- */

/*!
 * \fn tBleStatus BAS_Init(void)
 *
 * \brief Battery service Initialization
 *
 * \return tBleStatus status
 */
tBleStatus BAS_Init(void);

/*!
 * \fn tBleStatus BAS_Update_Char(uint16_t UUID, uint8_t *pPayload)
 *
 * \brief Update the data of the characteristic UUID with pPayload data
 *
 * \param UUID battery characteristic to update
 *
 * \param pPayload data to update
 *
 * \return tBleStatus status
 */
tBleStatus BAS_Update_Char(uint16_t UUID, uint8_t *pPayload);

/*!
 * \fn void BAS_Notification(BAS_Notification_evt_t * pNotification)
 *
 * \brief Battery service notification function
 *
 * \param pNotification notification event
 */
void BAS_Notification(BAS_Notification_evt_t * pNotification);

/*! @}*/
#ifdef __cplusplus
}
#endif

#endif /*__BAS_H */


