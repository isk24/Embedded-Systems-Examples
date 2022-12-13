/* 
 * File:   main.c
 * Author: islam
 *
 * Created on April 5, 2016, 2:25 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "System.h"

#define Digit1 LATDbits.LATD0
#define Digit2 LATDbits.LATD1

void main (){

    unsigned char Segment_Map[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
    
    TRISB = 0x00;
    TRISD = 0x00;
    OSCCON = 0x76;
    
    Digit1 = 0;
    Digit2 = 0;
    
    while(1){
    
        for(char i = 0; i < 99; i++){
        
            for(char j = 0; j < 50; j++){
                
                LATB = Segment_Map[i%10];

                Digit1 = 1; Digit2 = 0;       
                __delay_ms(10);
                Digit1 = 0; Digit2 = 1; 

                LATB = Segment_Map[i/10];
                __delay_ms(10);
            }
	}
    }
}
