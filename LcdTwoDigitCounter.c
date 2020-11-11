#include "lcd.h"

void main(void) {
    
    LCD_Initialize();

    while (1) {
        
        for(char i = 0; i < 100; i++){
            
            LCDGoto(0, 0);
            LCDPutChar(i/10 + 48);
            LCDGoto(1, 0);
            LCDPutChar(i%10 + 48);
            for(char j = 0; j < 5; j++)    __delay_ms(50);
        }
    }
}