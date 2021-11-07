# TCP/IP Web NET Server NVM MPFS Application

The Web Net Server MPFS configuration with QSPI peripheral demonstrates creating an HTTP web server on a Microchip evaluation board.

The Microchip Proprietary File System \(MPFS\) is used for reading the web pages from the internal Flash and using MPFS upload feature, the QSPI flash is updated with new MPFS file.

This demonstration uses the HTTP\_NET server which supports encrypted communication through the NET\_PRES layer and an external service provider for TLS support.

**TCP/IP Web NET Server QSPI MPFS MHC Configuration**

The following Project Graph diagram shows the Harmony components included in the application demonstration.

-   MHC is launched by selecting **Tools \> Embedded \> MPLAB® Harmony 3 Configurator** from the MPLAB X IDE and after successful database migration , TCP/IP demo project is ready to be configured and regenerated.

    ![tcpip_sama5d2_project](../../docs/GUID-B704D892-2311-4059-B8CC-42419969671F-low.png)

-   **TCP/IP Root Layer Project Graph**

    The root layer project shows that UART2 peripheral is selected to do read and write operation for TCP/IP commands.

    This is the basic configuration with SYS\_CONSOLE, SYS\_DEBUG and SYS\_COMMAND modules. These modules are required for TCP/IP command execution.

    ![tcpip_sama5d2_project](../../docs/GUID-F046EBDF-D543-4420-A9DB-E61C90CC55C8-low.png)

    **WolfSSL** component is selected for secure connection which supports TLS v1.3 and **WolfSSL-Crypto** component is selected for MD5 and SHA authentication.

    ![tcpip_sama5d2_project](../../docs/GUID-EFC6F748-3987-40B5-9885-BFDA8962E1B8-low.png)

    The file system component is required to select MPFS module. This is the below snapshot for the FS configuration.

    ![tcpip_sama5d2_project](../../docs/GUID-5596E2F5-2296-4E74-8119-327B71BD0C48-low.png)

    **FreeRTOS** component is required for RTOS application. For bare-metal \(non-RTOS\) **FreeRTOS** component should not be selected.

    TCP sockets calculate the ISN using the wolfSSL crypto library.

-   **TCP/IP Required Application**

    TCP/IP demo use these application module components for this demo.

    **Announce** module to discover the Microchip devices within a local network.

    **DHCP Client** module to discover the IPv4 address from the nearest DHCP Server.

    **HTTPNET** module is selected to run the web\_server for the secured port number **443**.

    ![tcpip_sama5d2_project](../../docs/GUID-227E60E8-2B86-4A65-98E1-4EB2AAC0BAAA-low.png)

    By default **Enable MPFS upload via HTTP** is selected. This is helpful When external EEPROM or serial Flash is used for storage, the option to upload the newly created image to the board is available.

-   **TCPIP Driver Layer**

    **Internal ethernet driver\(gmac\)** is enabled with the external **KSZ8081 PHY driver** library for SAMA5D2 demonstartion.

    ![tcpip_sama5d2_project](../../docs/GUID-CF42C6A6-0889-47EF-88FF-12F44B24E145-low.png)

    The MIIM Driver supports asynchronous read/write and scan operations for accessing the external PHY registers and notification when MIIM operations have completed.


**TCP/IP Web Net Server QSPI MPFS Hardware Configuration**

This is the section describes the hardware configuration for ATSAM A5D2 Xplained Ultra Evaluation Kit and one can be used for the respective application demonstration.

