/* 
 * File:   newmain.c
 * Author: islam
 *
 * Created on July 26, 2022, 10:15 AM
 */

#include "newfile.h"

void main() {

    char seg[] = {0x3f, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

    TRISC = 0;
    TRISD = 0;
    LATD = 0x3f;
    LATC = 0x3F;

    while (1) {

        for (char n = 0; n < 10; n++) {

            LATC = seg[n];
            for (char i = 0; i < 10; i++) {

                LATD = seg[i];
                for (char j = 0; j < 20; j++)
                    __delay_ms(20);
            }
        }
    }
}