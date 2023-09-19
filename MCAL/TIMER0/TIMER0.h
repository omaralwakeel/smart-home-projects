/* 
 * File:   TIMER0.h
 * Author: OMAR
 *
 * Created on August 18, 2023, 6:24 PM
 */

#ifndef TIMER0_H
#define	TIMER0_H

#include "../LAYPRARIES.h"
#include "../GPIO/GPIO.h"
#include "../INTURRAPT/interupt_privet.h"

#define force_com_enable()                  SET_BIT(TCCR0,FOC0)
#define force_com_disable()                 RESET_BIT(TCCR0,FOC0)

#define NORMAL_MODE()                       TCCR0&=~(1<<WGM00)&~(1<<WGM01)
#define PWM_MODE()                          TCCR0|= (1<<WGM00)&~(1<<WGM01)
#define CTC_MODE()                          TCCR0&=~(1<<WGM00)| (1<<WGM01)
#define FAST_PWM_MODE()                     TCCR0|= (1<<WGM00)| (1<<WGM01)

#define OCO_DISCONECT()                     TCCR0&=~(1<<COM00)&~(1<<COM01)
#define OCO_TOGGLE()                        TCCR0|= (1<<COM00)&~(1<<COM01)
#define OCO_CLEAR()                         TCCR0&=~(1<<COM00)| (1<<COM01)
#define OCO_SET()                           TCCR0|= (1<<COM00)| (1<<COM01)




#define ENABLE_TIMER_OUT_COM_INT()          SET_BIT(TIMSK,OCIE0)
#define DISABLE_TIMER_OUT_COM_INT()         RESET_BIT(TIMSK,OCIE0)

#define ENABLE_TIMER_OVERFLOW_INT()         SET_BIT(TIMSK,TOIE0)
#define DISABLE_TIMER_OVERFLOW_INT()        RESET_BIT(TIMSK,TOIE0)

typedef enum {
    NO_CLOCK=0,
    NO_PRESCAL=1,
    PRESCAL_8=2,
    PRESCAL_64=3,
    PRESCAL_256=4,
    PRESCAL_1024=5,
    FALLING_EAGE=6,
    RAISING_EAGE=7
}PRESCALLER_T;

typedef enum{
    TIMER=0,
    PWM_MODE=1,
    FAST_PWM_MODE=2,
    COUNTER_MODE=3,
    
}TC0_MODE_T;

typedef enum {
    OCO_DISCON=0,
    TOOGLE_OCO=1,
    CLEAR_OCO=2,
    SET_OCO=3,
            
}OCO_MODE_T;
typedef struct{
   TC0_MODE_T mode;
   PRESCALLER_T PRESCAL;
   OCO_MODE_T OCO_MODE;
   void(* PtrToHandler)(void) ;
}TIMER_COUNTER0_T;


std_return_type timer_int(const TIMER_COUNTER0_T  *obj);
std_return_type timer_deint(const TIMER_COUNTER0_T  *obj);
std_return_type delay_ms(const TIMER_COUNTER0_T  *obj,uint32 delay);
void pwm_set_duty(uint8 duty);
void fast_pwm_set_duty(uint8 duty);
;
#endif	/* TIMER0_H */

