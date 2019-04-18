FMAC API	{#sl_wfx_fmac_api}  
============

To interact with the WF200, the host has access to a set of API exposing a FMAC Wi-Fi interface. To find the related driver functions, you can refer to the table below or to the \ref FULL_MAC_API group.

## FMAC API commands
Below is a table listing the FMAC API commands supported by the WF200.
\anchor requests

| Commands                                   | Value | Associated driver function            | Description                                                             |
|--------------------------------------------|-------|---------------------------------------|-------------------------------------------------------------------------|
| SL_WFX_SET_MAC_ADDRESS_REQ_ID              | 0x42  | ::sl_wfx_set_mac_address              | Set a MAC address for each interface                                    |
| SL_WFX_CONNECT_REQ_ID                      | 0x43  | ::sl_wfx_send_join_command            | Connect to a network                                                    |
| SL_WFX_DISCONNECT_REQ_ID                   | 0x44  | ::sl_wfx_send_disconnect_command      | Disconnect from a network                                               |
| SL_WFX_START_AP_REQ_ID                     | 0x45  | ::sl_wfx_start_ap_command             | Start AP mode                                                           |
| SL_WFX_UPDATE_AP_REQ_ID                    | 0x46  | ::sl_wfx_update_ap_command            | Update AP mode parameters                                               |
| SL_WFX_STOP_AP_REQ_ID                      | 0x47  | ::sl_wfx_stop_ap_command              | Stop AP mode                                                            |
| SL_WFX_SEND_FRAME_REQ_ID                   | 0x4a  | ::sl_wfx_send_ethernet_frame          | Send a frame                                                            |
| SL_WFX_START_SCAN_REQ_ID                   | 0x4b  | ::sl_wfx_send_scan_command            | Perform a scan                                                          |
| SL_WFX_STOP_SCAN_REQ_ID                    | 0x4c  | ::sl_wfx_send_stop_scan_command       | Stop an ongoing scan                                                    |
| SL_WFX_GET_SIGNAL_STRENGTH_REQ_ID          | 0x4e  | ::sl_wfx_get_signal_strength          | Get signal strength                                                     |
| SL_WFX_DISCONNECT_AP_CLIENT_REQ_ID         | 0x4f  | ::sl_wfx_disconnect_ap_client_command | Disconnect AP client                                                    |
| SL_WFX_JOIN_IBSS_REQ_ID                    | 0x50  | ::sl_wfx_join_ibss_command            | Join or create an IBSS                                                  |
| SL_WFX_LEAVE_IBSS_REQ_ID                   | 0x51  | ::sl_wfx_leave_ibss_command           | Leave an IBSS                                                           |
| SL_WFX_SET_PM_MODE_REQ_ID                  | 0x52  | ::sl_wfx_set_power_mode               | Set pm mode                                                             |
| SL_WFX_ADD_MULTICAST_ADDR_REQ_ID           | 0x53  | ::sl_wfx_add_multicast_address        | Add multicast address to filter                                         |
| SL_WFX_REMOVE_MULTICAST_ADDR_REQ_ID        | 0x54  | ::sl_wfx_remove_multicast_address     | Remove multicast address to filter                                      |
| SL_WFX_SET_MAX_AP_CLIENT_COUNT_REQ_ID      | 0x55  | ::sl_wfx_set_max_ap_client            | Set client count limitation                                             |
| SL_WFX_SET_MAX_AP_CLIENT_INACTIVITY_REQ_ID | 0x56  | ::sl_wfx_set_max_ap_client_inactivity | Set client inactivity limitation                                        |
| SL_WFX_SET_ROAM_PARAMETERS_REQ_ID          | 0x57  | ::sl_wfx_set_roam_parameters          | Set roam parameters                                                     |
| SL_WFX_SET_TX_RATE_PARAMETERS_REQ_ID       | 0x58  | ::sl_wfx_set_tx_rate_parameters       | Set TX rate parameters                                                  |
| SL_WFX_SET_ARP_IP_ADDRESS_REQ_ID           | 0x59  | ::sl_wfx_set_arp_ip_address           | Active the ARP offloading for the IP address provided                   |
| SL_WFX_SET_NS_IP_ADDRESS_REQ_ID            | 0x5A  | ::sl_wfx_set_ns_ip_address            | Active the Neighbor Solicitation offloading for the IP address provided |
| SL_WFX_SET_BROADCAST_FILTER_REQ_ID         | 0x5B  | ::sl_wfx_set_broadcast_filter         | Active the broadcast filtering                                          |
| SL_WFX_SET_SCAN_PARAMETERS_REQ_ID          | 0x5C  | ::sl_wfx_set_scan_parameters          | Set scan parameters                                                     |
| SL_WFX_SET_UNICAST_FILTER_REQ_ID           | 0x5D  | ::sl_wfx_set_unicast_filter           | Active the unicast filtering                                            |
| SL_WFX_ADD_WHITELIST_ADDR_REQ_ID           | 0x5E  | ::sl_wfx_add_whitelist_address        | Add a MAC address to the whitelist                                      |
| SL_WFX_ADD_BLACKLIST_ADDR_REQ_ID           | 0x5F  | ::sl_wfx_add_blacklist_address        | Add a MAC address to the blacklist                                      |
| SL_WFX_SET_MAX_TX_POWER_REQ_ID             | 0x60  | ::sl_wfx_set_max_tx_power             | Set the max TX output power                                             |
| SL_WFX_GET_MAX_TX_POWER_REQ_ID             | 0x61  | ::sl_wfx_get_max_tx_power             | Get the max TX output power                                             |

For each available command, there is an associated confirmation with the same ID value.

##FMAC API indications
\anchor indications
| Indications                       | Value | Associated struture                  | Description                           |
| --------------------------------- | ----- | ------------------------------------ | ------------------------------------- |
| SL_WFX_CONNECT_IND                | 0xc3  | ::sl_wfx_connect_ind_t               | Connection to a network complete      |
| SL_WFX_DISCONNECT_IND             | 0xc4  | ::sl_wfx_disconnect_ind_t            | Disconnection from a network complete |
| SL_WFX_START_AP_IND               | 0xc5  | ::sl_wfx_start_ap_ind_t              | Started AP mode                       |
| SL_WFX_STOP_AP_IND                | 0xc7  | ::sl_wfx_stop_ap_ind_t               | Stopped AP mode                       |
| SL_WFX_RECEIVED_IND               | 0xca  | ::sl_wfx_received_ind_t              | Frame received                        |
| SL_WFX_SCAN_RESULT_IND            | 0xcb  | ::sl_wfx_scan_result_ind_t           | Scan result received                  |
| SL_WFX_SCAN_COMPLETE_IND          | 0xcc  | ::sl_wfx_scan_complete_ind_t         | Scan complete                         |
| SL_WFX_AP_CLIENT_CONNECTED_IND    | 0xcd  | ::sl_wfx_ap_client_connected_ind_t   | AP Client connected                   |
| SL_WFX_AP_CLIENT_REJECTED_IND     | 0xce  | ::sl_wfx_ap_client_rejected_ind_t    | AP Client rejected                    |
| SL_WFX_AP_CLIENT_DISCONNECTED_IND | 0xcf  | ::sl_wfx_ap_client_disconnected_ind_t| AP Client disconnected                |
| SL_WFX_JOIN_IBSS_IND              | 0xd0  | ::sl_wfx_join_ibss_req_t             | Connection to an IBSS complete        |
| SL_WFX_LEAVE_IBSS_IND             | 0xd1  | ::sl_wfx_leave_ibss_req_t            | Leave IBSS                            |

This indications have to be managed by the host depending on the application and use case.
