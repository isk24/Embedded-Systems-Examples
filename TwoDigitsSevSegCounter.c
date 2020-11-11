/* 
 * File:   newmain.c
 * Author: islam
 *
 * Created on April 22, 2018, 3:52 PM
 */

#include "config.h"

void main(){

    TRISC = 0x00;
    LATC = 0x00;
    
    TRISB = 0x00;
    LATB = 0x00;
    
    char seg[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
    
    while(1){
    
        for(char i = 0; i < 100; i++){
            
            LATB = seg[i/10];
            LATC = seg[i%10];
            for(char j = 0; j < 5; j++)    __delay_ms(50);
        }
    
        
    } 
}