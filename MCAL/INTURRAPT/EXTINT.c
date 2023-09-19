#include "EXTRNAL_INT.h"


static InterruptHandler INT0_InterruptHandler = NULL;
static InterruptHandler INT1_InterruptHandler = NULL;
static InterruptHandler INT2_InterruptHandler = NULL;
std_return_type Interrupt_INTx_Init(const EXTINTX_T *int_obj){
    std_return_type ret=E_OK;
    if(int_obj==NULL){
        ret=E_NOT_OK;
    }else{
        ret=E_OK;
        pin_config_t local_pin = int_obj->pin;
        GPIO_INTIALIZE_PIN(&local_pin);
        GPIO_WRITE_LOGIC_PIN(&local_pin,GPIO_HIGH);
        // Now, you can modify the local_pin object
        
        switch(int_obj->sourse){
            case Extint_enuInt0:
                Clear_INTF0();
                switch(int_obj->state){
            case Extint_enuLowLevel:
                MCUCR&=~(1<<ISC00)&~(1<<ISC01);
                break;
            case Extint_enuAnyChange:
                MCUCR|=(1<<ISC00)&~(1<<ISC01);
                break;
            case Extint_enuFallingEdge:
                MCUCR&=~(1<<ISC00)| (1<<ISC01);
                break;
            case Extint_enuRisingEdge:
                MCUCR|= (1<<ISC00) | (1<<ISC01);
                break;
        }
                Enable_EXINT0();
                INT0_InterruptHandler = int_obj->PtrToHandler;

            case Extint_enuInt1:
                Clear_INTF1();
                  switch(int_obj->state){
            case Extint_enuLowLevel:
                MCUCR&=~(1<<ISC10)&~(1<<ISC11);
                break;
            case Extint_enuAnyChange:
                MCUCR|=(1<<ISC10)&~(1<<ISC11);
                break;
            case Extint_enuFallingEdge:
                MCUCR&=~(1<<ISC10)| (1<<ISC11);
                break;
            case Extint_enuRisingEdge:
                MCUCR|= (1<<ISC10) | (1<<ISC11);
                break;
        }
                Enable_EXINT1();
                INT1_InterruptHandler = int_obj->PtrToHandler;
            
            case Extint_enuInt2:
                Clear_INTF2();
                if(int_obj->state==Extint_enuFallingEdge){RESET_BIT(MCUCSR,ISC2);}
                else {SET_BIT(MCUCSR,ISC2);}
                
                Enable_EXINT2();
        }
      Enable_Globle_Interrupt();  
    }
   
    return ret;
}






/**
 * External Interrupt 0 MCAL Helper function 
 */
 ISR(INT0_vect){
    /* The INT0 external interrupt occurred (must be cleared in software) */
    Clear_INTF0();
    /* Code : To be executed from MCAL Interrupt Context */
    /* Application Callback function gets called every time this ISR executes */
    if(INT0_InterruptHandler){ INT0_InterruptHandler(); }
    else{ /* Nothing */ }
}

/**
 * External Interrupt 1 MCAL Helper function 
 */
ISR(INT1_vect){
    /* The INT0 external interrupt occurred (must be cleared in software) */
    Clear_INTF1();
    /* Code : To be executed from MCAL Interrupt Context */
    /* Application Callback function gets called every time this ISR executes */
    if(INT1_InterruptHandler){ INT1_InterruptHandler(); }
    else{ /* Nothing */ }
}
ISR(INT2_vect){
    /* The INT0 external interrupt occurred (must be cleared in software) */
    Clear_INTF2();
    /* Code : To be executed from MCAL Interrupt Context */
    /* Application Callback function gets called every time this ISR executes */
    if(INT2_InterruptHandler){ INT2_InterruptHandler(); }
    else{ /* Nothing */ }
}
