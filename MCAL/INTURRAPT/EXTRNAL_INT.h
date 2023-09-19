/* 
 * File:   EXTRNAL_INT.h
 * Author: OMAR
 *
 * Created on August 15, 2023, 6:16 PM
 */

#ifndef EXTRNAL_INT_H
#define	EXTRNAL_INT_H
#include "../LAYPRARIES.h"
#include "interupt_privet.h"
#include "../GPIO/GPIO.h"


typedef void (*InterruptHandler)(void);



typedef enum {
    Extint_enuInt0=0,
    Extint_enuInt1,
    Extint_enuInt2
}Extint_enuIntNum;
// Add these declarations as extern


typedef enum {
	Extint_enuLowLevel=0,
	Extint_enuAnyChange=1,
	Extint_enuFallingEdge=2,
	Extint_enuRisingEdge=3
}Extint_enuIntState;
typedef  struct {
  void(* PtrToHandler)(void) ;
  pin_config_t pin;
  Extint_enuIntNum sourse;
  Extint_enuIntState state;
}EXTINTX_T;



/* ----------------- Software Interfaces Declarations -----------------*/
/**
 * 
 * @param int_obj
 * @return 
 */
std_return_type Interrupt_INTx_Init(const EXTINTX_T *int_obj);

/**
 * 
 * @param int_obj
 * @return 
 */
std_return_type Interrupt_INTx_DeInit(const EXTINTX_T *int_obj);
#endif	/* EXTRNAL_INT_H */

