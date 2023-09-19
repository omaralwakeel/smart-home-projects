#include "TIMER1.h"

static void prescaler_set(TIMER_COUNTER1_T *timer);
static void OC1_MODE_SET(TIMER_COUNTER1_T *timer);
static void tc1_mode_set(TIMER_COUNTER1_T *timer);
void Timer1_int(TIMER_COUNTER1_T *timer){
    prescaler_set(timer);
    OC1_MODE_SET(timer);
    tc1_mode_set(timer);
}
// Initialize Timer/Counter1 for PWM generation with ICR1A as TOP
volatile uint32 prescal_one ;
void Timer1_PWM(uint16_t frequency, uint8_t dutyCycle){
     // Calculate the TOP value (ICR1A) based on the desired frequency
    uint16_t top_value = (F_CPU / (2 * frequency/prescal_one)) - 1;
    ICR1 = top_value;

    // Set the duty cycle by adjusting the OCR1A value
    uint16_t duty_value = (top_value * dutyCycle) / 100;
    OCR1A = duty_value;

    // Set the prescaler to clock source (no prescaling)
    TCCR1B |= (1 << CS10);
}

// Initialize Timer/Counter1 for Input Capture mode
void Timer1_InputCapture(void){
    // Set Waveform Generation Mode to Normal mode
    TCCR1A = 0x00;
    TCCR1B = 0x00;

    // Enable Input Capture Noise Canceler and Rising Edge trigger
    TCCR1B |= (1 << ICNC1) | (1 << ICES1);

    // Enable Timer/Counter1 Input Capture interrupt (optional)
    TIMSK |= (1 << TICIE1);
}

// Initialize Timer/Counter1 for generating periodic interrupts
void Timer1_PeriodicInterrupt(uint16_t interval){
    
    // Enable Timer/Counter1 Compare Match A interrupt
    OCR1A = interval;
    TIMSK |= (1 << OCIE1A);
}


// Read the current counter value of Timer/Counter1
uint16_t Timer1_ReadCounter(void){
    // Read the current counter value from TCNT1
    return TCNT1;
}



