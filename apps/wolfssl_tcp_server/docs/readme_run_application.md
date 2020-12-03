---
grand_parent:  Harmony 3 TCP/IP Application for SAM A5D2 Family
parent: TCP/IP WolfSSL TCP Server
title: Running Application
nav_order: 3
has_children: false
has_toc: false
---
[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# TCP/IP WolfSSL TCP Server Running Application

## IAR Embeded Workbench IDE Project

This table lists the name and location of the IAR IDE project folder for the demonstration. 

|Project Name|  Target Device|  Target Development Board | Description  |
|:-------------:|:---------:|:---------:|:---------:|
|sam_a5d2_xult.IAR  | ATSAMA5D27   | SAM A5D2 Xplained Ultra  + KSZ8081 PHY Daughter board | Demonstrates the TCP/IP Wolfssl TCP  Server on development board with SAMA5D2 device and an on-board KSZ8081 PHY. This is a Non-RTOS implementation.  HW crypto enabled  |
|sam_a5d2_xult_freertos.IAR  | ATSAMA5D27   | SAM A5D2 Xplained Ultra  + KSZ8081 PHY Daughter board | Demonstrates the TCP/IP Wolfssl TCP Server on development board with SAMA5D2 device and an on-board KSZ8081 PHY. This is a FreeRtos implementation.  HW crypto enabled  |
|sam_a5d2_xplained_ultra_sw.IAR  | ATSAMA5D27   | SAM A5D2 Xplained Ultra  + KSZ8081 PHY Daughter board | Demonstrates the TCP/IP WolfSSL TCP Server on development board with SAMA5D2 device and an on-board KSZ8081 PHY. This is a non-RTOS implementation. SW crypto enabled  |

## Running The Demonstration

1. Build the demo by opening the project in the IAR Embedded Workbench 

2. Copy the project output, harmony.bin, to the SD card that is used to load the executable and run it on the SAM9X60-EK board. Note: the boot loader on the SD card, boot.bin, should be configured to load the harmony.bin image, not a uboot.bin image. 

3. Configure the Development Board as given  **[Configure Hardware](readme_hardware_configuration.md)**.

4. Make the demonstration setup as shown [Network Setup](../../readme.md).

5. Build and download the demonstration project on the target board.

6. If the board has a UART connection:

    1. A virtual COM port will be detected on the computer, when the USB cable is connected to USB-UART connector.

    2. Open a standard terminal application on the computer (like Hyper-terminal or Tera Term) and configure the virtual COM port.

    3. Set the serial baud rate to 115200 baud in the terminal application.

    4. Insert the SD Card into J19, SDMMC1, on the SAM A5D2 board and press the reset button. At this moment the board should boot up and display messages at the console.  

    5. See that the initialization prints on the serial port terminal.

    6. When the DHCP client is enabled in the demonstration, wait for the DHCP server to assign an IP address for the development board. This will be printed on the serial port terminal.

		* Alternatively: Use the Announce service or ping to get the IP address of the board.

        * Run **tcpip_discoverer.jar** to discover the IPv4 and IPv6 address for the board.
        
7. Execution :

    As soon as a valid IP address is assigned through the DHCP to the demonstration, it is ready to serve Web pages.

    The demonstration does not offer any additional functionality through the serial port; however, the current IP can be checked.

    Use any Web browser (i.e., Chrome, Internet Explorer, Firefox, etc.) to connect to the Web server with either http:// or https://.
