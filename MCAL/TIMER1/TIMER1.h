/* 
 * File:   TIMER1.h
 * Author: OMAR
 *
 * Created on August 23, 2023, 12:01 PM
 */

#ifndef TIMER1_H
#define	TIMER1_H

#include "../LAYPRARIES.h"


#define force_coma_enable()                  SET_BIT(TCCR1A,FOC1A)
#define force_coma_disable()                 RESET_BIT(TCCR1A,FOC1A)


#define force_comb_enable()                  SET_BIT(TCCR1A,FOC1B)
#define force_comb_disable()                 RESET_BIT(TCCR1A,FOC1B)

        

#define OC1A_DISCONECT()                     TCCR1A&=~(1<<COM1A0)&~(1<<COM1A1)
#define OC1A_TOGGLE()                        TCCR1A|= (1<<COM1A0)&~(1<<COM1A1)
#define OC1A_CLEAR()                         TCCR1A&=~(1<<COM1A0)| (1<<COM1A1)
#define OC1A_SET()                           TCCR1A|= (1<<COM1A0)| (1<<COM1A1)

#define OC1B_DISCONECT()                     TCCR1A&=~(1<<COM1B0)&~(1<<COM1B1)
#define OC1B_TOGGLE()                        TCCR1A|= (1<<COM1B0)&~(1<<COM1B1)
#define OC1B_CLEAR()                         TCCR1A&=~(1<<COM1B0)| (1<<COM1B1)
#define OC1B_SET()                           TCCR1A|= (1<<COM1B0)| (1<<COM1B1)

#define IC_NOIS_CANSELER()                   TCCR1B|= (1<<ICNC1)

#define IC_EDGE_SELCTOR()                    TCCR1B|= (1<<ICES1)

#define ENABLE_TIMER_IC_INT()                SET_BIT(TIMSK,OCIE1)
#define DISABLE_TIMER_IC_INT()               RESET_BIT(TIMSK,OCIE1)

#define ENABLE_TIMER_OVERFLOWA_INT()         SET_BIT(TIMSK,TOIE1)
#define DISABLE_TIMER_OVERFLOWA_INT()        RESET_BIT(TIMSK,TOIE1)


typedef enum {
    NO_CLOCK_1=0,
    NO_PRESCAL_1=1,
    PRESCAL_8_1=2,
    PRESCAL_64_1=3,
    PRESCAL_256_1=4,
    PRESCAL_1024_1=5,
    FALLING_EAGE_1=6,
    RAISING_EAGE_1=7
}PRESCALLER1_T;

typedef enum{
    TIMER_1=0,
    PWM_MODE_ICR=1,
    PWM_MODE_OCRA=2,
    FAST_PWM_MODE_ICR=3,
    FAST_PWM_MODE_OCRA=4,
    COUNTER_MODE_1=5,
    CTC_MODE,
}TC1_MODE_T;

typedef enum {
    OC1_DISCON=0,
    TOOGLE_OC1=1,
    CLEAR_OC1=2,
    SET_OC1=3,
            
}OC1_MODE_T;

typedef enum {
    A,
    B,
    BOTH,
}A_and_B_T;
typedef struct{
   TC1_MODE_T mode;
   PRESCALLER1_T PRESCAL;
   OC1_MODE_T OC1_MODE;
   void(* PtrToHandler)(void) ;
   uint8 PIN ;
   A_and_B_T A_and_B;
}TIMER_COUNTER1_T;
void Timer1_int(TIMER_COUNTER1_T *timer);
// Initialize Timer/Counter1 for PWM generation with ICR1A as TOP
void Timer1_PWM(uint16_t frequency, uint8_t dutyCycle);

// Initialize Timer/Counter1 for Input Capture mode
void Timer1_InputCapture(void);

// Initialize Timer/Counter1 for generating periodic interrupts
void Timer1_PeriodicInterrupt(uint16_t interval);

// Initialize Timer/Counter1 in Normal mode
void Timer1_NormalMode(void);

// Read the current counter value of Timer/Counter1
uint16_t Timer1_ReadCounter(void);

#endif	/* TIMER1_H */

