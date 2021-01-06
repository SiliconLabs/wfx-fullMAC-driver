Wi-Fi FMAC Driver Release Note
==============================

# Release 3.3.0
(release date 2020-01-06)

## New Features/Improvements/Bug Fixes
* Add a 'strategy' parameter to sl_wfx_set_power_mode() to select power save mode
* Aligned on firmware 3.12.0

# Release 3.2.2
(release date 2020-11-12)

## New Features/Improvements/Bug Fixes
* Add default configuration files
* Aligned on firmware 3.11.1

# Release 3.2.1
(release date 2020-10-14)

## New Features/Improvements/Bug Fixes
* Improve Secure Link context initialization
* Optimize power save implementation
* sl_wfx_send_request() returns a status when HIF queue is full
* Aligned on firmware 3.11.0

# Release 3.2.0
(release date 2020-10-05)

## New Features/Improvements/Bug Fixes
* Add API to allow WPA3 offloading to the host
* Aligned on firmware 3.10.0

# Release 3.1.0
(release date 2020-08-04)

## New Features/Improvements/Bug Fixes
* Sync to the Secure Link bitmap returned by the firmware in sl_wfx_secure_link_configure()
* Aligned on firmware 3.9.0

# Release 3.0.4
(release date 2020-07-20)

## New Features/Improvements/Bug Fixes
* Fix a potential exploit in sl_wfx_get_pmk()
* Check if received commands have the correct Secure Link encryption state
* Check 'get' command status before returning values to the application
* Aligned on firmware 3.8.0

# Release 3.0.3
(release date 2020-06-19)

## New Features/Improvements/Bug Fixes
* Fixed an issue with Secure Link Trusted Enforced parts

# Release 3.0.2
(release date 2020-06-15)

## New Features/Improvements/Bug Fixes
* Improve sl_wfx_send_request() and sl_wfx_receive_frame() error reporting
* Improve sl_wfx_init() execution time
* Aligned on firmware 3.7.0

## Known issues
* The driver cannot initialize Secure Link Trusted Enforced parts (sl_wfx_secure_link_configure() not encrypted)

# Release 3.0.0
(release date 2020-04-14)

## New Features/Improvements/Bug Fixes
* Remove following APIs:
  * sl_wfx_join_ibss_command()
  * sl_wfx_leave_ibss_command()
* Update context MAC address when calling sl_wfx_set_mac_address()
* Enable writing of Secure Link key in OTP
* Improve logging of error indications
* Fix memory issue with Secure Link
* Change firmware folder structure
* Aligned on firmware 3.5.0

# Release 2.4.0
(release date 2020-03-09)

## New Features/Improvements/Bug Fixes
* Add the following function to the driver API:
  * sl_wfx_set_cca_config()
* Fix handling error when calling sl_wfx_host_lock()
* Improve SLK negotiation handling robustness
* Add an error check on the config read in SDIO
* Do not set up event for:
  * SL_WFX_SEND_FRAME_REQ_ID request
  * SL_WFX_SHUT_DOWN_REQ_ID request
* Aligned on firmware 3.4.1

# Release 2.3.2
(release date 2019-12-06)

## New Features/Improvements/Bug Fixes
* Rename firmware files to use sl_wfx prefix
* Fix sl_wfx_get_opn() function
* Aligned on firmware 3.3.1

# Release 2.3.0
(release date 2019-11-07)

## New Features/Improvements/Bug Fixes
* Add a new logging mechanism to debug the driver
* Add a lock/unlock API to handle driver accesses in an RTOS context
* Add Secure Link (SLK) fast key negotiation support
* Add a "bssid" parameter to the sl_wfx_send_scan_command function to support directed unicast scan
* Add the following function to the driver API:
  * sl_wfx_get_pmk()
* Add the following functions to the host API:
  * sl_wfx_host_lock()
  * sl_wfx_host_unlock()
  * sl_wfx_host_log()
* Rename sl_status_t defines and move sl_status.h location
* Aligned on firmware 3.3.0

# Release 2.2.0
(release date 2019-09-05)

## New Features/Improvements/Bug fixes
* Fix a bug in sl_wfx_send_ethernet_frame() where the header payload could be
corrupted
* Add Secure Link (SLK) support
* Add Packet Traffic Arbitration (PTA) support
* Add the following functions to the driver API:
  * sl_wfx_pta_settings()
  * sl_wfx_pta_priority()
  * sl_wfx_pta_state()
  * sl_wfx_secure_link_set_mac_key()
  * sl_wfx_secure_link_exchange_keys()
  * sl_wfx_secure_link_renegotiate_session_key()
  * sl_wfx_secure_link_configure();