1.  This section describes the required default hardware configuration use SAM A5D2 Xplained Ultra Evaluation Kit

    [SAM A5D2 Xplained Ultra Evaluation Kit](http://ww1.microchip.com/downloads/en/devicedoc/Atmel-44028-32-bit-Cortex-A5-Microprocessor-SAMA5D2-Xplained-Ultra_User-Guide.pdf)

    ![required_hardware](../../docs/GUID-2B8A8C9A-7E15-4FCD-B14F-789116818A25-low.png)

    -   Ensure JP9 jumper is Open.

    -   Insert the SD Card with the "harmony.bin" output of the project into the SD card slot, J19

    -   Connect the board to a USB port on the test PC by inserting the serial cable into the serial connector, J1

    -   For debugging insert the Atmel SAM-ICE debugger to the JTAG port, J11

    -   Connect the micro USB cable from the computer to the USB Power connector on the SAM A5D2 Xplained Ultra Evaluation Kit to power the board, J23

    -   Establish a connection between the router/switch with the SAM A5D2 Xplained Ultra Evaluation Kit through the RJ45 connector


**TCP/IP Web NET Server QSPI MPFS Running Application**

The HTTP net server module uses Microchip Proprietary File System \(MPFS\) to read web pages from flash using QSPI peripheral. SDCARD is one of the memory media is used to store the web server pages.

This table lists the name and location of the IAR IDE project folder for the demonstration.

|Project Name|Target Device|Target Development Board|Description|
|------------|-------------|------------------------|-----------|
|sam\_a5d2\_xult.IAR|ATSAMA5D27|SAM A5D2 Xplained Ultra + KSZ8081 PHY Daughter board|Demonstrates the TCP/IP Web Net Server on development board with SAMA5D2 device and an on-board KSZ8081 PHY. This is a Non-RTOS implementation|
|sam\_a5d2\_xult\_freertos.IAR|ATSAMA5D27|SAM A5D2 Xplained Ultra + KSZ8081 PHY Daughter board|Demonstrates the TCP/IP Web Net Server on development board with SAMA5D2 device and an on-board KSZ8081 PHY. This is a FreeRtos implementation|

1.  Build the demo by opening the project in the IAR Embedded Workbench

2.  Copy the project output, harmony.bin, to the SD card that is used to load the executable and run it on the SAM9X60-EK board. Note: the boot loader on the SD card, boot.bin, should be configured to load the harmony.bin image, not a uboot.bin image.


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

    An HTTP server is hosted by the demonstration application. Open\_a web browser and direct it to the board running the HTTP server by typing the URL in the address bar \(for example, https://mchpboard\_c\), and then pressing Enter.

    The demonstration application features following:

    Real-time Hardware Control and Dynamic Variables - On the Overview page the LEDs can be clicked to toggle the LEDs on the Microchip hardware development board. The SWITCHes on the Microchip hardware development board can be pressed to toggle the Buttons on the web page. The dynamic variables can be updated in real-time on the HTTP server.

    **Note:** For the LED and SWITCH functionality portion of the demonstration, configure the GPIOs connected to LEDs and Switches on Microchip hardware development board, through the Pin Configuration manager in MPLAB® Harmony Configurator \(MHC\).

    1.  **Form Processing** - Input can be handled from the client by using the GET and POST methods \(this functionality controls the on-board LEDs and is operational only on the Explorer 16 Development Board\)

    2.  **Authentication** - Shows an example of the commonly used restricted access feature

    3.  **Cookies** - Shows an example of storing small text strings on the client side

    4.  **Server Side Includes** - An example of how SSI can be used to support dynamic content

    5.  **File Uploads** - Shows an example of a file upload using the POST method. The HTTP server can\_accept\_a user-defined MPFS/MPFS2 image file for web pages.

    6.  **Send E-mail** - Shows simple SMTP POST methods

    7.  **Dynamic DNS** - Exercises Dynamic DNS capabilities

    8.  **Network Configuration** - The MAC address, host name, and IP address of the evaluation kit can be viewed in the Network Configuration page and some configurations can be updated

    9.  **MPFS Upload** - A new set of web pages can be uploaded to the web server using this feature, which is accessed through http://mchpboard\_c/mpfsupload

    **Notes:** The location of the MPFS image is fixed at the beginning of the Flash page specified by DRV\_MEMORY\_DEVICE\_START\_ADDRESS. The size of the MPFS upload is limited to DRV\_MEMORY\_DEVICE\_MEDIA\_SIZE in the demonstration. The HTTP File Upload functionality has to be enabled when the project is generated.

    ![tcpip_web_net_server_project](../../docs/GUID-0AFDED7F-0BCB-48D3-8D96-7B6BF8B5090C-low.png)


**Parent topic:**[MPLAB® Harmony 3 TCP/IP Application for SAM A5D2 Family](../../docs/GUID-E0336200-D959-4A15-BD0E-C418C0991ADD.md)

