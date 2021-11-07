# TCP/IP UDP Client Server

The UDP Client Server configuration demonstrates creating a network client and a network server that uses the MPLAB Harmony UDP API. This demonstration shows how the UDP/IP loopback works and it is a combination of the TCP/IP UDP Client and TCP/IP UDP Server application.

**TCP/IP UDP Client Server MHC Configuration**

The following Project Graph diagram shows the Harmony components included in this application demonstration.

-   MHC is launched by selecting **Tools \> Embedded \> MPLAB® Harmony 3 Configurator** from the MPLAB X IDE and after successful database migration , TCP/IP demo project is ready to be configured and regenerated.

    ![tcpip_sama5d2_project](../../docs/GUID-B704D892-2311-4059-B8CC-42419969671F-low.png)

-   **TCP/IP Root Layer Project Graph**

    The root layer project shows that UART2 peripheral is selected to do read and write operation for TCP/IP commands.

    This is the basic configuration with SYS\_CONSOLE, SYS\_DEBUG and SYS\_COMMAND modules. These modules are required for TCP/IP command execution.

    ![tcpip_sama5d2_project](../../docs/GUID-80C3BD08-7679-4C58-AE88-39C6CF701B7C-low.png)

    **FreeRTOS** component is required for RTOS application. For bare-metal \(non-RTOS\) **FreeRTOS** component should not be selected.

    **NOTE** - The above diagram contains **FreeRTOS** component and that is required for RTOS application. For bare-metal\(non-RTOS\) **FreeRTOS** component shouldn't be selected.

    ![tcpip_sama5d2_project](../../docs/GUID-A99A6EC3-28B9-4090-BBAF-5137ABB0AADA-low.png)

-   **TCP/IP Required Application**

    TCP/IP demo use these application module components for this demo.

    **Announce** module to discover the Microchip devices within a local network.

    **DHCP Client** module to discover the IPv4 address from the nearest DHCP Server.

    **DNS Client** provides DNS resolution capabilities to the stack. During these components selection, the required transport and network modules are also selected.

    ![tcpip_sama5d2_project](../../docs/GUID-87D3ED53-381F-423B-8AF1-52733CFA951A-low.png)

-   **TCPIP Driver Layer**

    **Internal ethernet driver\(gmac\)** is enabled with the external **KSZ8081 PHY driver** library for SAMA5D2 demonstartion.

    ![tcpip_sama5d2_project](../../docs/GUID-CF42C6A6-0889-47EF-88FF-12F44B24E145-low.png)

    The MIIM Driver supports asynchronous read/write and scan operations for accessing the external PHY registers and notification when MIIM operations have completed.


**TCP/IP UDP Client Hardware Configuration**

This section describes the hardware configuration for ATSAM A5D2 Xplained Ultra Evaluation Kit and one can be used for the respective application demonstration.

1.  This section describes the required default hardware configuration use SAM A5D2 Xplained Ultra Evaluation Kit

    [SAM A5D2 Xplained Ultra Evaluation Kit](http://ww1.microchip.com/downloads/en/devicedoc/Atmel-44028-32-bit-Cortex-A5-Microprocessor-SAMA5D2-Xplained-Ultra_User-Guide.pdf)

    ![required_hardware](../../docs/GUID-2B8A8C9A-7E15-4FCD-B14F-789116818A25-low.png)

    -   Ensure JP9 jumper is Open.

    -   Insert the SD Card with the "harmony.bin" output of the project into the SD card slot, J19

    -   Connect the board to a USB port on the test PC by inserting the serial cable into the serial connector, J1

    -   For debugging insert the Atmel SAM-ICE debugger to the JTAG port, J11

    -   Connect the micro USB cable from the computer to the USB Power connector on the SAM A5D2 Xplained Ultra Evaluation Kit to power the board, J23

    -   Establish a connection between the router/switch with the SAM A5D2 Xplained Ultra Evaluation Kit through the RJ45 connector


**TCP/IP UDP Client Server Running Application**

This table lists the name and location of the IAR IDE project folder for the demonstration.

|Project Name|Target Device|Target Development Board|Description|
|------------|-------------|------------------------|-----------|
|sam\_a5d2\_xult.IAR|ATSAMA5D27|SAM A5D2 Xplained Ultra + KSZ8081 PHY Daughter board|Demonstrates the TCP/IP UDP Client/Server on development board with SAMA5D2 device and an on-board KSZ8081 PHY. This is a Non-RTOS implementation|
|sam\_a5d2\_xult\_freertos.IAR|ATSAMA5D27|SAM A5D2 Xplained Ultra + KSZ8081 PHY Daughter board|Demonstrates the TCP/IP UDP Client/Server on development board with SAMA5D2 device and an on-board KSZ8081 PHY. This is a FreeRtos implementation|

There are three sequential commands implemented in this demonstration.

1.  **setudppacketoptions** < hostname \> < port \> < message \> - This command specifies the following parameters for the UDP packet: Destination IP Address or Host name, Destination Port and Message to transfer

2.  **getudppacketoptions** - This command displays the current options

3.  **sendudppacket** - This command sends a UDP packet

4.  Build the demo by opening the project in the IAR Embedded Workbench

5.  Copy the project output, harmony.bin, to the SD card that is used to load the executable and run it on the SAM9X60-EK board. Note: the boot loader on the SD card, boot.bin, should be configured to load the harmony.bin image, not a uboot.bin image.


**Running Demonstration Steps**

1.  Build and download the demonstration project on the target board.

2.  If the board has a UART connection:

    1.  A virtual COM port will be detected on the computer, when the USB cable is connected to USB-UART connector.

    2.  Open a standard terminal application on the computer \(like Hyper-terminal or Tera Term\) and configure the virtual COM port.

    3.  Set the serial baud rate to 115200 baud in the terminal application.

    4.  Insert the SD Card into J19, SDMMC1, on the SAM A5D2 board and press the reset button. At this moment the board should boot up and display messages at the console.

    5.  See that the initialization prints on the serial port terminal.

    6.  When the DHCP client is enabled in the demonstration, wait for the DHCP server to assign an IP address for the development board. This will be printed on the serial port terminal.

        -   Alternatively: Use the Announce service or ping to get the IP address of the board.

        -   Run **tcpip\_discoverer.jar** to discover the IPv4 and IPv6 address for the board.

3.  Execution :

    1.  Set the UDP packet options by typing **setudppacketoptions** at the terminal console.

    2.  Verify the UDP packet settings by typing **getudppacketoptions** at the terminal console.

    3.  Send the UDP packet to the destination using the **sendudppacket** command.

    4.  After the **sendudppacket** command is input, the demonstration will make a DNS query to look up the host name and send a UDP packet to that host.

    5.  The output message will be received by the UDP server on the port that is configured by the command **setudppacketoption**.

4.  Testing the UDP Server part of demonstration:

    1.  As soon as a valid IP address is assigned through the DHCP to the demonstration, it is ready to accept a UDP/IP connection on port 9760.

    2.  Send a UDP packet to the IP address of the hardware board and port 9760 from any UDP Client application running on the computer \(SocketTest, Packet Sender etc\).

    3.  The UDP Server demonstration running on the evaluation kit will echo back everything it receives along the connection.


**Parent topic:**[MPLAB® Harmony 3 TCP/IP Application for SAM A5D2 Family](../../docs/GUID-E0336200-D959-4A15-BD0E-C418C0991ADD.md)

