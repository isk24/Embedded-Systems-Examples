#include "config.h"

void main(){

    // Set pin as Output
    TRISB0 = 0;
    // Set pin High
    LATB0 = 0;
    
    while(1){
    
        // Toggle LED
        LATB0 = !LATB0;
        // Wait one second
        for(char i = 0; i < 20; i++)
            __delay_ms(50);
    }
}
