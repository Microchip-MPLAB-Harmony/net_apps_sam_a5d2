![Microchip logo](https://raw.githubusercontent.com/wiki/Microchip-MPLAB-Harmony/Microchip-MPLAB-Harmony.github.io/images/microchip_logo.png)
![Harmony logo small](https://raw.githubusercontent.com/wiki/Microchip-MPLAB-Harmony/Microchip-MPLAB-Harmony.github.io/images/microchip_mplab_harmony_logo_small.png)

# Microchip MPLAB® Harmony 3 Release Notes

## Network Application Examples for SAMA5D2 Family, v3.10.0

### New Features
- All applications with TCP/IP Configurator Plugin.
- Support for MAC RX/TX Checksum offload feature.


### Improvements and Bug Fixes
- IPERF throughput improvement.
- Fix for GMAC driver critical section access issue.
- ETHPHY driver write function.
- Fix for bind operation in berkeley module.
- Fix for 'IntegerSymbol not found' MCC failure.
- Updated demo documentation.

### Known Issues
- wolfssl_tcp_client with FreeRTOS fails during TLS Handshake.
- Build warnings for third_party/wolfMQTT/mqtt_socket.c in wolfMQTT demo. Workaround is to uncheck 'Make warnings into errors' in xc32 options.


### Development Tools

- [MPLAB® X IDE, v6.15](https://www.microchip.com/mplab/mplab-x-ide) or later
- [MPLAB® XC32 C/C++ Compiler, v4.35](https://www.microchip.com/mplab/compilers) or later
- [MPLAB® Code Configurator(MCC) Plugin, v5.3.7](https://www.microchip.com/en-us/tools-resources/configure/mplab-code-configurator) or later
- [MPLAB® Harmony v3 net repository, v3.11.0](https://github.com/Microchip-MPLAB-Harmony/net/tree/v3.11.0)
- [MPLAB® Harmony v3 net\_apps\_sam\_a5d2 demo apps repository, v3.10.0](https://github.com/Microchip-MPLAB-Harmony/net_apps_sam_a5d2/tree/v3.10.0)

### Development Kit Support

This release supports applications for the following development kit.

| Development Kits |
| --- |
| [SAM A5D2 Xplained Ultra Evaluation Kit](https://www.microchip.com/Developmenttools/ProductDetails/ATSAMA5D2C-XULT) |


## Net Release Notes

- See the [Net 3.11.0 Release Notes](https://github.com/Microchip-MPLAB-Harmony/net/tree/v3.11.0)

---

## Harmony 3 Network application examples for SAMA5D2 family  v3.9.0

### New Features
New features added in this release are as follows:

- New MPLABX applications added to the SAMA5D2 applications repository
- All applications use MCC for configuration
- All applications use the Net Plugin (beta)

### KNOWN ISSUES
The current known issues are as follows:
* The xc32 uses FPU operations for (u)int64_t types.
    However, the ISRs do not save the FPU registers and can thus corrupt
    calculations that take place in sys_time.c, resulting in errors in the time keeping.
    Some demos for which time keeping is critical - iperf, wolfmqtt, etc. -
    will result in timeouts and the functionality is broken.
* The FreeRTOS demos (web_net_super_set_sdcard_fatfs/wolfmqtt_demo, iperf, berkeley_tcp_client, etc.) fail to initialize
    (due to FPU operations ?)
    Issue is under investigation.
    Debugging with MPLABX IDE is not possible for SAMA5D2 platform.
* iperf demo has really low throughput on TCP using '-O1' build.
    Issue is under investigation.
    The UDP throughput is not affected.
* SAMA5D2 MPLABX demos should not overwrite the mpfs_net_img.c file when regenerated
    - The symbols used in this automatically generated file are not present in the project
* wolfMQTT demos need to have the file third_party/wolfMQTT/mqtt_socket.c built without xc32 option 'Make warnings into errors'
    - That is because it uses the obsolete #include <sys/errno.h>
* DHCPv6 line #1041 the format specifier '%zu' is treated as an error by
    the xc32 on SAM platforms. xc21 will correct this issue in a next release.


### Development Tools

- [MPLAB� X IDE v6.05](https://www.microchip.com/mplab/mplab-x-ide) or later
- [MPLAB� XC32 C/C++ Compiler v4.20](https://www.microchip.com/mplab/compilers) or later
- [Harmony net repository, 3.9.0](https://github.com/Microchip-MPLAB-Harmony/net/tree/v3.9.0)
- [Harmony net_apps_sam_a5d2 demo apps repositories, 3.9.0](https://github.com/Microchip-MPLAB-Harmony/net_apps_sam_a5d2/tree/v3.9.0)
- MPLAB Code Configurator (MCC), 5.2.1


#### Development Kit Support

This release supports applications for the following development kits

| Development Kits |
| --- |
| [SAM A5D2 Xplained Ultra Evaluation Kit](https://www.microchip.com/Developmenttools/ProductDetails/ATSAMA5D2C-XULT) |


## Full release notes

- See the full [Net 3.9.0 Release notes](https://github.com/Microchip-MPLAB-Harmony/net/tree/v3.9.0)

## Harmony 3 Network application examples for SAMA5D2 family  v3.8.0

### New Features
New features added in this release are as follows:

- Applications migrated from MHC to MCC
- Migration of select applications to the Net Plugin (beta)
- Ported the IAR projects to MPLABX

### KNOWN ISSUES
The current known issues are as follows:
* IAR projects are not supported in this release
* SAMA5D2 MPLABX demos should not overwrite the linker script ddr.ld when regenerated.
    - Otherwise the GMAC descriptors: gmac_dcpt_array will not be placed in the '.region_nocache'
* SAMA5D2 MPLABX demos should not overwrite the mpfs_net_img.c file when regenerated
    - The symbols used in this automatically generated file are not present in the project
* SAMA5D2 projects should be built with -O0 optimization and at least 16 descriptors.
    - Higher optimization may cause GMAC driver lock up.
    - Investigation is in progress.





### Development Tools

- [MPLAB� X IDE v6.00](https://www.microchip.com/mplab/mplab-x-ide) or later
- [MPLAB� XC32 C/C++ Compiler v4.00](https://www.microchip.com/mplab/compilers) or later
- [Harmony net repository, 3.8.0](https://github.com/Microchip-MPLAB-Harmony/net/tree/v3.8.0)
- [Harmony net_apps_sam_a5d2 demo apps repositories, 3.8.0](https://github.com/Microchip-MPLAB-Harmony/net_apps_sam_a5d2/tree/v3.8.0)
- MPLAB Code Configurator (MCC), 5.1.2
- MCC Harmony Core, 1.1.0


#### Development Kit Support

This release supports applications for the following development kits

| Development Kits |
| --- |
| [SAM A5D2 Xplained Ultra Evaluation Kit](https://www.microchip.com/Developmenttools/ProductDetails/ATSAMA5D2C-XULT) |


## Full release notes

- See the full [Net 3.8.0 Release notes](https://github.com/Microchip-MPLAB-Harmony/net/tree/v3.8.0)

## Harmony 3 Network application examples for SAMA5D2 family  v3.7.0

### New Features
New features added in this release are as follows:

- Applications migrated from the net repository to this new application repository for SAMA5D2 development boards


### Development Tools

- [IAR Embedded Workbench for ARM - version 8.50.1](https://www.iar.com/iar-embedded-workbench/) or later 
- [Harmony net repository, 3.7.0](https://github.com/Microchip-MPLAB-Harmony/net/tree/v3.7.0)
- [Harmony net_apps_sam_a5d2 demo apps repositories, 3.7.0](https://github.com/Microchip-MPLAB-Harmony/net_apps_sam_a5d2/tree/v3.7.0)


#### Development Kit Support

This release supports applications for the following development kits

| Development Kits |
| --- |
| [SAM A5D2 Xplained Ultra Evaluation Kit](https://www.microchip.com/Developmenttools/ProductDetails/ATSAMA5D2C-XULT) |


## Full release notes

- See the full [Net 3.7.0 Release notes](https://github.com/Microchip-MPLAB-Harmony/net/tree/v3.7.0)


