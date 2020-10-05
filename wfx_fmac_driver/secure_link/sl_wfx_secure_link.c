/**************************************************************************//**
 * Copyright 2018, Silicon Laboratories Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

/*
 *  All the routines the underlying platform needs to define to port wfx_driver
 */

#include "sl_wfx_secure_link.h"

#ifdef SL_WFX_USE_SECURE_LINK
/******************************************************
*                      Macros
******************************************************/

/******************************************************
*                    Constants
******************************************************/

/******************************************************
*                   Enumerations
******************************************************/

/******************************************************
*                 Type Definitions
******************************************************/

/******************************************************
*                    Structures
******************************************************/

/******************************************************
*               Function Declarations
******************************************************/

/******************************************************
*               Variable Definitions
******************************************************/

extern sl_wfx_context_t *sl_wfx_context;

/******************************************************
*               Function Definitions
******************************************************/

/**************************************************************************//**
 * @addtogroup DRIVER_API
 * @{
 *****************************************************************************/

/**************************************************************************//**
 * @brief Initializes the whole SecureLink bitmap to disable encryption for all
 * request IDs
 *
 * @param bitmap is the bitmap that must be updated
 *
 * @note It is advised to apply these changes to a transitory bitmap. Its data will be copied
 * to the sl_wfx_context bitmap once the sl_wfx_send_secure_link_encryption_bitmap() has
 * completed successfully.
 *****************************************************************************/
void sl_wfx_init_secure_link_encryption_bitmap(uint8_t *bitmap)
{
  memset(bitmap, 0, SL_WFX_SECURE_LINK_ENCRYPTION_BITMAP_SIZE);
}

/**************************************************************************//**
 * @brief Get the encryption state of a request ID
 *
 * @param request_id to check in the bitmap
 * @returns Returns SL_WFX_SECURE_LINK_ENCRYPTION_REQUIRED if the request should be encrypted,
 * SL_WFX_SECURE_LINK_ENCRYPTION_NOT_REQUIRED otherwise
 *****************************************************************************/
uint8_t sl_wfx_secure_link_encryption_required_get(uint8_t request_id)
{
  uint8_t result;

  if ((sl_wfx_context->encryption_bitmap[request_id >> 3] & (1 << (request_id & 0x07) ) ) > 0) {
    result = SL_WFX_SECURE_LINK_ENCRYPTION_REQUIRED;
  } else {
    result = SL_WFX_SECURE_LINK_ENCRYPTION_NOT_REQUIRED;
  }

  return result;
}

/**************************************************************************//**
 * @addtogroup GENERAL_DRIVER_API
 * @{
 *****************************************************************************/

/**************************************************************************//**
 * @brief SecureLink Set MAC Key
 *
 * @param sl_mac_key: MAC key to write on wf200
 * @param destination: Memory section where it should be written
 *   @arg         SL_MAC_KEY_DEST_OTP
 *   @arg         SL_MAC_KEY_DEST_RAM
 * @returns Returns SL_STATUS_OK if the request has been sent correctly,
 * SL_STATUS_FAIL otherwise
 *****************************************************************************/
sl_status_t sl_wfx_secure_link_set_mac_key(const uint8_t *sl_mac_key, sl_wfx_securelink_mac_key_dest_t destination)
{
  sl_status_t       result;
  sl_wfx_set_securelink_mac_key_req_body_t request;
  sl_wfx_set_securelink_mac_key_cnf_t *reply = NULL;

  request.otp_or_ram = destination;
  memcpy(request.key_value, sl_mac_key, SL_WFX_KEY_VALUE_SIZE);

  result = sl_wfx_send_command(SL_WFX_SET_SECURELINK_MAC_KEY_REQ_ID, &request, sizeof(request), SL_WFX_STA_INTERFACE, (sl_wfx_generic_confirmation_t **)&reply);
  SL_WFX_ERROR_CHECK(result);

  result = sl_wfx_get_status_code(sl_wfx_htole32(reply->body.status), SL_WFX_SET_SECURELINK_MAC_KEY_REQ_ID);

  error_handler:
  return result;
}

/**************************************************************************//**
 * @brief Exchange SecureLink public keys
 *
 * @param sl_mac_key: MAC key to be used
 * @param sl_host_pub_key: public key of the host
 * @returns Returns SL_STATUS_OK if the request has been sent correctly,
 * SL_STATUS_WIFI_SECURE_LINK_EXCHANGE_FAILED otherwise
 *****************************************************************************/
