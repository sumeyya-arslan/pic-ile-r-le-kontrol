/**
  Generated Pin Manager File

  Company:
    Microchip Technology Inc.

  File Name:
    pin_manager.c

  Summary:
    This is the Pin Manager file generated using MPLAB® Code Configurator

  Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB® Code Configurator - v2.25.2
        Device            :  PIC16F1829
        Driver Version    :  1.02
    The generated drivers are tested against the following:
        Compiler          :  XC8 v1.34
        MPLAB             :  MPLAB X v2.35 or v3.00
*/

/*
Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*/

#include <xc.h>
#include "pin_manager.h"
#define Dgt1 LATCbits.LATC3
#define Dgt2 LATCbits.LATC4
#define DS   LATC6
#define STCP LATC5
#define SHCP LATC7
#define digit1button PORTBbits.RB4
#define digit2button PORTBbits.RB5
#define digit3button PORTBbits.RB6
#define digit4button PORTBbits.RB7
unsigned char Digit[10] = { 0x03, 0x9F, 0X25, 0x0D, 0x99, 0x49, 0x41, 0x1F, 0x01, 0x09 };// SIRASIYLA 0,1,2,3,4,5,6,7,8,9

void PIN_MANAGER_Initialize(void)
{
    LATA = 0x00;
    TRISA = 0x3F;
    ANSELA = 0x17;
    WPUA = 0x00;

    LATB = 0x00;
    TRISB = 0xF0;
    ANSELB = 0x00;
    WPUB = 0xF0;

    LATC = 0x00;
    TRISC = 0xE7;
    ANSELC = 0xC7;
    WPUC = 0x00;

    OPTION_REGbits.nWPUEN = 0x00;

    APFCON0 = 0x00;

    APFCON1 = 0x00;

    // enable interrupt-on-change individually    
    IOCBN4 = 1;
    IOCBN5 = 1;
    IOCBN6 = 1;
    IOCBN7 = 1;
    
    // enable interrupt-on-change globally
    INTCONbits.IOCIE = 1;        
        
}
void PIN_MANAGER_IOC(void)
{
 

    if((IOCBN4 == 1) && (IOCBF4 == 1))
    {
        //@TODO Add handling code for IOC on pin RB4
        // clear interrupt-on-change flag
        IOCBF4 = 0;
    }
    else if((IOCBN5 == 1) && (IOCBF5 == 1))
    {
        //@TODO Add handling code for IOC on pin RB5
        // clear interrupt-on-change flag
        IOCBF5 = 0;        
    }
    else if((IOCBN6 == 1) && (IOCBF6 == 1))
    {
        //@TODO Add handling code for IOC on pin RB6
   
        // clear interrupt-on-change flag
        IOCBF6 = 0;        
    }
    else if((IOCBN7 == 1) && (IOCBF7 == 1))
    {
        //@TODO Add handling code for IOC on pin RB7
    
        // clear interrupt-on-change flag
        IOCBF7 = 0;        
    }
}
/**
 End of File
*/