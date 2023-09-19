/* 
 * File:   LOCKER.h
 * Author: OMAR
 *
 * Created on September 17, 2023, 4:32 PM
 */

#ifndef LOCKER_H
#define	LOCKER_H
#include "../MCAL/LAYPRARIES.h"
#include "../MCAL/USART/USART.h"
#include "../ECU/7seg/7seg.h"
#include "../ECU/KEYBAD/KEYBAD.h"
#include "../ECU/lcd/lcd.h"
#include "../MCAL/TIMER0/TIMER0.h"
 // Initialize keypad with desired settings
char pass[4];
uint8 press=0;
const char ROOM_1_PASS[]="5647";
const char ROOM_2_PASS[]="7894";
const char ROOM_3_PASS[]="1234";
int WRONG_PASS=0;
KEYPAD_T KEY={
    .rows[0].pin=GPIO_PIN0,
    .rows[0].port=GPIO_PORTA,
    .rows[0].direction=GPIO_PIN_OUTPUT,
    .rows[1].pin=GPIO_PIN1,
    .rows[1].port=GPIO_PORTA,
    .rows[1].direction=GPIO_PIN_OUTPUT,
    .rows[2].pin=GPIO_PIN2,
    .rows[2].port=GPIO_PORTA,
    .rows[2].direction=GPIO_PIN_OUTPUT,
    .rows[3].pin=GPIO_PIN3,
    .rows[3].port=GPIO_PORTA,
    .rows[3].direction=GPIO_PIN_OUTPUT,
    
    .columns[0].pin=GPIO_PIN4,
    .columns[0].port=GPIO_PORTA,
    .columns[0].direction=GPIO_PIN_INPUT,
    .columns[1].pin=GPIO_PIN5,
    .columns[1].port=GPIO_PORTA,
    .columns[1].direction=GPIO_PIN_INPUT,
    .columns[2].pin=GPIO_PIN6,
    .columns[2].port=GPIO_PORTA,
    .columns[2].direction=GPIO_PIN_INPUT,
    .columns[3].pin=GPIO_PIN7,
    .columns[3].port=GPIO_PORTA,
    .columns[3].direction=GPIO_PIN_INPUT,
    

    .values={
        {55,56,57,92},
        {52,53,54,42},
        {49,50,51,43},
        {78,48,61,45}
    },
};

// Initialize USART with desired settings
USART_T uart = {
    .BAUD_RATE = 9600,
    .SYNCH_TYPE = 0,  // Asynchronous mode
    .NO_STOPBI_BIT = 0,  // 1 stop bit
    .RX_INT_EN = 0,  // RX interrupt disabled
    .TX_INT_EN = 0,  // TX interrupt disabled
    .EMPTY_DATA_INT_EN = 0,  // Empty data interrupt disabled
    .PIR = even,  // Even parity
    .CHAR_SIZE = eight_bit  // 8-bit character size
    };

TIMER_COUNTER0_T motor={
    .OCO_MODE=CLEAR_OCO,
    .PRESCAL=PRESCAL_64,
    .mode = FAST_PWM_MODE,
};

#endif	/* LOCKER_H */

