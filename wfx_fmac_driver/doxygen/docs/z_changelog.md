Changelog {#changelog}
============

(release date 2019-04-18)
# Release 2.0.1
* Fix an issue with the soft ap interface
* Limit the input buffers to avoid running into issues when transmitting data and send regular FMAC commands
* Update the Doxygen documentation
* Aligned on firmware 2.2.1

# Release 2.0.0
(release date 2019-04-12)
* File name prefixes changed from wf200_ to sl_wfx_
* Function name prefixes changed from wf200_ to sl_wfx_
* Structure name prefixes changed from wf200_ to sl_wfx_
* Add secure link support through sl_wfx_secure_link.c and sl_wfx_secure_link.h
* Add following APIs:
	* sl_wfx_join_ibss_command
	* sl_wfx_leave_ibss_command
	* sl_wfx_remove_multicast_address
	* sl_wfx_set_arp_ip_address
	* sl_wfx_set_ns_ip_address
	* sl_wfx_set_broadcast_filter
	* sl_wfx_set_unicast_filter
	* sl_wfx_add_whitelist_address
	* sl_wfx_add_blacklist_address
	* sl_wfx_set_max_ap_client_inactivity
	* sl_wfx_set_scan_parameters
	* sl_wfx_set_roam_parameters
	* sl_wfx_set_tx_rate_parameters
	* sl_wfx_set_max_tx_power
	* sl_wfx_get_max_tx_power
	* sl_wfx_control_gpio
	* sl_wfx_prevent_rollback
* Remove wf200_pds.h from the driver
* Add sl_wfx_host_get_pds_data() and sl_wfx_host_get_pds_size() APIs
* Modify sl_wfx_host_post_event declaration
* Modify sl_wfx_host_spi_transfer_no_cs_assert declaration
* wf200_frame_t structure replaced by sl_wfx_send_frame_req_t
* wf200_ethernet_frame_t structure replaced by sl_wfx_received_ind_t
* wf200_buffer_t structure replaced by sl_wfx_generic_message_t
* wf200_scan_result_t structure replaced by sl_wfx_scan_result_ind_t
* Align existing driver APIs to firmware APIs
* Aligned on firmware 2.2.1

# Release 1.0.1
(release date 2019-03-04)
* Modification in wf200_bus_sdio.c to improve SDIO support
* Removed Doxygen HTML output
* Aligned on firmware 2.0.0

# Release 1.0.0
(release date 2019-01-08)
* Initial release
* Aligned on firmware 2.0.0