* Add the following functions to the host API:
  * sl_wfx_host_get_secure_link_mac_key()
  * sl_wfx_host_compute_pub_key()
  * sl_wfx_host_verify_pub_key()
  * sl_wfx_host_decode_secure_link_data()
  * sl_wfx_host_encode_secure_link_data()
  * sl_wfx_host_schedule_secure_link_renegotiation()
* Add the following files to the driver:
  * secure_link/sl_wfx_secure_link.c
  * secure_link/sl_wfx_secure_link.h
  * sl_wfx_version.h
* Aligned on firmware 3.0.0

# Release 2.1.0
(release date 2019-07-19)

## New Features/Improvements/Bug fixes
* Introduce device power save management
* Add the following functions to the driver API:
  * sl_wfx_get_ap_client_signal_strength()
  * sl_wfx_enable_device_power_save()
  * sl_wfx_disable_device_power_save()
* Add the following functions to the host API:
	* sl_wfx_host_sleep_grant()
* Rename sl_wfx_context_t used_buffer_number attribute to used_buffers
* Rename sl_wfx_interface_status_t to sl_wfx_state_t
* Add attribute sl_wfx_state_t state to sl_wfx_context_t
* Remove wait_duration_ms parameter from sl_wfx_host_allocate_buffer()
* Remove message_type parameter from sl_wfx_host_post_event()
* Remove the Doxygen documentation and replace it by a link to docs.silabs.com
* Aligned on firmware 2.3.0

## Known issues
* sl_wfx_send_ethernet_frame() can send a corrupted header if the memory allocated for sl_wfx_send_frame_req_t frame is not set to 0

# Release 2.0.1
(release date 2019-04-18)

## New Features/Improvements/Bug fixes
* Fix an issue with the softAP interface
* Limit the input buffers to avoid running into issues when transmitting data
	and sending regular FMAC commands
* Update the Doxygen documentation
* Aligned on firmware 2.2.1

# Release 2.0.0
(release date 2019-04-12)

## New Features/Improvements/Bug fixes
* File name prefixes changed from wf200_ to sl_wfx_
* Function name prefixes changed from wf200_ to sl_wfx_
* Structure name prefixes changed from wf200_ to sl_wfx_
* Add following APIs:
	* sl_wfx_join_ibss_command()
	* sl_wfx_leave_ibss_command()
	* sl_wfx_remove_multicast_address()
	* sl_wfx_set_arp_ip_address()
	* sl_wfx_set_ns_ip_address()
	* sl_wfx_set_broadcast_filter()
	* sl_wfx_set_unicast_filter()
	* sl_wfx_add_whitelist_address()
	* sl_wfx_add_blacklist_address()
	* sl_wfx_set_max_ap_client_inactivity()
	* sl_wfx_set_scan_parameters()
	* sl_wfx_set_roam_parameters()
	* sl_wfx_set_tx_rate_parameters()
	* sl_wfx_set_max_tx_power()
	* sl_wfx_get_max_tx_power()
	* sl_wfx_control_gpio()
	* sl_wfx_prevent_rollback()
* Remove wf200_pds.h from the driver
* Add sl_wfx_host_get_pds_data() and sl_wfx_host_get_pds_size() APIs
* Modify sl_wfx_host_post_event() declaration
* Modify sl_wfx_host_spi_transfer_no_cs_assert() declaration
* wf200_frame_t structure replaced by sl_wfx_send_frame_req_t
* wf200_ethernet_frame_t structure replaced by sl_wfx_received_ind_t
* wf200_buffer_t structure replaced by sl_wfx_generic_message_t
* wf200_scan_result_t structure replaced by sl_wfx_scan_result_ind_t
* Align existing driver APIs to firmware APIs
* Aligned on firmware 2.2.1

## Known issues
* The softAP interface is not set correctly by the driver

# Release 1.0.1
(release date 2019-03-04)

## New Features/Improvements/Bug fixes
* Modification in wf200_bus_sdio.c to improve SDIO support
* Removed Doxygen HTML output
* Aligned on firmware 2.0.0

# Release 1.0.0
(release date 2019-01-08)
* Initial release
* Aligned on firmware 2.0.0
