# WF200 FMAC driver

The Silicon Labs WF200 is an **Ultra Low Power Wi-Fi® transceiver** or network co-processor (NCP) targeted for applications where optimal RF performance, low-power consumption, and secure end-to-end solution, together with fast time to market, are key requirements.
The WF200 integrates the Balun, T/R switch, LNA and PA for best possible RF performance. WF200 has been optimized for resource and power constrained devices at the RF, protocol
and firmware levels. Power conscious devices can take advantage of these features in both active and idle/sleep modes. For security sensitive applications WF200 provides secure boot and a secure & encrypted host interface. Robust security is made possible with a native integrated True Random
Number Generator and OTP memory for confidential encryption key storage. The WF200 fits well with Linux-based and RTOS based host processors. WF200 supports both the 802.11 split MAC and the 802.11 full MAC architectures. It communicates
with the external host controller over the SPI or SDIO interface.

WF200 can act as a full-MAC wireless device and WPA2 personal supplicant. The firmware exposes a full-MAC API at the IP packet level.
It also manages WPA2 personal  authentication process as well as automatic roaming. This FMAC driver enables a user to use WF200 in this configuration.

The doxygen documentation of the driver is available through the FMAC_driver_doxygen shorcut.