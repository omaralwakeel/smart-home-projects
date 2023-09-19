#include "ADC.h"
void ADC_Init(void) {
    ADMUX |= (1 << REFS0); // Set reference voltage to AVCC
    ADCSRA |= (1 << ADEN); // Enable the ADC
    ADCSRA |= (1 << ADSC); // Start the first conversion
    ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Set ADC prescaler to 128
}

// Read ADC value from a specified channel
uint16_t ADC_Read(uint8_t channel) {
    ADMUX &= 0xF0;       // Clear the previous channel selection
    ADMUX |= channel;    // Select the new channel
    ADCSRA |= (1 << ADSC); // Start the conversion
    while (ADCSRA & (1 << ADSC)); // Wait for the conversion to complete
    return ADC;          // Return the ADC result
}