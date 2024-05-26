#include "lpc2148.h"
#include "stdint.h"

void delay_ms(unit16_t j){
    uint16_t x,i;
    for(i=0;i<=j;i++){
        for(x=0;x<6000;x++);
    }
}
int main(void){
    PINSEL1 = 0x00080000;
    uint16_t i;
    while(1){
        DACR = 1023<<6;
        for(i=1023;i>=0;i--)
            DACR = i<<6;
    }
}