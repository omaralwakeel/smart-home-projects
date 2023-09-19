/* 
 * File:   newfile.h
 * Author: OMAR
 *
 * Created on August 15, 2023, 7:46 PM
 */

#ifndef NEWFILE_H
#define	NEWFILE_H
#include <avr/interrupt.h>
/*************** Registers Bits Definition *****************/
//Global Interrupt Enable
#define Enable_Globle_Interrupt()   SET_BIT(SREG,SREG_I)
#define Enable_EXINT0()            SET_BIT(GICR,INT0)
#define Disable_EXINT0()             RESET_BIT(GICR,INT0)
#define Enable_EXINT1()              SET_BIT(GICR,INT1)
#define Disable_EXINT1()            RESET_BIT(GICR,INT1)
#define Enable_EXINT2()             SET_BIT(GICR,INT2)
#define disable_EXINT2()            RESET_BIT(GICR,INT2)
#define Clear_INTF0()               SET_BIT(GIFR,INTF0)
#define Clear_INTF1()               SET_BIT(GIFR,INTF1)
#define Clear_INTF2()               SET_BIT(GIFR,INTF2)


#endif	/* NEWFILE_H */

