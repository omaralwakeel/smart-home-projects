/* 
 * File:   USART.h
 * Author: OMAR
 *
 * Created on September 7, 2023, 8:48 PM
 */

#ifndef USART_H
#define	USART_H
#include "../LAYPRARIES.h"

#define RX_INT_EN()                 SET_BIT(UCSRB,RXCIE)
#define RX_INT_DIS()                RESET_BIT(UCSRB,RXCIE)
#define TX_INT_EN()                 SET_BIT(UCSRB,TXCIE)
#define TX_INT_DIS()                RESET_BIT(UCSRB,TXCIE)
#define EMPTY_DATA_INT_EN()         SET_BIT(UCSRB,UDRIE)
#define EMPTY_DATA_INT_DIS()        RESET_BIT(UCSRB,UDRIE)
#define RESIVE_EN()                 SET_BIT(UCSRB,RXEN)
#define RESIVE_DIS()                RESET_BIT(UCSRB,RXEN)
#define TRANSMIT_EN()               SET_BIT(UCSRB,TXEN)
#define TRANSMIT_DIS()              RESET_BIT(UCSRB,TXEN)
#define NINE_BIT_EN()               SET_BIT(UCSRB,RXB8)
#define NINE_BIT_DIS()              RESET_BIT(UCSRB,RXB8)
#define USART_MODE_Asynch()        `RESET_BIT(UCSRC,UMSEL)
#define USART_MODE_Synch()        ` SET_BIT(UCSRC,UMSEL)
#define DIS_POIRT()                 UCSRC&=~(1<<UPM0) & ~(1<<UPM1)
#define EVEN_POIRT()                UCSRC&=~(1<<UPM0) |  (1<<UPM1)
#define ODD_POIRT()                 UCSRC|= (1<<UPM0) |  (1<<UPM1)
#define STOP_1_BIT()                RESET_BIT(UCSRC,USBS)
#define STOP_2_BIT()                SET_BIT(UCSRC,USBS)
#define RAISING_EDGE()              RESET_BIT(UCSSRC,UCPOL)
#define FALLING_EDGE()              SET_BIT(UCSSRC,UCPOL)

#define ONE_BIT                     0
#define TWO_BIT                     1

typedef enum {
    no,
    even,
    odd
}PIORITY_T;



typedef enum{
    five_bit,
    sex_bit,
    seven_bit,
    eight_bit,
    nine_bit
}char_sze_t;

typedef struct{
    uint32 BAUD_RATE;
    uint8  SYNCH_TYPE;
    uint8 NO_STOPBI_BIT;
    uint8 RX_INT_EN;
    uint8 TX_INT_EN;
    uint8 EMPTY_DATA_INT_EN;
    PIORITY_T PIR;
    char_sze_t CHAR_SIZE;
}USART_T;

std_return_type USART_INT(USART_T *usart);
void USART_TRANSIMIT(char DATA);
std_return_type USART_RESIVE_STRING(char *data, uint16_t max_length);
std_return_type USART_RESIVE(char  *DATA);
#endif	/* USART_H */

