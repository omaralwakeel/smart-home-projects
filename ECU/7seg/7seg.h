/* 
 * File:   7seg.h
 * Author: OMAR
 *
 * Created on September 15, 2023, 9:19 PM
 */

#ifndef SEG_H
#define	SEG_H
#include "../../MCAL/GPIO/GPIO.h"
#define anoud                   0
#define seven_pins              7
#define four_pins               4

typedef struct {
    pin_config_t pin[7];
    uint8 anoud_casod;
    uint8 no_pins_7_or_4;
}seven_segmant;

extern  const uint8_t seven_seg_patterns[10] ;

void seven_seg_init(seven_segmant * seven);
void seven_write(seven_segmant *seven, uint8_t number) ;
#endif	/* 7SEG_H */

