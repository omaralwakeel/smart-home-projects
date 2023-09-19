/* 
 * File:   MICROSE.h
 * Author: OMAR
 *
 * Created on August 14, 2023, 11:59 PM
 */

#ifndef MICROSE_H
#define	MICROSE_H


#define SET_BIT(byte, bit_no) ((byte) |= (1 << bit_no))
#define RESET_BIT(byte,bit_no) (byte &= ~(1<< bit_no))
#define GET_BIT(byte,bit_no) ((byte>>bit_no)& 1)
#define TOGGLE_BIT(byte, bit_no) (byte ^= (1 << bit_no))
#define ASSIGN_BIT(byte,bit_no,value)	byte = (byte & (~(1<<bit_no)))|(value<<bit_no)

#endif	/* MICROSE_H */

