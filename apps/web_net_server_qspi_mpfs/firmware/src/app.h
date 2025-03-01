/*******************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/

/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_Initialize" and "APP_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP_STATES" definition).  Both
    are defined here for convenience.
*******************************************************************************/

#ifndef _APP_H
#define _APP_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "configuration.h"
#include "system_definitions.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************

#define APP_DEBUG_ON                0   // display app state and debug messages

#ifdef __SAM9X60__
#define LED_AH_PB11_Get() (PIOB_REGS->PIO_PDSR & (1<<11))
#define LED_AH_PB12_Get() (PIOB_REGS->PIO_PDSR & (1<<12))
#define LED_AH_PB13_Get() (PIOB_REGS->PIO_PDSR & (1<<13))

#define APP_LED_2StateGet()         LED_AH_PB12_Get()
#define APP_LED_3StateGet()         LED_AH_PB13_Get()
  
#define APP_SWITCH_1StateGet()      SW1_Get()
#define APP_LED_1StateGet()         LED_AH_PB11_Get()
#define APP_LED_1StateSet()         LED_AH_PB11_On()
#define APP_LED_1StateClear()       LED_AH_PB11_Off()
#define APP_LED_1StateToggle()      LED_AH_PB11_Toggle()
#else
/*
#define APP_SWITCH_1StateGet()      SWITCH_Get()
#define APP_LED_1StateGet()         LED1_Get()
#define APP_LED_1StateSet()         LED1_Set()
#define APP_LED_1StateClear()       LED1_Clear()
#define APP_LED_1StateToggle()      LED1_Toggle()
 */
#define APP_SWITCH_1StateGet()      SWITCH_USER_Get()
#define APP_LED_1StateGet()         LED_GREEN_Get()
#define APP_LED_1StateSet()         LED_GREEN_On()
#define APP_LED_1StateClear()       LED_GREEN_Off()
#define APP_LED_1StateToggle()      LED_GREEN_Toggle()
    
#define APP_LED_2StateGet()         LED_BLUE_Get()
#define APP_LED_2StateSet()         LED_BLUE_On()
#define APP_LED_2StateClear()       LED_BLUE_Off()
#define APP_LED_2StateToggle()      LED_BLUE_Toggle()
    
#define APP_LED_3StateGet()         LED_RED_Get()
#define APP_LED_3StateSet()         LED_RED_On()
#define APP_LED_3StateClear()       LED_RED_Off()
#define APP_LED_3StateToggle()      LED_RED_Toggle()

#endif 

// Application SYS_FS mount points
// Adjust as needed
#define APP_SYS_FS_NVM_VOL          "/dev/mtda1"
#define APP_SYS_FS_MOUNT_POINT      "/mnt/mchpSite1"
#define APP_SYS_FS_TYPE             MPFS2
#define APP_SYS_FS_TYPE_STRING      "MPFS2"

// *****************************************************************************
/* Application states

  Summary:
    Application states enumeration

  Description:
    This enumeration defines the valid application states.  These states
    determine the behavior of the application at various times.
*/

typedef enum
{
    /* Application's state machine's initial state. */
    /* Application writes the MPFS2 image on the external QSPI memory */
    APP_VERIFY_WRITE_DISK = 0,
    /* The app mounts the disk */
    APP_MOUNT_DISK,
    /* In this state, the application waits for the initialization of the TCP/IP stack
     * to complete. */
    APP_TCPIP_WAIT_INIT,
    /* In this state, the application can do TCP/IP transactions.. */
    APP_TCPIP_TRANSACT,
    /* The application error state */
    APP_TCPIP_ERROR,
} APP_STATES;

typedef enum
{
    APP_TCPIP_WAIT_FOR_COMMAND,
    APP_TCPIP_GET_COMMAND,
    APP_TCPIP_PROCESS_COMMAND,
}APP_COMMAND_STATES;

// *****************************************************************************
/* LED State

  Summary:
    Enumerates the supported LED states.

  Description:
    This enumeration defines the supported LED states.

  Remarks:
    None.
*/
typedef enum
{
    APP_LED_STATE_OFF = 0,
    APP_LED_STATE_ON = 1,
} APP_LED_STATE;

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    Application strings and buffers are be defined outside this structure.
 */

typedef struct
{
    /* SYS_FS File handle */
    SYS_FS_HANDLE       fileHandle;
    /* Application's current state */
    APP_STATES          state;
/* TODO: Define any additional data used by the application. */

} APP_DATA;

// *****************************************************************************
// *****************************************************************************
// Section: extern declarations
// *****************************************************************************
// *****************************************************************************
extern const uint8_t NVM_MEDIA_DATA[];

// HTTP application processing
extern void HTTP_APP_Initialize(void);

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************
/* These routines are called by drivers when certain events occur.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Summary:
     MPLAB Harmony application initialization routine.

  Description:
    This function initializes the Harmony application.  It places the
    application in its initial state and prepares it to run so that its
    APP_Tasks function can be called.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_Initialize();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function.
*/

void APP_Initialize ( void );


/*******************************************************************************
  Function:
    void APP_Tasks ( void )

  Summary:
    MPLAB Harmony Demo application tasks function

  Description:
    This routine is the Harmony Demo application's tasks function.  It
    defines the application's state machine and core logic.

  Precondition:
    The system and application initialization ("SYS_Initialize") should be
    called before calling this.

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_Tasks();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */

void APP_Tasks( void );

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _APP_H */

/*******************************************************************************
 End of File
 */