static void prescaler_set(TIMER_COUNTER1_T *timer){
    switch(timer->PRESCAL){
        case NO_CLOCK_1:
            RESET_BIT(TCCR1B,CS10);
            RESET_BIT(TCCR1B,CS11);
            RESET_BIT(TCCR1B,CS12);
            break;
        case NO_PRESCAL_1:
            SET_BIT(TCCR1B,CS10);
            RESET_BIT(TCCR1B,CS11);
            RESET_BIT(TCCR1B,CS12);
            prescal_one=1;
            break;
        case PRESCAL_8_1:
            RESET_BIT(TCCR1B,CS10);
            SET_BIT(TCCR1B,CS11);
            RESET_BIT(TCCR1B,CS12);
            prescal_one=8;
            break;
        case PRESCAL_64_1:
            SET_BIT(TCCR1B,CS10);
            SET_BIT(TCCR1B,CS11);
            RESET_BIT(TCCR1B,CS12);
            prescal_one=64;
            break;
        case PRESCAL_256_1:
            RESET_BIT(TCCR1B,CS10);
            RESET_BIT(TCCR1B,CS11);
            SET_BIT(TCCR1B,CS12);
            prescal_one=256;
            break;
        case PRESCAL_1024_1:
            SET_BIT(TCCR1B,CS10);
            RESET_BIT(TCCR1B,CS11);
            SET_BIT(TCCR1B,CS12);
            prescal_one=1024;
            break;
        case FALLING_EAGE_1:
            RESET_BIT(TCCR1B,CS10);
            SET_BIT(TCCR1B,CS11);
            SET_BIT(TCCR1B,CS12);
            break;
        case RAISING_EAGE_1:
            SET_BIT(TCCR1B,CS10);
            SET_BIT(TCCR1B,CS11);
            SET_BIT(TCCR1B,CS12);
            break;
            
        }
}
static void OC1_MODE_SET(TIMER_COUNTER1_T *timer){
    switch(timer->A_and_B){
        case A:
           switch(timer->OC1_MODE){
            case OC1_DISCON:
                RESET_BIT(TCCR1A,COM1A0);
                RESET_BIT(TCCR1A,COM1A1);
                break;
            case TOOGLE_OC1:
                SET_BIT(TCCR1A,COM1A0);
                RESET_BIT(TCCR1A,COM1A1);
                break;
            case CLEAR_OC1:
                RESET_BIT(TCCR1A,COM1A0);
                SET_BIT(TCCR1A,COM1A1);
                break;
            case SET_OC1:
                SET_BIT(TCCR1A,COM1A0);
                SET_BIT(TCCR1A,COM1A1);
                
                break;
        }
        case B:
           switch(timer->OC1_MODE){
            case OC1_DISCON:
                RESET_BIT(TCCR1A,COM1B0);
                RESET_BIT(TCCR1A,COM1B1);
                break;
            case TOOGLE_OC1:
                SET_BIT(TCCR1A,COM1B0);
                RESET_BIT(TCCR1A,COM1B1);
                break;
            case CLEAR_OC1:
                RESET_BIT(TCCR1A,COM1B0);
                SET_BIT(TCCR1A,COM1B1);
                break;
            case SET_OC1:
                SET_BIT(TCCR1A,COM1B0);
                SET_BIT(TCCR1A,COM1B1);
                
                break;
        }
        case BOTH:
          switch(timer->OC1_MODE){
            case OC1_DISCON:
                RESET_BIT(TCCR1A,COM1B0);
                RESET_BIT(TCCR1A,COM1B1);
                RESET_BIT(TCCR1A,COM1A0);
                RESET_BIT(TCCR1A,COM1A1);
                break;
            case TOOGLE_OC1:
                SET_BIT(TCCR1A,COM1A0);
                RESET_BIT(TCCR1A,COM1A1);
                SET_BIT(TCCR1A,COM1B0);
                RESET_BIT(TCCR1A,COM1B1);
                break;
            case CLEAR_OC1:
                RESET_BIT(TCCR1A,COM1A0);
                SET_BIT(TCCR1A,COM1A1);
                RESET_BIT(TCCR1A,COM1B0);
                SET_BIT(TCCR1A,COM1B1);
                break;
            case SET_OC1:
                SET_BIT(TCCR1A,COM1A0);
                SET_BIT(TCCR1A,COM1A1);
                SET_BIT(TCCR1A,COM1B0);
                SET_BIT(TCCR1A,COM1B1);
                
                break;
        } 
        
    }
}
static void tc1_mode_set(TIMER_COUNTER1_T *timer){
    switch(timer->mode){
        case TIMER_1:
            TCCR1A &=~(1<<WGM10);
            TCCR1A &=~(1<<WGM11);
            TCCR1B &=~(1<<WGM12);
            TCCR1B &=~(1<<WGM13);
            TIMSK  |= (1<<TOIE1);
            TCNT1 = 0;
            SET_BIT(SREG,SREG_I);
            break;
        
        case CTC_MODE:
            TCCR1A &=~(1<<WGM10);
            TCCR1A &=~(1<<WGM11);
            TCCR1B |= (1<<WGM12);
            TCCR1B &=~(1<<WGM13);
            break;
        case PWM_MODE_ICR:
            TCCR1A &=~(1<<WGM10);
            TCCR1A &=~(1<<WGM11);
            TCCR1B &=~(1<<WGM12);
            TCCR1B |= (1<<WGM13);
            break;
        case PWM_MODE_OCRA:
            TCCR1A |= (1<<WGM10);
            TCCR1A &=~(1<<WGM11);
            TCCR1B &=~(1<<WGM12);
            TCCR1B |= (1<<WGM13);
            break;
        case FAST_PWM_MODE_ICR:
            TCCR1A &=~(1<<WGM10);
            TCCR1A |= (1<<WGM11);
            TCCR1B |= (1<<WGM12);
            TCCR1B |= (1<<WGM13);
            break;
        case FAST_PWM_MODE_OCRA:
            TCCR1A |= (1<<WGM10);
            TCCR1A |= (1<<WGM11);
            TCCR1B |= (1<<WGM12);
            TCCR1B |= (1<<WGM13);
            break;
        case COUNTER_MODE_1:
            TCCR1A=0X00;
            SET_BIT(SREG,SREG_I);
            break;
    }
}
