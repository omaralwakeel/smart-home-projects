#include "TIMER0.h"


static std_return_type timer_prescal(const TIMER_COUNTER0_T  *obj);
static std_return_type timer_mode(const TIMER_COUNTER0_T  *obj);
static std_return_type OCO_mode(const TIMER_COUNTER0_T  *obj);
volatile uint32 prescal;
std_return_type timer_int(const TIMER_COUNTER0_T  *obj){
    std_return_type ret=E_OK;
    if(obj==NULL){
        ret=E_NOT_OK;
    }
    else{
        ret=E_OK;
        timer_mode(obj);
        timer_prescal(obj);
        OCO_mode(obj);
    }
    return ret;
}
std_return_type timer_deint(const TIMER_COUNTER0_T  *obj);

std_return_type delay_ms(const TIMER_COUNTER0_T  *obj,uint32 delay){
    TCNT0 = 0;
    uint32 ticks=((F_CPU/prescal)*delay)/1000;
    while (TCNT0 < ticks) {
        // Wait
    }
    
    // Stop the timer
    TCCR0 = 0;
    TCNT0 = 0;
}
void pwm_set_duty(uint8 duty){
    // Set duty cycle using OCR0
    OCR0 = (duty * 255) / 100;
}
void fast_pwm_set_duty(uint8 duty){
    // Set duty cycle using OCR0
    OCR0 = (duty * 255) / 100;
}


volatile uint16_t event_count = 0;
static std_return_type timer_prescal(const TIMER_COUNTER0_T  *obj){
    std_return_type ret=E_OK;
    if(obj==NULL){
        ret=E_NOT_OK;
    }
    else{
        ret=E_OK;
        switch(obj->PRESCAL){
            case NO_CLOCK:
                RESET_BIT(TCCR0,CS00);
                RESET_BIT(TCCR0,CS01);
                RESET_BIT(TCCR0,CS02);
                break;
            case NO_PRESCAL:
                SET_BIT(TCCR0,CS00);
                RESET_BIT(TCCR0,CS01);
                RESET_BIT(TCCR0,CS02);
                prescal=1;
                break;
            case PRESCAL_8:
                RESET_BIT(TCCR0,CS00);
                SET_BIT(TCCR0,CS01);
                RESET_BIT(TCCR0,CS02);
                prescal=8;
                break;
            case PRESCAL_64:
                SET_BIT(TCCR0,CS00);
                SET_BIT(TCCR0,CS01);
                RESET_BIT(TCCR0,CS02);
                prescal=64;
                break;
            case PRESCAL_256:
                RESET_BIT(TCCR0,CS00);
                RESET_BIT(TCCR0,CS01);
                SET_BIT(TCCR0,CS02);
                prescal=256;
                break;
            case PRESCAL_1024:
                SET_BIT(TCCR0,CS00);
                RESET_BIT(TCCR0,CS01);
                SET_BIT(TCCR0,CS02);
                prescal=1024;
                break;
            case FALLING_EAGE:
                RESET_BIT(TCCR0,CS00);
                SET_BIT(TCCR0,CS01);
                SET_BIT(TCCR0,CS02);
                break;
            case RAISING_EAGE:
                SET_BIT(TCCR0,CS00);
                SET_BIT(TCCR0,CS01);
                SET_BIT(TCCR0,CS02);
                break;
            
        }
    }
    return ret;
}
static std_return_type timer_mode(const TIMER_COUNTER0_T  *obj){
    std_return_type ret=E_OK;
    if(obj==NULL){
        ret=E_NOT_OK;
    }
    else{
        ret=E_OK;
        switch(obj->mode){
            case TIMER:
                NORMAL_MODE();
                ENABLE_TIMER_OVERFLOW_INT();
                Enable_Globle_Interrupt();
                break;
            case PWM_MODE:
                DDRB |= (1 << PB3);
                
                PWM_MODE();
                break;
            case FAST_PWM_MODE:
                FAST_PWM_MODE();
                DDRB |= (1 << PB3);
                break;
            case COUNTER_MODE:
                DDRB&=~(1<<PB0);
                break;
        }
    }
    return ret;
}

static std_return_type OCO_mode(const TIMER_COUNTER0_T  *obj){
    std_return_type ret=E_OK;
    if(obj==NULL){
        ret=E_NOT_OK;
    }
    else{
        ret=E_OK;
        switch(obj->OCO_MODE){
            case OCO_DISCON:
                RESET_BIT(TCCR0,COM00);
                RESET_BIT(TCCR0,COM01);
                break;
            case TOOGLE_OCO:
                SET_BIT(TCCR0,COM00);
                RESET_BIT(TCCR0,COM01);
                break;
            case CLEAR_OCO:
                RESET_BIT(TCCR0,COM00);
                SET_BIT(TCCR0,COM01);
                break;
            case SET_OCO:
                SET_BIT(TCCR0,COM00);
                SET_BIT(TCCR0,COM01);
                
                break;
        }
    }
    return ret;
}





ISR(TIMER0_CAPT_vect) {
    event_count++;
}