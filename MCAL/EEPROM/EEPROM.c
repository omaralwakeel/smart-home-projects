#include "EEPROM.h"

void EEPROM_WRITE(uint32 addr,uint8 data){
    while(EEPROM_WRITE_STATE());
    while(WAIT_4CL());
    EEAR=addr;
    EEDR=data;
    EEPROM_MASTER_ENABLE()  ;
    EEPROM_WRITE_ENABLE();
    
}
std_return_type EEPROM_READ(uint32 addr,uint8 *data){
    std_return_type RET=E_OK;
    if(NULL==data){RET=E_NOT_OK;}
    else{
        RET=E_OK;
        while(EEPROM_WRITE_STATE());
        EEAR=addr;
        EEPROM_READ_ENABLE(); 
        *data=EEDR;
    }
}
