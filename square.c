#include "lpc214x.h" 
#include "stdint.h"
 
voiddelay_ms(uint16_t j) 
{ 
    uint16_tx,i; 
    for(i=0;i<j;i++) 
    { 
        for(x=0; x<6000; x++);    /* loop to generate 1 milisecond delay with Cclk = 60MHz */ 
    } 
} 
int main (void) 
{ 
    uint16_t value; 
    uint16_ti = 0; 
    PINSEL1 = 0x00080000;	/* P0.25 as DAC output */ 
    IO0DIR = 0xFFFFFFFF; /* Input pins for switch. P0.8 sine, P0.9 triangular, P0.10 sawtooth, P0.11 square */ 
    while(1) 
    { 
        DACR=1023<<6;	 
        delay_ms(10); 
        DACR=0;			 
        delay_ms(10); 
    } 
} 