sl_status_t sl_wfx_secure_link_exchange_keys(const uint8_t *sl_mac_key, uint8_t *sl_host_pub_key)
{
  sl_status_t       result = SL_STATUS_OK;
  sl_wfx_generic_message_t  *request_packet = NULL;
  sl_wfx_securelink_exchange_pub_keys_cnf_t     *response_packet = NULL;
  sl_wfx_securelink_exchange_pub_keys_req_body_t *request = NULL;
  uint32_t          request_length = SL_WFX_ROUND_UP_EVEN(sizeof(sl_wfx_securelink_exchange_pub_keys_req_t));

  result = sl_wfx_allocate_command_buffer(&request_packet, SL_WFX_SECURELINK_EXCHANGE_PUB_KEYS_REQ_ID, SL_WFX_CONTROL_BUFFER, request_length);
  SL_WFX_ERROR_CHECK(result);

  request = (sl_wfx_securelink_exchange_pub_keys_req_body_t *)&request_packet->body;

#ifdef SL_WFX_SLK_CURVE25519
  request->algorithm = sl_wfx_htole32(SECURE_LINK_CURVE25519);
#else
  request->algorithm = sl_wfx_htole32(SECURE_LINK_KDF);
#endif

  result = sl_wfx_host_compute_pub_key(request, sl_mac_key);
  SL_WFX_ERROR_CHECK(result);

  memcpy(sl_host_pub_key, &request->host_pub_key, SL_WFX_HOST_PUB_KEY_SIZE);

  result = sl_wfx_send_request(SL_WFX_SECURELINK_EXCHANGE_PUB_KEYS_REQ_ID, request_packet, request_length);
  SL_WFX_ERROR_CHECK(result);

  result = sl_wfx_host_wait_for_confirmation(SL_WFX_SECURELINK_EXCHANGE_PUB_KEYS_REQ_ID, SL_WFX_DEFAULT_REQUEST_TIMEOUT_MS, (void **)&response_packet);
  SL_WFX_ERROR_CHECK(result);

  result = sl_wfx_get_status_code(sl_wfx_htole32(response_packet->body.status), SL_WFX_SECURELINK_EXCHANGE_PUB_KEYS_REQ_ID);

  error_handler:
  if (request_packet != NULL) {
    sl_wfx_free_command_buffer(request_packet, SL_WFX_SECURELINK_EXCHANGE_PUB_KEYS_REQ_ID, SL_WFX_CONTROL_BUFFER);
  }
  return result;
}

/**************************************************************************//**
 * @brief Renegotiate session key request
 *
 * @returns SL_STATUS_OK if the setting is applied correctly, SL_STATUS_FAIL otherwise
 *****************************************************************************/
sl_status_t sl_wfx_secure_link_renegotiate_session_key(void)
{
  sl_status_t result;
  sl_wfx_securelink_exchange_pub_keys_ind_t *exchange_pub_keys_ind;
  uint8_t sl_host_pub_key[SL_WFX_HOST_PUB_KEY_SIZE];

  sl_wfx_context->secure_link_renegotiation_state = SL_WFX_SECURELINK_RENEGOTIATION_PENDING;
  memset(&sl_wfx_context->secure_link_exchange_ind, 0, sizeof(sl_wfx_securelink_exchange_pub_keys_ind_t));

  result = sl_wfx_secure_link_exchange_keys(sl_wfx_context->secure_link_mac_key, sl_host_pub_key);
  SL_WFX_ERROR_CHECK(result);

  result = sl_wfx_host_setup_waited_event(SL_WFX_SECURELINK_EXCHANGE_PUB_KEYS_IND_ID);
  SL_WFX_ERROR_CHECK(result);

  if (sl_wfx_context->secure_link_exchange_ind.header.length == 0) {
    /* Indication not yet in, wait for it */
    result = sl_wfx_host_wait_for_confirmation(SL_WFX_SECURELINK_EXCHANGE_PUB_KEYS_IND_ID, SL_WFX_DEFAULT_REQUEST_TIMEOUT_MS, (void **)&exchange_pub_keys_ind);
  } else {
    /* Indication already in, fetch it from buffer (can happen with slow bus) */
    exchange_pub_keys_ind = &sl_wfx_context->secure_link_exchange_ind;
    result = SL_STATUS_OK;
  }
  SL_WFX_ERROR_CHECK(result);

  if (sl_wfx_htole32(exchange_pub_keys_ind->body.status) != SL_WFX_PUB_KEY_EXCHANGE_STATUS_SUCCESS) {
    result = SL_STATUS_WIFI_SECURE_LINK_EXCHANGE_FAILED;
    goto error_handler;
  }
  result = sl_wfx_get_status_code(sl_wfx_htole32(exchange_pub_keys_ind->body.status), SL_WFX_SECURELINK_EXCHANGE_PUB_KEYS_IND_ID);
  SL_WFX_ERROR_CHECK(result);

  result = sl_wfx_host_verify_pub_key(exchange_pub_keys_ind, sl_wfx_context->secure_link_mac_key, sl_host_pub_key);
  SL_WFX_ERROR_CHECK(result);

#if (SL_WFX_DEBUG_MASK & SL_WFX_DEBUG_SLK)
  sl_wfx_host_log("--Key renegotiated--\r\n");
#endif

  error_handler:
  sl_wfx_host_free_crypto_context();
  sl_wfx_context->secure_link_renegotiation_state = SL_WFX_SECURELINK_DEFAULT;
  return result;
}

