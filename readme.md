![Microchip logo](https://raw.githubusercontent.com/wiki/Microchip-MPLAB-Harmony/Microchip-MPLAB-Harmony.github.io/images/microchip_logo.png)
![Harmony logo small](https://raw.githubusercontent.com/wiki/Microchip-MPLAB-Harmony/Microchip-MPLAB-Harmony.github.io/images/microchip_mplab_harmony_logo_small.png)

# Harmony 3 Net library application examples for SAMA5D2 family

MPLAB® Harmony 3 is an extension of the MPLAB® ecosystem for creating embedded firmware solutions for Microchip 32-bit SAM and PIC® microcontroller and microprocessor devices.  Refer to the following links for more information.

- [Microchip 32-bit MCUs](https://www.microchip.com/design-centers/32-bit)
- [Microchip 32-bit MPUs](https://www.microchip.com/design-centers/32-bit-mpus)
- [Microchip MPLAB X IDE](https://www.microchip.com/mplab/mplab-x-ide)
- [Microchip MPLAB® Harmony](https://www.microchip.com/mplab/mplab-harmony)
- [Microchip MPLAB® Harmony Pages](https://microchip-mplab-harmony.github.io/)

This repository contains the MPLAB® Harmony 3 Net library application examples for SAMA5D2 family

- [Release Notes](release_notes.md)
- [MPLAB® Harmony License](mplab_harmony_license.md)

This content can be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

## Contents Summary

| Folder     | Description                             |
| ---        | ---                                     |
| apps       | Contains Net library example applications |
| docs       | Contains documentation in html format for offline viewing (to be used only after cloning this repository onto a local machine). Use [github pages](https://microchip-mplab-harmony.github.io/net_apps_sam_a5d2/) of this repository for viewing it online. |

## Code Examples

The following applications are provided to demonstrate the typical or interesting usage models of the Net libraries.

| Name | Description |
| ---- | ----------- |
| [berkeley_tcp_client](./docs/GUID-357D4BD1-F8B9-462D-A9C7-5F55422F3578.html) | This example application shows a TCP Client demo using BSD API |
| [berkeley_tcp_server](./docs/GUID-31BD4275-1484-465A-874A-B2CF6DF78D36.html) | This example application shows a TCP Server demo using BSD API |
| [berkeley_udp_client](./docs/GUID-C73267EF-E2D6-4788-B33E-5FA4281DA552.html) | This example application shows a UDP Client demo using BSD API |
| [berkeley_udp_server](./docs/GUID-615D1EED-8A15-4A20-9717-542A8137FEAC.html) | This example application shows a UDP Server demo using BSD API |
| [iperf_demo](./docs/GUID-67C26E54-9F2C-446F-AB11-89924D2A39D9.html) | This example application shows running iperf and measuring the network performance |
| [tcpip_client_server](./docs/GUID-5BCE8554-F528-4C99-A373-CCA033F68DAA.html) | This example application shows a multi-threaded example with TCP and UDP server and client threads |
| [tcpip_tcp_client](./docs/GUID-8EF7BA16-A13E-4652-B2B2-AA99F32AABF1.html) | This example application shows a TCP Client demo using Harmony native API |
| [tcpip_tcp_client_server](./docs/GUID-ABCB4795-F280-44F6-9FF5-F4E3E1AC8196.html) | This example application shows a TCP Client and Server demo using Harmony native API |
| [tcpip_tcp_server](./docs/GUID-632389C6-4DB2-4CCC-B138-5198FC675450.html) | This example application shows a TCP Server demo using Harmony native API |
| [tcpip_udp_client](./docs/GUID-B423C86B-AA47-4949-AB06-94B60BE76AB6.html) | This example application shows a UDP Client demo using Harmony native API |
| [tcpip_udp_client_server](./docs/GUID-0A2FB1EB-80EF-4777-A0D4-869307687EF8.html) | This example application shows a UDP Client and Server demo using Harmony native API|
| [tcpip_udp_server](./docs/GUID-EACB8B2B-A4A1-4C1B-81FA-CED5B2AAA90B.html)| This example application shows a UDP Server demo using Harmony native API |
| [web_net_server_qspi_mpfs](./docs/GUID-E7DEE2EB-2D9A-4543-B99F-409ED2ABF1BE.html) | This example application shows a Web server with MPFS file system on the onboard QSPI Flash Memory |
| [web_net_server_sdcard_fatfs](./docs/GUID-4B3AA47C-28FB-402F-8430-25037021D137.html) | This example application shows a Web server with FAT FS file system on the external SD card |
| [web_net_super_set_sdcard_fatfs](./docs/GUID-98E41875-C5E4-47F9-9137-9BD2AE77E177.html) | This example application shows a All modules built in demo (IPv6, DHCPv6 server, telnet, etc.) running a web server with FAT FS file system on the external SD card |
| [wolfmqtt_demo](./docs/GUID-E63A9CD6-68F2-4D0B-98A6-DDBFDA4654A0.html) | This example application shows a MQTT demo using the 3rd party wolfMQTT library |
| [wolfssl_tcp_client](./docs/GUID-478F4BDE-ACE9-463B-8FF6-5462752CDAD4.html) | This example application shows a connection to a Web server using TLS to encrypt the connection with wolfSSL |
| [wolfssl_tcp_server](./docs/GUID-ED7F2AF1-5B04-402F-BC7C-3F2E9BBBDBB2.html) | This example application shows Web server demo accepting encrypted TLS connections using wolfSSL |

____

[![License](https://img.shields.io/badge/license-Harmony%20license-orange.svg)](https://github.com/Microchip-MPLAB-Harmony/net_apps_sam_a5d2/blob/master/mplab_harmony_license.md)
[![Latest release](https://img.shields.io/github/release/Microchip-MPLAB-Harmony/net_apps_sam_a5d2.svg)](https://github.com/Microchip-MPLAB-Harmony/net_apps_sam_a5d2/releases/latest)
[![Latest release date](https://img.shields.io/github/release-date/Microchip-MPLAB-Harmony/net_apps_sam_a5d2.svg)](https://github.com/Microchip-MPLAB-Harmony/net_apps_sam_a5d2/releases/latest)
[![Commit activity](https://img.shields.io/github/commit-activity/y/Microchip-MPLAB-Harmony/net_apps_sam_a5d2.svg)](https://github.com/Microchip-MPLAB-Harmony/net_apps_sam_a5d2/graphs/commit-activity)
[![Contributors](https://img.shields.io/github/contributors-anon/Microchip-MPLAB-Harmony/net_apps_sam_a5d2.svg)]()

____

[![Follow us on Youtube](https://img.shields.io/badge/Youtube-Follow%20us%20on%20Youtube-red.svg)](https://www.youtube.com/user/MicrochipTechnology)
[![Follow us on LinkedIn](https://img.shields.io/badge/LinkedIn-Follow%20us%20on%20LinkedIn-blue.svg)](https://www.linkedin.com/company/microchip-technology)
[![Follow us on Facebook](https://img.shields.io/badge/Facebook-Follow%20us%20on%20Facebook-blue.svg)](https://www.facebook.com/microchiptechnology/)
[![Follow us on Twitter](https://img.shields.io/twitter/follow/MicrochipTech.svg?style=social)](https://twitter.com/MicrochipTech)

[![](https://img.shields.io/github/stars/Microchip-MPLAB-Harmony/net_apps_sam_a5d2.svg?style=social)]()
[![](https://img.shields.io/github/watchers/Microchip-MPLAB-Harmony/net_apps_sam_a5d2.svg?style=social)]()
