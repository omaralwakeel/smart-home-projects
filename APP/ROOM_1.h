/* 
 * File:   ROOM_1.h
 * Author: OMAR
 *
 * Created on September 18, 2023, 5:12 PM
 */

#ifndef ROOM_1_H
#define	ROOM_1_H


#include "../MCAL/LAYPRARIES.h"
#include "../MCAL/USART/USART.h"
#include "../ECU/LM35/LM35.h"
#include "../ECU/lcd/lcd.h"
#include "../MCAL/TIMER0/TIMER0.h"
#include "../MCAL/TIMER1/TIMER1.h"
#include "../MCAL/GPIO/GPIO.h"
volatile uint16_t timer_count = 0;
char received_data[10];  // Assuming a maximum of 10 characters
uint8 someone_in;
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

TIMER_COUNTER1_T int1={
  .PRESCAL=  PRESCAL_1024,
  .A_and_B=A,
  .OC1_MODE=OC1_DISCON,
  .mode =TIMER,
 
};
TIMER_COUNTER0_T motor={
    .OCO_MODE=CLEAR_OCO,
    .PRESCAL=PRESCAL_64,
    .mode = FAST_PWM_MODE,
};
pin_config_t power_up={
  .direction =GPIO_PIN_OUTPUT,
  .pin=GPIO_PIN1 ,
  .port=GPIO_PORTA,
};
pin_config_t ROOM={
  .direction =GPIO_PIN_INPUT,
  .pin=GPIO_PIN2 ,
  .port=GPIO_PORTA,
};
#endif	/* ROOM_1_H */

