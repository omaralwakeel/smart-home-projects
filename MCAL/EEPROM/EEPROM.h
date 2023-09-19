/* 
 * File:   EEPROM.h
 * Author: OMAR
 *
 * Created on August 16, 2023, 10:34 PM
 */

#ifndef EEPROM_H
#define	EEPROM_H
#include"../LAYPRARIES.h"


#define EEPROM_MASTER_ENABLE()          SET_BIT(EECR,EEMWE)
#define EEPROM_MASTER_DISABLE()         RESET_BIT(EECR,EEMWE)

#define EEPROM_WRITE_ENABLE()           SET_BIT(EECR,EEWE)
#define EEPROM_WRITE_DISABLE()          RESET_BIT(EECR,EEWE)
#define EEPROM_WRITE_STATE()            GET_BIT(EECR,EEWE)

#define WAIT_4CL()                      GET_BIT(SPMCR,SPMEN)

#define EEPROM_READ_ENABLE()           SET_BIT(EECR,EERE)
#define EEPROM_READ_DISABLE()          RESET_BIT(EECR,EERE)


void EEPROM_WRITE(uint32 addr,uint8 data);
std_return_type EEPROM_READ(uint32 addr,uint8 *data);

#endif	/* EEPROM_H */

