#include "7seg.h"

const uint8_t seven_seg_patterns[10] = {
    0b00111111, // 0
    0b00000110, // 1
    0b01011011, // 2
    0b01001111, // 3
    0b01100110, // 4
    0b01101101, // 5
    0b01111101, // 6
    0b00000111, // 7
    0b01111111, // 8
    0b01101111  // 9
};

void seven_seg_init(seven_segmant * seven){

    for(int i=0;i< 8;i++){
        seven->pin[i].direction=GPIO_PIN_OUTPUT;
        GPIO_INTIALIZE_PIN(&(seven->pin[i]));
    }
}

void seven_write(seven_segmant *seven, uint8_t number) {
    if(seven->no_pins_7_or_4==seven_pins){
        if (number >= 0 && number <= 9) {
            // Activate the appropriate segments for the given number
            for (int i = 0; i < seven_pins; i++) {
                if (seven_seg_patterns[number] & (1 << i)) {
                    GPIO_WRITE_LOGIC_PIN(&(seven->pin[i]),GPIO_HIGH); // Turn on the segment
                } else {
                    GPIO_WRITE_LOGIC_PIN(&(seven->pin[i]),GPIO_LOW);  // Turn off the segment
                }
            }
        } else {
            // Invalid number, turn off all segments
            for (int i = 0; i < seven_pins; i++) {
                GPIO_WRITE_LOGIC_PIN(&(seven->pin[i]),GPIO_LOW); // Turn off all segments
            }
        }
    }
    if(seven->no_pins_7_or_4==four_pins){
        if (number >= 0 && number <= 9) {
                GPIO_WRITE_LOGIC_PIN(&(seven->pin[0]), (number & 0x01));
                GPIO_WRITE_LOGIC_PIN(&(seven->pin[1]), (number & 0x02) >> 1);
                GPIO_WRITE_LOGIC_PIN(&(seven->pin[2]), (number & 0x04) >> 2);
                GPIO_WRITE_LOGIC_PIN(&(seven->pin[3]), (number & 0x08) >> 3);
                
            } 
         }
    }


