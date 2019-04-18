General API	{#sl_wfx_common_api}  
============

To interact with WF200, the host has access to a set of API which are exposed both in the split MAC case and in the full MAC case. To find the related driver functions, you can refer to the table below or to the \ref GENERAL_API group.

## General API commands

| Commands                       | Value | Associated driver function       | Description                                                                                                         |
|--------------------------------|-------|----------------------------------|---------------------------------------------------------------------------------------------------------------------|
| SL_WFX_CONFIGURATION           | 0x09  | ::sl_wfx_send_configuration      | Configure the device through the \ref sl_wfx_pds                                                                    |
| SL_WFX_SHUT_DOWN               | 0x32  | ::sl_wfx_shutdown                | Send a request to shut down the internal power supplies                                                             |
| SL_WFX_CONTROL_GPIO            | 0x26  | ::sl_wfx_control_gpio            | Control a GPIO of the WF200                                                                                         |
| SL_WFX_PREVENT_ROLLBACK        | 0x2a  | ::sl_wfx_prevent_rollback        | Active the prevent rollback feature. From this point on the chip  will not boot on an older version of the firmware |

For each available command, there is an associated confirmation with the same ID value.

## General API indications

| Indications          | Value | Associated structure          | Description        |
| -------------------- | ----- | ----------------------------- | ------------------ |
| SL_WFX_EXCEPTION_IND | 0xe0  | ::sl_wfx_exception_ind_body_t | Exception          |
| SL_WFX_ERROR_IND     | 0xe4  | ::sl_wfx_error_ind_body_t     | Error              |
| SL_WFX_STARTUP_IND   | 0xe1  | ::sl_wfx_startup_ind_body_t   | Startup indication |
| SL_WFX_GENERIC_IND   | 0xe3  | ::sl_wfx_generic_ind_body_t   | Generic status     |

This indications have to be managed by the host depending on the application and use case.
