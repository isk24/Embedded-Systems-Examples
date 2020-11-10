/* 
 * File:   newmain.c
 * Author: islam
 *
 * Created on March 27, 2018, 11:45 AM
 */

#include "config.h"

void main(){
    char i = 0; 
    char seg[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7C, 0x07, 0x7F, 0x6F};
    
    TRISB = 0;
    TRISC = 0;
    LATB = 0x3F;
    LATC = 0x3F;
    TRISD0 = 1;
    
    while(1){
       
        if(!PORTDbits.RD0){
           
            __delay_ms(5);
            i++;
            if(i > 99)  i = 0;
            LATB = seg[i / 10];
            LATC = seg[i % 10];
            while(PORTDbits.RD0 == 0);
            __delay_ms(5);
        }
    }
}