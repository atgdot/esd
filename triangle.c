#include "lpc214x.h" 
#include "stdint.h" 

void delay_ms(uint16_t j) 
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
        i=0; 
        while(i!=1023) 
        { 
            DACR=i<<6;	 
            i++; 
        } 
        i=1023;			 
        while(i!=0) 
        { 
            DACR=i<<6; 
            i--; 
        } 
    } 
} 