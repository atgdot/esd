#include "lpc2148.h"
#include "stdint.h"

void delay_ms(uint16_t j)
{
    uint16_t x,i;
    for(i=0;i<j;i++)
    {
        for(x=0;x<6000;x++);
    }
}

void main()
{
    // Define the waveforms for QPSK with different phase shifts
    uint16_t value1[] = {512,600,687,768,841,904,955,993,1016,1023,1016,993,955,904,841,768,687,600,512,424,337,256,183,120,69,31,8,0,8,31,69,120,183,256,337,424,512};

    uint16_t value2[] = {710, 666, 620, 574, 531, 491, 455, 423, 396, 374, 358, 349, 346, 351, 362, 379, 401, 428, 458, 490, 524, 558, 591, 621, 647, 668, 682, 688, 684, 670, 645, 609, 563, 511, 456, 401, 352};

    uint16_t value3[] = {0,8,31,69,120,183,256,337,424,512,600,687,768,841,904,955,993,1016,1023,1016,993,955,904,841,768,687,600,512,424,337,256,183,120,69,31,8,0};

    // Example binary message to be transmitted using QPSK
    uint16_t msg[] = {0,1,0,2,0,3,0,0};

    PINSEL1 = 0x00080000; // Configure DAC output pin

    while (1)
    {
        for(int j=0; j<8; j++)
        {
            switch (msg[j])
            {
                case 0:
                    {
                        for(int i=0; i<37; i++)
                        {
                            DACR = (value1[i] << 6);
                            //delay_ms(1); // Adjust the delay to change the frequency
                        }
                    }
                    break;

                case 1:
                    {
                        for(int i=0; i<37; i++)
                        {
                            DACR = (value2[i] << 6);
                            //delay_ms(1); // Adjust the delay to change the frequency
                        }
                    }
                    break;

                case 2:
                    {
                        for(int i=36; i>=0; i--)
                        {
                            DACR = (value3[i] << 6);
                            //delay_ms(1); // Adjust the delay to change the frequency
                        }
                    }
                    break;

                case 3:
                    {
                        for(int i=36; i>=0; i--)
                        {
                            DACR = (value1[i] << 6);
                            //delay_ms(1); // Adjust the delay to change the frequency
                        }
                    }
                    break;
            }
        }
    }
}
