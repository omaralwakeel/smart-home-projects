/* 
 * File:   *SPI.h
 * Author: OMAR
 *
 * Created on September 5, 2023, 3:33 PM
 */

#ifndef SPI_H
#define	SPI_H
#include "../LAYPRARIES.h"
#include "../GPIO/GPIO.h"

#define MOSI PB5
#warning "MOSI IS SET FOR ATMEGA16"



#define SCK PB4
#warning "SCK IS SET FOR ATMEGA16"


#define MISO PB5
#warning "MISO IS SET FOR ATMEGA16"

#define SS   PB7
#warning "SS IS SET FOR ATMEGA16"


#define SPI_ENABLE_INT_ENABLE()                SET_BIT(SPCR,SPIE)
#define SPI_DISABLE_INT_ENABLE()               RESET_BIT(SPCR,SPIE)
#define SPI_ENABLE()                           SET_BIT (SPCR , SPE)
#define SPI_DISABLE()                          RESET_BIT (SPCR , SPE)
#define LSB()                                  SET_BIT(SPCR,DORD)
#define MSB()                                  RESET_BIT(SPCR,DORD)
#define SPI_MASTER_MODE()                      SET_BIT(SPCR,MSTR)
#define SPI_SELAVE_MODE()                      RESET_BIT(SPCR,MSTR)
#define CLOCK_POLARITY_RAISING()               SET_BIT(SPCR,CPOL)
#define CLOCK_POLARITY_FALLING()               RESET_BIT(SPCR,CPOL)
#define CLOCK_PHASE_SETUP()                    SET_BIT(SPCR,CPHA)
#define CLOCK_PHASE_SAMPLE()                   RESET_BIT(SPCR,CPHA)
#define normal_speed                           0
#define doble_speed                            1
#define SLAVE_MODE                             0
#define MASTER_MODE                            1
#define MSB_T                                  0
#define LSB_T                                  1

typedef enum{
    leading_edge_falling,
    leading_edge_raising,    
}CPOL_T;

typedef enum{
    sample=0,
    setup=1,
}CPHA_T;

typedef enum{
    SCK_Frequency_4=0,
    SCK_Frequency_16=1,
    SCK_Frequency_64=2,
    SCK_Frequency_128=3
}NORMAL_SPEED_T;
typedef enum {
    SCK_Frequency_DOUBLE_2=0,
    SCK_Frequency_DOUBLE_8=1,
    SCK_Frequency_DOUBLE_32=2,
    SCK_Frequency_DOUBLE_64=3
}DOUBLE_SPEE_T;

typedef struct {
 uint8 SPI_mode;
 uint8 SPEED_mode;
 DOUBLE_SPEE_T sck_fre;
 NORMAL_SPEED_T sck_freq;
 CPHA_T clock_phase;
 CPOL_T clock_func;
 uint8 data_bit;
}SPI_T;

std_return_type SPI_INT(SPI_T  *SPI);
std_return_type SPI_DEINT(SPI_T *SPI);
std_return_type SPI_SENT(uint8 data );
std_return_type SPI_RESIVE(uint8 *data );
#endif	/* SPI_H */

