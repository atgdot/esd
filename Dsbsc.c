#include "lpc214x.h"  // Correct include for LPC2148 specific definitions
#include <stdint.h>   // Include standard integer types
#include <math.h>     // Include math functions

#define PI 3.14159265358979323846
#define SAMPLING_RATE 1000 // Sampling rate in Hz
#define CARRIER_FREQ 100    // Carrier frequency in Hz
#define MESSAGE_FREQ 10     // Message frequency in Hz

void delay_us(uint32_t us){
    uint32_t i;
    for(i = 0; i < us * 15; i++); // Rough estimate for 1 microsecond delay
}

int main(){
    uint16_t sample;
    float carrier, message, dsbsc;
    float carrier_phase = 0, message_phase = 0;
    float carrier_step = 2 * PI * CARRIER_FREQ / SAMPLING_RATE;
    float message_step = 2 * PI * MESSAGE_FREQ / SAMPLING_RATE;

    // Configure DAC pin
    PINSEL1 |= 0x00080000; // Select DAC function for P0.25

    while(1){
        for(sample = 0; sample < SAMPLING_RATE; sample++){
            // Generate carrier and message signals
            carrier = sin(carrier_phase);
            message = sin(message_phase);

            // Generate DSBSC signal by multiplying carrier and message
            dsbsc = carrier * message;

            // Scale and shift the signal to fit DAC range (0 to 1023)
            DACR = ((uint32_t)((dsbsc + 1.0) * 511.5)) << 6;

            // Increment phases
            carrier_phase += carrier_step;
            if(carrier_phase >= 2 * PI) carrier_phase -= 2 * PI;

            message_phase += message_step;
            if(message_phase >= 2 * PI) message_phase -= 2 * PI;

            // Delay to achieve the sampling rate
            delay_us(1000); // Delay to achieve a 1 kHz sampling rate
        }
    }
}
