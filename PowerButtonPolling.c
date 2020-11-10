/* 
 * File:   newmain.c
 * Author: islam
 *
 * Created on August 18, 2019, 11:38 PM
 */


#include "config.h"

bit power_led;

void main() {

    unsigned char counter;

    TRISB0 = 0;
    TRISB1 = 0;
    TRISB2 = 1;

    LATB0 = 0;
    LATB1 = 0;


    while (1) {

        if (!PORTBbits.RB2) {

            __delay_ms(10);

            while (!PORTBbits.RB2) {

                __delay_ms(10);
                counter++;

                if (counter >= 99) {

                    LATB0 = 1;
                    power_led = 0;
                }
            }

            if (power_led) {

                LATB1 = 1;
            }
        }

        counter = 0;
        power_led = 1;
    }
}

