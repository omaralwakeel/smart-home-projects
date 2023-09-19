 /* 
 * File:   GPIO.h
 * Author: OMAR
 *
 * Created on August 15, 2023, 12:18 PM
 */

#ifndef GPIO_H
#define	GPIO_H

#include "../LAYPRARIES.h"

#define GPIO_PORTA_DIR     DDRA
#define GPIO_PORTA_PIN     PINA
#define GPIO_PORTA_PORT    PORTA

#define GPIO_PORTB_DIR     DDRB
#define GPIO_PORTB_PIN     PINB
#define GPIO_PORTB_PORT    PORTB

#define GPIO_PORTC_DIR     DDRC
#define GPIO_PORTC_PIN     PINC
#define GPIO_PORTC_PORT    PORTC

#define GPIO_PORTD_DIR     DDRD
#define GPIO_PORTD_PIN     PIND
#define GPIO_PORTD_PORT    PORTD

/* GPIO Pin Directions */
#define GPIO_PIN_INPUT     0
#define GPIO_PIN_OUTPUT    1

/* GPIO Pin Levels */
#define GPIO_LOW           0
#define GPIO_HIGH          1

/* GPIO Port Indices */
#define GPIO_PORTA_INDEX   0
#define GPIO_PORTB_INDEX   1
#define GPIO_PORTC_INDEX   2
#define GPIO_PORTD_INDEX   3

/* GPIO Pin Indices */
#define GPIO_PIN0_INDEX    0
#define GPIO_PIN1_INDEX    1
#define GPIO_PIN2_INDEX    2
#define GPIO_PIN3_INDEX    3
#define GPIO_PIN4_INDEX    4
#define GPIO_PIN5_INDEX    5
#define GPIO_PIN6_INDEX    6
#define GPIO_PIN7_INDEX    7

/*section :data type DEclaration*/

typedef enum {
    GPIO_PIN0 = GPIO_PIN0_INDEX,
	GPIO_PIN1 = GPIO_PIN1_INDEX,
	GPIO_PIN2 = GPIO_PIN2_INDEX,
	GPIO_PIN3 = GPIO_PIN3_INDEX,
	GPIO_PIN4 = GPIO_PIN4_INDEX,
	GPIO_PIN5 = GPIO_PIN5_INDEX,
	GPIO_PIN6 = GPIO_PIN6_INDEX,
	GPIO_PIN7 = GPIO_PIN7_INDEX
           
}gpio_pin_t;

typedef enum {
    GPIO_PORTA = GPIO_PORTA_INDEX,
	GPIO_PORTB = GPIO_PORTB_INDEX,
	GPIO_PORTC = GPIO_PORTC_INDEX,
	GPIO_PORTD = GPIO_PORTD_INDEX
} gpio_port_t;

typedef struct {
    gpio_port_t port;
    gpio_pin_t pin;
    uint8   direction ;
}pin_config_t;

/******************function interface***************/
std_return_type GPIO_INTIALIZE_PIN(pin_config_t *PIN_OBJ);
std_return_type GPIO_WRITE_LOGIC_PIN(pin_config_t *PIN_OBJ,uint8 logic);
std_return_type GPIO_READ_LOGIC_PIN(pin_config_t *PIN_OBJ,uint8 *data);
std_return_type GPIO_TOGGLE_PIN(pin_config_t *PIN_OBJ);

std_return_type GPIO_INTIALIZE_PORT(pin_config_t *PIN_OBJ);
std_return_type GPIO_WRITE_LOGIC_PORT(pin_config_t *PIN_OBJ,uint8 logic);
std_return_type GPIO_READ_LOGIC_PORT(pin_config_t *PIN_OBJ,uint8 *data);
std_return_type GPIO_TOGGLE_PORT(pin_config_t *PIN_OBJ);
#endif	/* GPIO_H */

