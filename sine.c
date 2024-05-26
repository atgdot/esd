#include "lpc2148.h"
#include "stdint.h"

void delay_ms(unit16_t j){
    uint16_t x,i;
    for(i=0;i<=j;i++){
        for(x=0;x<6000;x++);
    }
}
void main(){
    uint16_t value[] = {512,600,687,768,841,904,955,993,1016,1023,1016,993,995,904,841,768,687,600,512,424,337,256,183,120,69,31,8,0,8,31,69,120,183,256,337,424,512};
    PINSEL1 = 0x00080000;
    while(1){
        for(int i=0;i<37;i++){
            DACR = (value[i]<<6);
        }
    }
}