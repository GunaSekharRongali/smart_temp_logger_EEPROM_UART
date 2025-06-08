#include <msp430.h>
#include "adc.hpp"
ADC adc;
void ADC::init() {
    ADC10CTL1 = INCH_10;                      // Temperature sensor channel
    ADC10CTL0 = SREF_1 + ADC10SHT_3 + REFON + ADC10ON;
    __delay_cycles(1000);                     // Allow Vref to settle
}
int ADC::readTemp() {
    ADC10CTL0 |= ENC + ADC10SC;
    while (ADC10CTL1 & ADC10BUSY);
    return ADC10MEM;
}
