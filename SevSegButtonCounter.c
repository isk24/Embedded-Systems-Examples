/* 
 * File:   newmain.c
 * Author: islam
 *
 * Created on July 26, 2022, 10:15 AM
 */

#include "config.h"

void main() {

    char i = 0, seg[10] = {0x3f, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
 
    TRISC = 0;
    TRISD = 0;
    TRISB0 = 1;

    LATC = 0x3F;
    LATD = 0x3F;

    while (1) {

        if (PORTBbits.RB0 == 0) {

            __delay_ms(5);
            while (PORTBbits.RB0 == 0) {

                i++;
                if (i > 99) i = 0;
                LATC = seg[i / 10];
                LATD = seg[i % 10];
                for(char i = 0; i < 10; i++)
                    __delay_ms(40);
            }
            __delay_ms(5);
        }
    }
}
