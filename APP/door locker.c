
#include "APP/LOCKER.h"


int main() {
    USART_INT(&uart);  // Initialize USART
    key_int(KEY);
    LCD_init();
    timer_int(&motor);
   fast_pwm_set_duty(0);
    int password_index = 0;
    while (1) {
        
        LCD_command(_LCD_CLEAR);
     while(password_index<4){
         
         LCD_setCursor(0,0); 
         LCD_print("enter ur pass");  
         LCD_setCursor(1,password_index); 
      get_key(KEY,&press);
        //LCD_setCursor(0,0);  
        if(press){
            pass[password_index]=press;
            LCD_data(42);
            password_index++;}
        press=0;
        
    }
    if (password_index >= 4) {
                pass[4] = '\0'; // Null-terminate the password
                // Check if the password is correct (you need to implement this part)
                if (strcmp(pass,ROOM_1_PASS) == 0) {
                    LCD_command(_LCD_CLEAR);
                    LCD_print("Password correct");
                    char str[] = "user1\n";
                    int length = sizeof(str) - 1; // Subtract 1 to exclude the null terminator

                    for (int i = 0; i < length; i++) {
                        USART_TRANSIMIT(str[i]);
                    }
                    LCD_setCursor(1,0); 
                    LCD_print("opening door");
                    fast_pwm_set_duty(50);
                    _delay_ms(1000);
                    fast_pwm_set_duty(0);
                    WRONG_PASS=0;
                } 
                else if (strcmp(pass,ROOM_2_PASS) == 0) {
                    LCD_command(_LCD_CLEAR);
                    LCD_print("Password correct");
                    char str[] = "user2\n";
                    int length = sizeof(str) - 1; // Subtract 1 to exclude the null terminator

                    for (int i = 0; i < length; i++) {
                        USART_TRANSIMIT(str[i]);
                    }
                    LCD_setCursor(1,0); 
                    LCD_print("opening door");
                    fast_pwm_set_duty(50);
                    _delay_ms(1000);
                    fast_pwm_set_duty(0);
                    WRONG_PASS=0;
                }
                else if (strcmp(pass,ROOM_3_PASS) == 0) {
                    LCD_command(_LCD_CLEAR);
                    LCD_print("Password correct");
                    char str[] = "user3\n";
                    int length = sizeof(str) - 1; // Subtract 1 to exclude the null terminator

                    for (int i = 0; i < length; i++) {
                        USART_TRANSIMIT(str[i]);
                    }
                    LCD_setCursor(1,0); 
                    LCD_print("opening door");
                    fast_pwm_set_duty(50);
                    _delay_ms(1000);
                    fast_pwm_set_duty(0);
                    WRONG_PASS=0;
                }else {
                    LCD_command(_LCD_CLEAR);
                    LCD_print("Password incorrect");
                    WRONG_PASS++;
                    LCD_setCursor(1,0); 
                    
                    if(WRONG_PASS==3){LCD_print("thife");}
                }
     
     _delay_ms(5000);
     password_index=0;
    }
    }
    return 0;
}

