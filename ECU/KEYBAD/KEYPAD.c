#include "KEYBAD.h"


void key_int(KEYPAD_T key){
    uint8 row_counter=0;
    uint8 colum_counter;
    for(row_counter =0;row_counter<4;row_counter++){
       GPIO_INTIALIZE_PIN(&( key.rows[row_counter]));
       GPIO_WRITE_LOGIC_PIN(&( key.rows[row_counter]),GPIO_LOW);
    }
    for( colum_counter =0;colum_counter<4;colum_counter++){
       GPIO_INTIALIZE_PIN(&( key.columns[colum_counter]));
       
    }
}
void get_key(KEYPAD_T key,uint8 *pressed){
    uint8 row_counter;
    uint8 colum_counter;
    uint8 KEY;
    for( row_counter=0;row_counter<4;row_counter++){
      
       GPIO_WRITE_LOGIC_PIN(&( key.rows[row_counter]),GPIO_HIGH);
       for( colum_counter =0;colum_counter<4;colum_counter++){
           
            GPIO_READ_LOGIC_PIN(&( key.columns[colum_counter]),&KEY);
            
            if (KEY==1){
                *pressed=key.values[row_counter][colum_counter];
                KEY=0;
                _delay_ms(200);
                
            }
       }
       _delay_ms(20);
       GPIO_WRITE_LOGIC_PIN(&( key.rows[row_counter]),GPIO_LOW);
       
    }
    
}