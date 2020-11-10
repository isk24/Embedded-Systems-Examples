#include "config.h"

void main(){

    TRISC = 0x00;
    LATC = 0x00;
    
    while(1){
    
        for(char i = 0; i < 8; i++){
            
            LATC = 1 << i;
            for(char j = 0; j < 10; j++)    __delay_ms(50);
        }
        
        for(signed char i = 6; i > 0; i--){
            
            LATC = 1 << i;
            for(char j = 0; j < 10; j++)    __delay_ms(50);
        }
        
                
    }
}
