/* 
 * File:   GPIO.c
 * Author: OMAR
 *
 * Created on August 15, 2023, 12:56 PM
 */


#include "GPIO.h"

std_return_type GPIO_INTIALIZE_PIN(pin_config_t *PIN_OBJ){
    std_return_type ret=E_OK;
    if(PIN_OBJ==NULL){
        ret=E_NOT_OK;
    }else{
        ret=E_OK;
        switch(PIN_OBJ->port){
            case (GPIO_PORTA): 
                if (PIN_OBJ->direction==GPIO_PIN_OUTPUT){SET_BIT(DDRA,PIN_OBJ->pin);}
                if (PIN_OBJ->direction==GPIO_PIN_INPUT){RESET_BIT(DDRA,PIN_OBJ->pin);}
           case (GPIO_PORTB): 
                if (PIN_OBJ->direction==GPIO_PIN_OUTPUT){SET_BIT (DDRB,PIN_OBJ->pin);}
                if (PIN_OBJ->direction==GPIO_PIN_INPUT){RESET_BIT(DDRB,PIN_OBJ->pin);}
                break;
            case (GPIO_PORTC): 
                if (PIN_OBJ->direction==GPIO_PIN_OUTPUT){SET_BIT (DDRC,PIN_OBJ->pin);}
                if (PIN_OBJ->direction==GPIO_PIN_INPUT){RESET_BIT(DDRC,PIN_OBJ->pin);}
                break;
            case (GPIO_PORTD):  
                if (PIN_OBJ->direction==GPIO_PIN_OUTPUT){SET_BIT (DDRD,PIN_OBJ->pin);}
                if (PIN_OBJ->direction==GPIO_PIN_INPUT){RESET_BIT(DDRD,PIN_OBJ->pin);}
                break;
        }
    }
    return ret;
}
std_return_type GPIO_WRITE_LOGIC_PIN(pin_config_t *PIN_OBJ,uint8 logic){   
        std_return_type ret=E_OK;    
        if(PIN_OBJ==NULL){       
            ret=E_NOT_OK;    
        }else{        
            ret=E_OK; 
            switch(PIN_OBJ->port){
                case (GPIO_PORTA): 
                    switch(PIN_OBJ->pin){
                        case (GPIO_PIN0): if(logic==GPIO_HIGH){SET_BIT(GPIO_PORTA_PORT,GPIO_PIN0_INDEX);}
                                            else if(logic==GPIO_LOW){RESET_BIT(GPIO_PORTA_PORT,GPIO_PIN0_INDEX);}
                        break;
                        case (GPIO_PIN1): if(logic==GPIO_HIGH){SET_BIT(GPIO_PORTA_PORT,GPIO_PIN1_INDEX);}
                            else if(logic==GPIO_LOW){RESET_BIT(GPIO_PORTA_PORT,GPIO_PIN1_INDEX);}
                        break;
                        case (GPIO_PIN2): if(logic==GPIO_HIGH){SET_BIT(GPIO_PORTA_PORT,GPIO_PIN2_INDEX);}
                            else if(logic==GPIO_LOW){RESET_BIT(GPIO_PORTA_PORT,GPIO_PIN2_INDEX);}
                        break;
                        case (GPIO_PIN3): if(logic==GPIO_HIGH){SET_BIT(GPIO_PORTA_PORT,GPIO_PIN3_INDEX);}
                            else if(logic==GPIO_LOW){RESET_BIT(GPIO_PORTA_PORT,GPIO_PIN3_INDEX);}
                        break;
                        case (GPIO_PIN4): if(logic==GPIO_HIGH){SET_BIT(GPIO_PORTA_PORT,GPIO_PIN4_INDEX);}
                            else if(logic==GPIO_LOW){RESET_BIT(GPIO_PORTA_PORT,GPIO_PIN4_INDEX);}
                        break;
                        case (GPIO_PIN5): if(logic==GPIO_HIGH){SET_BIT(GPIO_PORTA_PORT,GPIO_PIN5_INDEX);}
                            else if(logic==GPIO_LOW){RESET_BIT(GPIO_PORTA_PORT,GPIO_PIN5_INDEX);}
                        break;
                        case (GPIO_PIN6): if(logic==GPIO_HIGH){SET_BIT(GPIO_PORTA_PORT,GPIO_PIN6_INDEX);}
                            else if(logic==GPIO_LOW){RESET_BIT(GPIO_PORTA_PORT,GPIO_PIN6_INDEX);}
                        break;
                        case (GPIO_PIN7): if(logic==GPIO_HIGH){SET_BIT(GPIO_PORTA_PORT,GPIO_PIN7_INDEX);}
                            else if(logic==GPIO_LOW){RESET_BIT(GPIO_PORTA_PORT,GPIO_PIN7_INDEX);}
                        break;

                    }
                    break;

               case (GPIO_PORTB): 
                    switch(PIN_OBJ->pin){
                        case (GPIO_PIN0): if(logic==GPIO_HIGH){SET_BIT(GPIO_PORTB_PORT,GPIO_PIN0_INDEX);}
                                            else if(logic==GPIO_LOW){RESET_BIT(GPIO_PORTB_PORT,GPIO_PIN0_INDEX);}
                        break;
                        case (GPIO_PIN1): if(logic==GPIO_HIGH){SET_BIT(GPIO_PORTB_PORT,GPIO_PIN1_INDEX);}
                            else if(logic==GPIO_LOW){RESET_BIT(GPIO_PORTB_PORT,GPIO_PIN1_INDEX);}
                        break;
                        case (GPIO_PIN2): if(logic==GPIO_HIGH){SET_BIT(GPIO_PORTB_PORT,GPIO_PIN2_INDEX);}
                            else if(logic==GPIO_LOW){RESET_BIT(GPIO_PORTB_PORT,GPIO_PIN2_INDEX);}
                        break;
                        case (GPIO_PIN3): if(logic==GPIO_HIGH){SET_BIT(GPIO_PORTB_PORT,GPIO_PIN3_INDEX);}
                            else if(logic==GPIO_LOW){RESET_BIT(GPIO_PORTB_PORT,GPIO_PIN3_INDEX);}
                        break;
                        case (GPIO_PIN4): if(logic==GPIO_HIGH){SET_BIT(GPIO_PORTB_PORT,GPIO_PIN4_INDEX);}
                            else if(logic==GPIO_LOW){RESET_BIT(GPIO_PORTB_PORT,GPIO_PIN4_INDEX);}
                        break;
                        case (GPIO_PIN5): if(logic==GPIO_HIGH){SET_BIT(GPIO_PORTB_PORT,GPIO_PIN5_INDEX);}
                            else if(logic==GPIO_LOW){RESET_BIT(GPIO_PORTB_PORT,GPIO_PIN5_INDEX);}
                        break;
                        case (GPIO_PIN6): if(logic==GPIO_HIGH){SET_BIT(GPIO_PORTB_PORT,GPIO_PIN6_INDEX);}
                            else if(logic==GPIO_LOW){RESET_BIT(GPIO_PORTB_PORT,GPIO_PIN6_INDEX);}
                        break;
                        case (GPIO_PIN7): if(logic==GPIO_HIGH){SET_BIT(GPIO_PORTB_PORT,GPIO_PIN7_INDEX);}
                            else if(logic==GPIO_LOW){RESET_BIT(GPIO_PORTB_PORT,GPIO_PIN7_INDEX);}
                        break;

                    }
                    break;
                case (GPIO_PORTC): 
                    switch(PIN_OBJ->pin){
                        case (GPIO_PIN0): if(logic==GPIO_HIGH){SET_BIT(GPIO_PORTC_PORT,GPIO_PIN0_INDEX);}
                                            else if(logic==GPIO_LOW){RESET_BIT(GPIO_PORTC_PORT,GPIO_PIN0_INDEX);}
                        break;
                        case (GPIO_PIN1): if(logic==GPIO_HIGH){SET_BIT(GPIO_PORTC_PORT,GPIO_PIN1_INDEX);}
                            else if(logic==GPIO_LOW){RESET_BIT(GPIO_PORTC_PORT,GPIO_PIN1_INDEX);}
                        break;
                        case (GPIO_PIN2): if(logic==GPIO_HIGH){SET_BIT(GPIO_PORTC_PORT,GPIO_PIN2_INDEX);}
                            else if(logic==GPIO_LOW){RESET_BIT(GPIO_PORTC_PORT,GPIO_PIN2_INDEX);}
                        break;
                        case (GPIO_PIN3): if(logic==GPIO_HIGH){SET_BIT(GPIO_PORTC_PORT,GPIO_PIN3_INDEX);}
                            else if(logic==GPIO_LOW){RESET_BIT(GPIO_PORTC_PORT,GPIO_PIN3_INDEX);}
                        break;
                        case (GPIO_PIN4): if(logic==GPIO_HIGH){SET_BIT(GPIO_PORTC_PORT,GPIO_PIN4_INDEX);}
                            else if(logic==GPIO_LOW){RESET_BIT(GPIO_PORTC_PORT,GPIO_PIN4_INDEX);}
                        break;
                        case (GPIO_PIN5): if(logic==GPIO_HIGH){SET_BIT(GPIO_PORTC_PORT,GPIO_PIN5_INDEX);}
                            else if(logic==GPIO_LOW){RESET_BIT(GPIO_PORTC_PORT,GPIO_PIN5_INDEX);}
                        break;
                        case (GPIO_PIN6): if(logic==GPIO_HIGH){SET_BIT(GPIO_PORTC_PORT,GPIO_PIN6_INDEX);}
                            else if(logic==GPIO_LOW){RESET_BIT(GPIO_PORTC_PORT,GPIO_PIN6_INDEX);}
                        break;
                        case (GPIO_PIN7): if(logic==GPIO_HIGH){SET_BIT(GPIO_PORTC_PORT,GPIO_PIN7_INDEX);}
                            else if(logic==GPIO_LOW){RESET_BIT(GPIO_PORTC_PORT,GPIO_PIN7_INDEX);}
                        break;

                    }
                    break;
                case (GPIO_PORTD): 
                    switch(PIN_OBJ->pin){
                        case (GPIO_PIN0): if(logic==GPIO_HIGH){SET_BIT(GPIO_PORTD_PORT,GPIO_PIN0_INDEX);}
                                            else if(logic==GPIO_LOW){RESET_BIT(GPIO_PORTD_PORT,GPIO_PIN0_INDEX);}
                        break;
                        case (GPIO_PIN1): if(logic==GPIO_HIGH){SET_BIT(GPIO_PORTD_PORT,GPIO_PIN1_INDEX);}
                            else if(logic==GPIO_LOW){RESET_BIT(GPIO_PORTD_PORT,GPIO_PIN1_INDEX);}
                        break;
                        case (GPIO_PIN2): if(logic==GPIO_HIGH){SET_BIT(GPIO_PORTD_PORT,GPIO_PIN2_INDEX);}
                            else if(logic==GPIO_LOW){RESET_BIT(GPIO_PORTD_PORT,GPIO_PIN2_INDEX);}
                        break;
                        case (GPIO_PIN3): if(logic==GPIO_HIGH){SET_BIT(GPIO_PORTD_PORT,GPIO_PIN3_INDEX);}
                            else if(logic==GPIO_LOW){RESET_BIT(GPIO_PORTD_PORT,GPIO_PIN3_INDEX);}
                        break;
                        case (GPIO_PIN4): if(logic==GPIO_HIGH){SET_BIT(GPIO_PORTD_PORT,GPIO_PIN4_INDEX);}
                            else if(logic==GPIO_LOW){RESET_BIT(GPIO_PORTD_PORT,GPIO_PIN4_INDEX);}
                        break;
                        case (GPIO_PIN5): if(logic==GPIO_HIGH){SET_BIT(GPIO_PORTD_PORT,GPIO_PIN5_INDEX);}
                            else if(logic==GPIO_LOW){RESET_BIT(GPIO_PORTD_PORT,GPIO_PIN5_INDEX);}
                        break;
                        case (GPIO_PIN6): if(logic==GPIO_HIGH){SET_BIT(GPIO_PORTD_PORT,GPIO_PIN6_INDEX);}
                            else if(logic==GPIO_LOW){RESET_BIT(GPIO_PORTD_PORT,GPIO_PIN6_INDEX);}
                        break;
                        case (GPIO_PIN7): if(logic==GPIO_HIGH){SET_BIT(GPIO_PORTD_PORT,GPIO_PIN7_INDEX);}
                            else if(logic==GPIO_LOW){RESET_BIT(GPIO_PORTD_PORT,GPIO_PIN7_INDEX);}
                        break;

                    }
                    break;
            }
        }
        return ret;
}
std_return_type GPIO_READ_LOGIC_PIN(pin_config_t *PIN_OBJ,uint8 *data){    
    std_return_type ret=E_OK;    
    if(PIN_OBJ==NULL){        
        ret=E_NOT_OK;    
    }else{        
        ret=E_OK;    
         switch(PIN_OBJ->port){
            case (GPIO_PORTA): 
                switch(PIN_OBJ->pin){
                    case (GPIO_PIN0): *data=GET_BIT(GPIO_PORTA_PIN,GPIO_PIN0_INDEX);
                    break;
                    case (GPIO_PIN1): *data=GET_BIT(GPIO_PORTA_PIN,GPIO_PIN1_INDEX);
                    break;
                    case (GPIO_PIN2):*data=GET_BIT(GPIO_PORTA_PIN,GPIO_PIN2_INDEX);
                    break;
                    case (GPIO_PIN3): *data=GET_BIT(GPIO_PORTA_PIN,GPIO_PIN3_INDEX);
                    break;
                    case (GPIO_PIN4): *data=GET_BIT(GPIO_PORTA_PIN,GPIO_PIN4_INDEX);
                    break;
                    case (GPIO_PIN5): *data=GET_BIT(GPIO_PORTA_PIN,GPIO_PIN5_INDEX);
                    break;
                    case (GPIO_PIN6): *data=GET_BIT(GPIO_PORTA_PIN,GPIO_PIN6_INDEX);
                    break;
                    case (GPIO_PIN7): *data=GET_BIT(GPIO_PORTA_PIN,GPIO_PIN7_INDEX);
                    break;
                    
                }
                break;
            
            case (GPIO_PORTB): 
                switch(PIN_OBJ->pin){
                    case (GPIO_PIN0): *data=GET_BIT(GPIO_PORTB_PIN,GPIO_PIN0_INDEX);
                    break;
                    case (GPIO_PIN1): *data=GET_BIT(GPIO_PORTB_PIN,GPIO_PIN1_INDEX);
                    break;
                    case (GPIO_PIN2):*data=GET_BIT(GPIO_PORTB_PIN,GPIO_PIN2_INDEX);
                    break;
                    case (GPIO_PIN3): *data=GET_BIT(GPIO_PORTB_PIN,GPIO_PIN3_INDEX);
                    break;
                    case (GPIO_PIN4): *data=GET_BIT(GPIO_PORTB_PIN,GPIO_PIN4_INDEX);
                    break;
                    case (GPIO_PIN5): *data=GET_BIT(GPIO_PORTB_PIN,GPIO_PIN5_INDEX);
                    break;
                    case (GPIO_PIN6): *data=GET_BIT(GPIO_PORTB_PIN,GPIO_PIN6_INDEX);
                    break;
                    case (GPIO_PIN7): *data=GET_BIT(GPIO_PORTB_PIN,GPIO_PIN7_INDEX);
                    break;
                    
                }
                break;
            case (GPIO_PORTC): 
                switch(PIN_OBJ->pin){
                    case (GPIO_PIN0): *data=GET_BIT(GPIO_PORTC_PIN,GPIO_PIN0_INDEX);
                    break;
                    case (GPIO_PIN1): *data=GET_BIT(GPIO_PORTC_PIN,GPIO_PIN1_INDEX);
                    break;
                    case (GPIO_PIN2):*data=GET_BIT(GPIO_PORTC_PIN,GPIO_PIN2_INDEX);
                    break;
                    case (GPIO_PIN3): *data=GET_BIT(GPIO_PORTC_PIN,GPIO_PIN3_INDEX);
                    break;
                    case (GPIO_PIN4): *data=GET_BIT(GPIO_PORTC_PIN,GPIO_PIN4_INDEX);
                    break;
                    case (GPIO_PIN5): *data=GET_BIT(GPIO_PORTC_PIN,GPIO_PIN5_INDEX);
                    break;
                    case (GPIO_PIN6): *data=GET_BIT(GPIO_PORTC_PIN,GPIO_PIN6_INDEX);
                    break;
                    case (GPIO_PIN7): *data=GET_BIT(GPIO_PORTC_PIN,GPIO_PIN7_INDEX);
                    break;
                    
                }
                break;
                
            case (GPIO_PORTD): 
                switch(PIN_OBJ->pin){
                    case (GPIO_PIN0): *data=GET_BIT(GPIO_PORTD_PIN,GPIO_PIN0_INDEX);
                    break;
                    case (GPIO_PIN1): *data=GET_BIT(GPIO_PORTD_PIN,GPIO_PIN1_INDEX);
                    break;
                    case (GPIO_PIN2):*data=GET_BIT(GPIO_PORTD_PIN,GPIO_PIN2_INDEX);
                    break;
                    case (GPIO_PIN3): *data=GET_BIT(GPIO_PORTD_PIN,GPIO_PIN3_INDEX);
                    break;
                    case (GPIO_PIN4): *data=GET_BIT(GPIO_PORTD_PIN,GPIO_PIN4_INDEX);
                    break;
                    case (GPIO_PIN5): *data=GET_BIT(GPIO_PORTD_PIN,GPIO_PIN5_INDEX);
                    break;
                    case (GPIO_PIN6): *data=GET_BIT(GPIO_PORTD_PIN,GPIO_PIN6_INDEX);
                    break;
                    case (GPIO_PIN7): *data=GET_BIT(GPIO_PORTD_PIN,GPIO_PIN7_INDEX);
                    break;
                    
                }
                break;
         }
    }   
    return ret;
}
std_return_type GPIO_TOGGLE_PIN(pin_config_t *PIN_OBJ){   
    std_return_type ret=E_OK;    
    if(PIN_OBJ==NULL){        
        ret=E_NOT_OK;    
    }else{        
        ret=E_OK;    
         switch(PIN_OBJ->port){
            case (GPIO_PORTA): 
                switch(PIN_OBJ->pin){
                    case (GPIO_PIN0): TOGGLE_BIT(GPIO_PORTA_PORT,GPIO_PIN0_INDEX);
                    break;
                    case (GPIO_PIN1): TOGGLE_BIT(GPIO_PORTA_PORT,GPIO_PIN1_INDEX);
                    break;
                    case (GPIO_PIN2):TOGGLE_BIT(GPIO_PORTA_PORT,GPIO_PIN2_INDEX);
                    break;
                    case (GPIO_PIN3): TOGGLE_BIT(GPIO_PORTA_PORT,GPIO_PIN3_INDEX);
                    break;
                    case (GPIO_PIN4): TOGGLE_BIT(GPIO_PORTA_PORT,GPIO_PIN4_INDEX);
                    break;
                    case (GPIO_PIN5): TOGGLE_BIT(GPIO_PORTA_PORT,GPIO_PIN5_INDEX);
                    break;
                    case (GPIO_PIN6): TOGGLE_BIT(GPIO_PORTA_PORT,GPIO_PIN6_INDEX);
                    break;
                    case (GPIO_PIN7): TOGGLE_BIT(GPIO_PORTA_PORT,GPIO_PIN7_INDEX);
                    break;
                    
                }
                break;
            
            case (GPIO_PORTB): 
                switch(PIN_OBJ->pin){
                    case (GPIO_PIN0): TOGGLE_BIT(GPIO_PORTB_PORT,GPIO_PIN0_INDEX);
                    break;
                    case (GPIO_PIN1): TOGGLE_BIT(GPIO_PORTB_PORT,GPIO_PIN1_INDEX);
                    break;
                    case (GPIO_PIN2):TOGGLE_BIT(GPIO_PORTB_PORT,GPIO_PIN2_INDEX);
                    break;
                    case (GPIO_PIN3): TOGGLE_BIT(GPIO_PORTB_PORT,GPIO_PIN3_INDEX);
                    break;
                    case (GPIO_PIN4): TOGGLE_BIT(GPIO_PORTB_PORT,GPIO_PIN4_INDEX);
                    break;
                    case (GPIO_PIN5): TOGGLE_BIT(GPIO_PORTB_PORT,GPIO_PIN5_INDEX);
                    break;
                    case (GPIO_PIN6): TOGGLE_BIT(GPIO_PORTB_PORT,GPIO_PIN6_INDEX);
                    break;
                    case (GPIO_PIN7): TOGGLE_BIT(GPIO_PORTB_PORT,GPIO_PIN7_INDEX);
                    break;
                    
                }
                break;
            case (GPIO_PORTC): 
                switch(PIN_OBJ->pin){
                    case (GPIO_PIN0): TOGGLE_BIT(GPIO_PORTC_PORT,GPIO_PIN0_INDEX);
                    break;
                    case (GPIO_PIN1): TOGGLE_BIT(GPIO_PORTC_PORT,GPIO_PIN1_INDEX);
                    break;
                    case (GPIO_PIN2):TOGGLE_BIT(GPIO_PORTC_PORT,GPIO_PIN2_INDEX);
                    break;
                    case (GPIO_PIN3): TOGGLE_BIT(GPIO_PORTC_PORT,GPIO_PIN3_INDEX);
                    break;
                    case (GPIO_PIN4): TOGGLE_BIT(GPIO_PORTC_PORT,GPIO_PIN4_INDEX);
                    break;
                    case (GPIO_PIN5): TOGGLE_BIT(GPIO_PORTC_PORT,GPIO_PIN5_INDEX);
                    break;
                    case (GPIO_PIN6): TOGGLE_BIT(GPIO_PORTC_PORT,GPIO_PIN6_INDEX);
                    break;
                    case (GPIO_PIN7): TOGGLE_BIT(GPIO_PORTC_PORT,GPIO_PIN7_INDEX);
                    break;
                    
                }
                break;
                
            case (GPIO_PORTD): 
                switch(PIN_OBJ->pin){
                    case (GPIO_PIN0): TOGGLE_BIT(GPIO_PORTD_PORT,GPIO_PIN0_INDEX);
                    break;
                    case (GPIO_PIN1): TOGGLE_BIT(GPIO_PORTD_PORT,GPIO_PIN1_INDEX);
                    break;
                    case (GPIO_PIN2):TOGGLE_BIT(GPIO_PORTD_PORT,GPIO_PIN2_INDEX);
                    break;
                    case (GPIO_PIN3): TOGGLE_BIT(GPIO_PORTD_PORT,GPIO_PIN3_INDEX);
                    break;
                    case (GPIO_PIN4): TOGGLE_BIT(GPIO_PORTD_PORT,GPIO_PIN4_INDEX);
                    break;
                    case (GPIO_PIN5): TOGGLE_BIT(GPIO_PORTD_PORT,GPIO_PIN5_INDEX);
                    break;
                    case (GPIO_PIN6): TOGGLE_BIT(GPIO_PORTD_PORT,GPIO_PIN6_INDEX);
                    break;
                    case (GPIO_PIN7): TOGGLE_BIT(GPIO_PORTD_PORT,GPIO_PIN7_INDEX);
                    break;
                    
                }
                break;
         }
    }   
    return ret;
}



