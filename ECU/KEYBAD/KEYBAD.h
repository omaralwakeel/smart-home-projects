/* 
 * File:   KEYBAD.h
 * Author: OMAR
 *
 * Created on September 11, 2023, 6:42 PM
 */

#ifndef KEYBAD_H
#define	KEYBAD_H

#ifndef rows_number
#define rows_number     4
#endif

#ifndef columns_number
#define columns_number     4
#endif
#include "../../MCAL/LAYPRARIES.h"
#include "../../MCAL/GPIO/GPIO.h"

typedef struct {
    pin_config_t rows[rows_number];
    pin_config_t columns[columns_number];
    uint8 values[rows_number][columns_number];
}KEYPAD_T;
void key_int(KEYPAD_T key);
void get_key(KEYPAD_T key,uint8 *pressed);

#endif	/* KEYBAD_H */

