/***************************************************************************//**
 * @file sl_wfx_general_error_api.h
 * @brief This file contains the error ids for WLAN general API
 *
 * @copyright Copyright 2015 Silicon Laboratories, Inc. http://www.silabs.com
 ******************************************************************************/

#ifndef _SL_WFX_GENERAL_ERROR_API_H_
#define _SL_WFX_GENERAL_ERROR_API_H_

/**********************************************************************/
/*                  Assert Error Codes                                */
/**********************************************************************/

/**
 * @addtogroup GENERAL_API
 * @{
 *
 * @addtogroup ERROR_IDS
 * @{
 */

/**
 * @brief specifies the type of error reported by the indication message sl_wfx_error_ind_body_t
 *
 * */
typedef enum sl_wfx_error_e {
  SL_WFX_ERROR_FIRMWARE_ROLLBACK                 = 0x0,    ///<Firmware rollback error, no data returned
  SL_WFX_ERROR_DEPRECATED_0                      = 0x1,    ///<Not used anymore
  SL_WFX_ERROR_OUTDATED_SESSION_KEY              = 0x2,    ///<SecureLink Session key is outdated, 4 bytes returned (nonce counter)
  SL_WFX_ERROR_INVALID_SESSION_KEY               = 0x3,    ///<SecureLink Session key is invalid, 0 or 4 bytes returned
  SL_WFX_ERROR_OOR_VOLTAGE                       = 0x4,    ///<Out-of-range power supply voltage detected, no data returned
  SL_WFX_ERROR_PDS_VERSION                       = 0x5,    ///<Wrong PDS version detected, no data returned
  SL_WFX_ERROR_OOR_TEMPERATURE                   = 0x6,    ///<Out-of-range temperature, no data returned
  SL_WFX_ERROR_REQ_DURING_KEY_EXCHANGE           = 0x7,    ///<Requests from Host are forbidden until the end of key exchange (Host should wait for the associated indication)
  SL_WFX_ERROR_MULTI_TX_CNF_SECURELINK           = 0x8,    ///<'Multi TX conf' feature is not supported in SecureLink mode
  SL_WFX_ERROR_SECURELINK_OVERFLOW               = 0x9,    ///<HT SecureLink traffic is producing an internal overflow
  SL_WFX_ERROR_SECURELINK_DECRYPTION             = 0xa,    ///<An error occured during message decryption (can be a counter mismatch or wrong CCM tag)
  SL_WFX_ERROR_SECURELINK_WRONG_ENCRYPTION_STATE = 0xb,    ///< Encryption state of the received message doesn't match the SecureLink bitmap
  SL_WFX_SPI_OR_SDIO_FREQ_TOO_LOW                = 0xc,    ///<SPI or SDIO bus clock is too slow (<1kHz)
  SL_WFX_ERROR_DEPRECATED_1                      = 0xd,    ///<Not used anymore
  SL_WFX_HIF_MESSAGE_LENGTH_TOO_LARGE            = 0xe,    ///<HIF message length bigger than maximum Hif buffer size. Max is 1616 bytes. Param: message length
  SL_WFX_HIF_BUS_ERROR                           = 0xf,    ///<HIF HW has reported an error. Param: status_reg
  SL_WFX_PDS_TESTFEATURE_MODE_ERROR              = 0x10    ///<unknown TestFeatureMode during test feature init */
} sl_wfx_error_t;

/**
 * @}
 *
 * @}
 */

#endif /* _SL_WFX_GENERAL_ERROR_API_H_ */