std_return_type GPIO_INTIALIZE_PORT(pin_config_t *PIN_OBJ){
    std_return_type ret=E_OK;
    if(PIN_OBJ==NULL){
        ret=E_NOT_OK;
    }else{
        ret=E_OK;
        if(PIN_OBJ->direction==GPIO_PIN_OUTPUT){
            switch(PIN_OBJ->port){
                case (GPIO_PORTA):DDRA=0XFF;break;
                case (GPIO_PORTC):DDRB=0XFF;break;
                case (GPIO_PORTB):DDRC=0XFF;break;
                case (GPIO_PORTD):DDRD=0XFF;break;
            }
        }else if(PIN_OBJ->direction==GPIO_PIN_OUTPUT){
            switch(PIN_OBJ->port){
                case (GPIO_PORTA):DDRA=0X00;break;
                case (GPIO_PORTC):DDRB=0X00;break;
                case (GPIO_PORTB):DDRC=0X00;break;
                case (GPIO_PORTD):DDRD=0X00;break;
            }
        }
    }    
    return ret;
}
std_return_type GPIO_WRITE_LOGIC_PORT(pin_config_t *PIN_OBJ,uint8 logic){
    std_return_type ret=E_OK;
    if(PIN_OBJ==NULL){
        ret=E_NOT_OK;
    }else{
       if(logic==GPIO_HIGH){
            switch(PIN_OBJ->port){
                case (GPIO_PORTA):PORTA=0XFF;break;
                case (GPIO_PORTC):PORTB=0XFF;break;
                case (GPIO_PORTB):PORTC=0XFF;break;
                case (GPIO_PORTD):PORTD=0XFF;break;
            }
        }else if(logic==GPIO_LOW){
            switch(PIN_OBJ->port){
                case (GPIO_PORTA):PORTA=0X00;break;
                case (GPIO_PORTC):PORTB=0X00;break;
                case (GPIO_PORTB):PORTC=0X00;break;
                case (GPIO_PORTD):PORTD=0X00;break;
            }
        }
    }    
    return ret;
}
std_return_type GPIO_TOGGLE_PORT(pin_config_t *PIN_OBJ){
    std_return_type ret=E_OK;
    if(PIN_OBJ==NULL){
        ret=E_NOT_OK;
    }else{
        ret=E_OK;
        switch(PIN_OBJ->port){
            case (GPIO_PORTA):
                for(int i=0;i<8;i++){
                    TOGGLE_BIT(GPIO_PORTA_PORT,i);
                }
                break;
            case (GPIO_PORTC):
                for(int i=0;i<8;i++){
                    TOGGLE_BIT(GPIO_PORTA_PORT,i);
                }
                break;
            case (GPIO_PORTB):
                for(int i=0;i<8;i++){
                    TOGGLE_BIT(GPIO_PORTA_PORT,i);
                }
                break;
            case (GPIO_PORTD):
                for(int i=0;i<8;i++){
                    TOGGLE_BIT(GPIO_PORTA_PORT,i);
                }
                break;
        }
    }    
    return ret;
}