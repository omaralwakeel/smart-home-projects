#include "LM35.h"

int16_t lm35_temp(uint8 chanal) {
    // Initialize ADC
    ADC_Init();

    uint16_t ADC_Result = ADC_Read(chanal);
    // Convert ADC value to voltage
    float voltage = (ADC_Result * 5.0) / 1024.0;
    
    // Calculate temperature with support for negative values
    int16_t temperature = (voltage ) * 100.0;

    return temperature;
}
