---
grand_parent:  Harmony 3 TCP/IP Application for SAM A5D2 Family
parent: TCP/IP TCP and UDP Client Server
title: Running Application
nav_order: 3
has_children: false
has_toc: false
---
[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# TCP/IP TCP and UDP Client Server Running Application

The Client Server configuration use combination of both TCP and UDP sockets for both client and server communication.

## IAR Embeded Workbench IDE Project

This table lists the name and location of the IAR IDE project folder for the demonstration. 

|Project Name|  Target Device|  Target Development Board | Description  |
|:-------------:|:---------:|:---------:|:---------:|
|sam_a5d2_xult_freertos.IAR  | ATSAMA5D27   | SAM A5D2 Xplained Ultra  + KSZ8081 PHY Daughter board | Demonstrates the TCP/IP TCP & UDP Client/Server on development board with SAMA5D2 device and an on-board KSZ8081 PHY. This is a FreeRtos implementation  |

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

    1. Once the demonstration starts executing,  we can observe the current IP settings at the Tera Term terminal port.

    2. Using "help" will display the available commands that can be used for this demo.

    3. The application can create 4 separate connections, each one running in its own thread:
        * A TCP client connection
        * A TCP server connection
        * A UDP client connection
        * A UDP server connection

    4. Each connection has its own set of commands.

        * They can open or close the sockets, send messages to the socket they are connected to, they can display the received messages, etc.
        
        * Using your preferred networking tools on the PC side ( netcat, Packet Sender, Hercules, python scripts, etc., etc. ) create sockets that talk to the ones opened by the client server application.
        
        * This way you can exchange data with any/all of the communication threads that the demonstration creates.

    5. After the successful broad bring up, the console output becomes

        ![tcpip_client_server_project](images/dhcp_5.png)

    6. For TCP Client test, input the following command from the serial port: **openurl < url >** - The < url > argument must be a fully formed URL; for instance, http://www.microchip.com/.

        For this above URL , the DNS module will make a DNS query. Then it will open a connection to the requested URL and perform a simple HTTP GET command.
        The response received from the server will be printed on the terminal application through the serial port.

        The expected output -

        ![tcpip_client_server_project](images/http_put_6.png)
    
    7.  For TCP Server test, the TCP Client application is required to run on the computer (SocketTest, Packet Sender etc). In this demonstration, we use the program, SocketTest (http://sockettest.sourceforge.net/). This demonstration is tested with **SocketTest v3.0**.

        * Open the **SocketTest** software and set the configuration as shown in the following figure.

            ![tcpip_tcp_client_server_project](images/enter_ip_7.png)

        *  Press the Connect button on the **SocketTest** software after setting the configuration. The serial terminal indicates that the connection has been established.
        
        * Type any message in the message box of the **SocketTest** program, and press the Send button. The Server running on the development board will echo back the message to the **SocketTest** program.

            ![tcpip_tcp_client_server_project](images/client_test_8.png)
    
    8. Simillarly UDP Client and Server test also performed using **SocketTest** tool.