/**************************************************************************//**
 * @brief Modify SecureLink configuration
 *
 * @param encryption_bitmap: Encryption bitmap that must be written to wf200
 * @param disable_session_key_protection: Force the firmware to authorize the use of the same session key
 *  during a complete power cycle, even very long.
 * @note Disabling the session key protection downgrades the link security and is NOT RECOMMENDED.
 * @note The magic word SL_WFX_SESSION_KEY_PROTECTION_DISABLE_MAGIC is used to disable this protection.
 * @returns Returns SL_STATUS_OK if the request has been sent correctly,
 * SL_STATUS_FAIL otherwise
 *
 * @note The bitmap used as a parameter will be copied to the context bitmap if the setting
 * completed successfully.
 *****************************************************************************/
sl_status_t sl_wfx_secure_link_configure(const uint8_t *encryption_bitmap, uint8_t disable_session_key_protection)
{
  sl_status_t result;
  uint8_t     i;
  sl_wfx_securelink_configure_req_body_t request;
  sl_wfx_securelink_configure_cnf_t *reply = NULL;

  memcpy(request.encr_bmp, encryption_bitmap, SL_WFX_ENCR_BMP_SIZE);
  request.disable_session_key_protection = sl_wfx_htole32(disable_session_key_protection);

  result = sl_wfx_send_command(SL_WFX_SECURELINK_CONFIGURE_REQ_ID,
                               &request,
                               sizeof(request),
                               SL_WFX_STA_INTERFACE,
                               (sl_wfx_generic_confirmation_t **)&reply);

  if (result == SL_STATUS_OK) {
    result = sl_wfx_get_status_code(sl_wfx_htole32(reply->body.status), SL_WFX_GET_SIGNAL_STRENGTH_REQ_ID);
    if (result == SL_STATUS_OK) {
      memcpy(sl_wfx_context->encryption_bitmap, reply->body.encr_bmp, SL_WFX_SECURE_LINK_ENCRYPTION_BITMAP_SIZE);
    }
    // Return a warning if one or more bits of the bitmap were not applied by the firmware.
    if (memcmp(request.encr_bmp, reply->body.encr_bmp, SL_WFX_SECURE_LINK_ENCRYPTION_BITMAP_SIZE)) {
      result = SL_STATUS_WIFI_WARNING;
    }
  }

  return result;
}

/** @} end GENERAL_DRIVER_API */

/**************************************************************************//**
 * @brief Quickly set the bitmap to encrypt all requests
 *
 * @param bitmap is the bitmap that must be updated
 *
 * @note WFX firmware automatically adjusts for commands that should never or always be encrypted
 *****************************************************************************/
void sl_wfx_secure_link_bitmap_set_all_encrypted(uint8_t *bitmap)
{
  memset(bitmap, 0xFF, SL_WFX_SECURE_LINK_ENCRYPTION_BITMAP_SIZE);
}

/**************************************************************************//**
 * @brief Add a request ID to the SecureLink bitmap
 *
 * @param bitmap is the bitmap that must be updated
 * @param request_id is id to add to the bitmap
 *
 * @note It is advised to apply these changes to a transitory bitmap. Its data will be copied
 * to the sl_wfx_context bitmap once the sl_wfx_send_secure_link_encryption_bitmap() has
 * completed successfully.
 *****************************************************************************/
void sl_wfx_secure_link_bitmap_add_request_id(uint8_t *bitmap, uint8_t request_id)
{
  bitmap[request_id >> 3] |= (1 << (request_id & 0x07) );
}

/**************************************************************************//**
 * @brief Remove a request ID to the SecureLink bitmap
 *
 * @param bitmap is the bitmap that must be updated
 * @param request_id is id to remove from the bitmap
 *
 * @note It is advised to apply these changes to a transitory bitmap. Its data will be copied
 * to the sl_wfx_context bitmap once the sl_wfx_send_secure_link_encryption_bitmap() has
 * completed successfully.
 *****************************************************************************/
void sl_wfx_secure_link_bitmap_remove_request_id(uint8_t *bitmap, uint8_t request_id)
{
  bitmap[request_id >> 3] &= ~(1 << (request_id & 0x07) );
}

/** @} end DRIVER_API */

#endif // SL_WFX_USE_SECURE_LINK
