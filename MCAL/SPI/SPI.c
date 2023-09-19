#include "SPI.h"

static void clock(SPI_T *SPI);
static void frequanc (SPI_T *SPI) ;
static void data_segnificant(SPI_T *SPI);
std_return_type SPI_INT(SPI_T  *SPI){
    std_return_type ret=E_OK;
    if (SPI==NULL){
        ret=E_NOT_OK;
    }
    else{
        SET_BIT(SREG,7);
        SET_BIT(SPCR,SPE);
        SET_BIT(SPCR,SPIE);
        data_segnificant(SPI);
        switch(SPI->SPI_mode){
            case SLAVE_MODE:
                SET_BIT(DDRB,MISO);
                RESET_BIT(SPCR,MSTR);
                RESET_BIT(DDRB,MOSI);
                RESET_BIT(DDRB,SS);
                RESET_BIT(DDRB,SCK);
                
                break;
            case MASTER_MODE:
                RESET_BIT(DDRB,MISO);
                SET_BIT(SPCR,MSTR);
                SET_BIT(DDRB,MOSI);
                SET_BIT(DDRB,SS);
                SET_BIT(DDRB,SCK);
                clock(SPI);
                frequanc(SPI);
                break;
                ret=E_OK;
        }
        
    }
    return ret;
}
std_return_type SPI_DEINT(SPI_T *SPI) {
    std_return_type ret=E_OK;
    if (SPI==NULL){
        ret=E_NOT_OK;
    }
    else{
      RESET_BIT(SPCR,SPE);  
      ret=E_OK;
    }
    return ret;
}
std_return_type SPI_SENT(uint8 data ){
     // Start transmission
    SPDR = data;
    
    // Wait for transmission complete
    while (!(SPSR & (1 << SPIF)));
    
    // Return received data
    return SPDR;
}
std_return_type SPI_RESIVE (uint8 *data){
     std_return_type ret=E_OK;
    if (data==NULL){
        ret=E_NOT_OK;
    }
    else{
        /* Wait for reception complete */
        while(!(SPSR & (1<<SPIF)))
        ;
        /* Return data register */
        *data= SPDR;
        ret=E_OK;
    }
     return ret;
}


static void clock(SPI_T *SPI){
    switch(SPI->clock_phase){
        case sample:
            CLOCK_PHASE_SAMPLE() ;
            break;
        case setup:
            CLOCK_PHASE_SETUP();
            break;
    }
    
    switch(SPI->clock_func){
        case leading_edge_falling :
            CLOCK_POLARITY_FALLING();
            break;
        case leading_edge_raising: 
            CLOCK_POLARITY_RAISING();
            break;
    }
}

static void frequanc (SPI_T *SPI) {
    switch(SPI->SPEED_mode){
        case normal_speed:
            RESET_BIT(SPSR,SPI2X);
            switch (SPI->sck_freq){
                case SCK_Frequency_4:
                    RESET_BIT(SPCR,SPR0);
                    RESET_BIT(SPCR,SPR1);
                    break;
                case SCK_Frequency_16:
                    SET_BIT(SPCR,SPR0);
                    RESET_BIT(SPCR,SPR1);
                    break;
                case SCK_Frequency_64:
                    RESET_BIT(SPCR,SPR0);
                    SET_BIT(SPCR,SPR1);
                    break;
                case SCK_Frequency_128:
                    SET_BIT(SPCR,SPR0);
                    SET_BIT(SPCR,SPR1);
                    break;
                
            }
        case doble_speed:
            SET_BIT(SPSR,SPI2X);
            switch (SPI->sck_fre){
                case SCK_Frequency_DOUBLE_2:
                    RESET_BIT(SPCR,SPR0);
                    RESET_BIT(SPCR,SPR1);
                    break;
                case SCK_Frequency_DOUBLE_8:
                    SET_BIT(SPCR,SPR0);
                    RESET_BIT(SPCR,SPR1);
                    break;
                case SCK_Frequency_DOUBLE_32:
                    RESET_BIT(SPCR,SPR0);
                    SET_BIT(SPCR,SPR1);
                    break;
                case SCK_Frequency_DOUBLE_64:
                    SET_BIT(SPCR,SPR0);
                    SET_BIT(SPCR,SPR1);
                    break;
                
            }
    }
}

static void data_segnificant(SPI_T *SPI){
    switch(SPI->data_bit){
        case MSB_T:
            MSB();
            break;
        case LSB_T:
            LSB();
            break;
    }
}