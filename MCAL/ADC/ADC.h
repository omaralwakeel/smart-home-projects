/* 
 * File:   ADC.h
 * Author: OMAR
 *
 * Created on August 17, 2023, 4:42 PM
 */

#ifndef ADC_H
#define	ADC_H

#include "../LAYPRARIES.h"


void ADC_Init(void);
uint16_t ADC_Read(uint8_t channel);
#endif	/* ADC_H */

