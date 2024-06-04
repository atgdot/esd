#include "lpc214x.h"  // LPC2148 specific definitions
#include <stdint.h>   // Standard integer types
#include <math.h>     // Math functions

#define PI 3.14159265358979323846
#define SAMPLING_RATE 1000 // Sampling rate in Hz
#define MESSAGE_FREQ 10     // Message frequency in Hz

void delay_us(uint32_t us){
    uint32_t i;
    for(i = 0; i < us * 15; i++); // Rough estimate for 1 microsecond delay
}

int main(){
    uint16_t sample;
    float message;
    float message_phase = 0;
    float message_step = 2 * PI * MESSAGE_FREQ / SAMPLING_RATE;

    // Configure DAC pin
    PINSEL1 |= 0x00080000; // Select DAC function for P0.25

    while(1){
        for(sample = 0; sample < SAMPLING_RATE; sample++){
            // Generate message signal (analog input)
            message = sin(message_phase);

            // Quantize the message signal to 8-bit PCM
            uint8_t pcm_sample = (uint8_t)((message + 1.0) * 127.5); // Scale and shift to 0-255 range

            // Scale PCM sample to fit DAC range (0 to 1023)
            DACR = ((uint32_t)pcm_sample * 4) << 6; // Scale from 0-255 to 0-1023

            // Increment phase
            message_phase += message_step;
            if(message_phase >= 2 * PI) message_phase -= 2 * PI;

            // Delay to achieve the sampling rate
            delay_us(1000); // Delay to achieve a 1 kHz sampling rate
        }
    }
}
