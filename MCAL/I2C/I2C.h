/* 
 * File:   I2C.h
 * Author: OMAR
 *
 * Created on September 10, 2023, 2:45 PM
 */

#ifndef I2C_H
#define	I2C_H
#include "../LAYPRARIES.h"

#define ACKN_BIT_EN()                   SET_BIY(TWCR,TWEA)
#define ACKN_BIT_DIS()                  RESET_BIT(TWCR,TWEA)
#define START_TWI()                     SET_BIT(TWCR,TWSTA)
#define STOP_TWI()                      RESET_BIT(TWCR,TWSTO)
#define TWI_EN()                        SET(TWCR,TWEN)
#define TWI_DIS()                       RESET(TWCR,TWEN)
#define TWI_INT_EN()                    SET_BIT(TWCR,TWIE)
#define TWI_INT_DIS()                   RESET_BIT(TWCR,TWIE)
#define GEN_CALL_EN()                   SET_BIT(TWAR,TWGCE)
#define GEN_CALL_DIS()                  RESET_BIT(TWAR,TWGCE)
#define cpu_fre    8000000u
#define master_mode  0
#define slave_mode   1
#define prescaler       16ul
#define enable_gcall            1
#define disable_gcall           0
typedef enum {
    pre1 =0x00,
    pre4=0x01,
    pre16=0x02,
    pre64=0x03
}pre_bit;

typedef struct {
    uint8 TWI_MODE;

    uint8 genral_call;
    
    uint8 slave_adress;
}TWI_CONFIG;

typedef struct{
    uint32 twi_rate;
    void(*TWI_report_Write_Collision)(void);
    void(*TWI_Inturrept_handeller)(void);
    TWI_CONFIG TWI_CFG;
}TWI_T;

std_return_type TWI_int(const TWI_T *TWI) ;
std_return_type TWI_deint() ;
std_return_type TWI_send_start() ;
std_return_type TWI_send_stop() ;
std_return_type TWI_write(uint8 data) ;
std_return_type TWI_read(uint8 *data) ;



#endif	/* I2C_H */

