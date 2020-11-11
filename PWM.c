/* 
 * File:   newmain.c
 * Author: islam
 *
 * Created on May 2, 2018, 3:12 PM
 */

/*================ Setting Frequency & Duty Cycle =================*/
// Generating a PWM signal with Frequency = 1Khz & Duty Cycle = 50%
// periodic time = Tosc * 4 * prescalar * [(PR2) + 1]
// PR2 = (periodic time / (Tosc * 4 * prescalar)) - 1
// PR2 = (1000 us / (0.125 us * 4 * prescalar[16])) - 1
// PR2 = 124

// On time = Tosc * 1 * prescalar * (CCPRXL:CCPXCON<5:4>)
// (CCPRXL:CCPXCON<5:4>) = On time / (Tosc * prescalar)
// (CCPRXL:CCPXCON<5:4>) = 500 us / (0.125 us * prescalar[16])
// (CCPRXL:CCPXCON<5:4>) = 250
/*=================================================================*/

#include "config.h"

void main(){

    TRISC2 = 0;
    TMR2 = 0;
    PR2 = 124;
    // Set Prescalar to 16
    T2CONbits.T2CKPS = 2;
    CCPR1L = 0x3E;
    CCP1CONbits.DC1B = 2;
    CCP1CONbits.CCP1M = 0xC;
    TMR2ON = 1;
    
    while(1);
}
