/* 
 * File:   newmain.c
 * Author: islam
 *
 * Created on April 30, 2018, 6:07 PM
 */
/*================ Implementing 1 Sec =================*/
// Blink LED every one second
// time = Tosc * 4 * prescalar * (TMR0H:TMR0L)
// 1e6 us = 0.125 us * 4 * prescalar * (TMR0H:TMR0L)
// 1e6 us / (0.125 us * 4) = prescalar * (TMR0H:TMR0L)
// 2e6 = prescalar[32] * (TMR0H:TMR0L)
// (TMR0H:TMR0L) = 62500
// preloaded | Preset = 65536 - 62500 = 3036
/*=====================================================*/

#include "config.h"

void interrupt Timer(){

    if(TMR0IF == 1){
    
        TMR0L = 0xDC;
        TMR0H = 0x0B;        
        LATB0 = !LATB0;
        TMR0IF = 0;
    }
}

void main(){
    
    TRISB0 = 0;
    LATB0 = 0;
    
    GIE = 1;
    PEIE = 1;
    TMR0IE = 1;
    TMR0IF = 0;
	
    T08BIT = 0;
    T0CS = 0;
    PSA = 0;
	T0CONbits.T0PS = 4;
    TMR0L = 0xDC;
    TMR0H = 0x0B;
    TMR0ON = 1;
    
    while(1);
}