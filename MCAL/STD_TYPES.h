/* 
 * File:   STD_TYPES.h
 * Author: OMAR
 *
 * Created on August 14, 2023, 11:58 PM
 */

#ifndef STD_TYPES_H
#define	STD_TYPES_H

/*section :data type DEclaration*/
typedef unsigned char    uint8;
typedef unsigned short   uint16;
typedef unsigned int     uint32;

typedef uint8 std_return_type;



#define E_OK         (std_return_type)0x01
#define E_NOT_OK     (std_return_type)0x00 
#endif	/* STD_TYPES_H */

