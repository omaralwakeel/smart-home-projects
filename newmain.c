
#include "APP/ROOM_1.h"



int main() {
    USART_INT(&uart);  // Initialize USART
    GPIO_INTIALIZE_PIN(&power_up);
    GPIO_INTIALIZE_PIN(&ROOM);
    LCD_init();
    timer_int(&motor);
    fast_pwm_set_duty(0);
    int index = 0;
    Timer1_int(&int1);
    char received_string[128]; // Define a character array to store the received string

    while (1) {
        USART_RESIVE_STRING(received_string, sizeof(received_string));

        // Check if the received string contains '1' at index 4
        if (strlen(received_string) > 4 && received_string[4] == '1') {
            GPIO_WRITE_LOGIC_PIN(&power_up,GPIO_HIGH);
            int16_t tem = lm35_temp(0);
            LCD_print("Room Temperature is");
            char str[20]; // Assuming a maximum of 20 characters for the string representation
             // Convert temperature to a string
            while (tem < 30) {
                tem = lm35_temp(0);
                LCD_setCursor(1, 0);
                sprintf(str, "%d", tem );
                LCD_setCursor(1, 0); // Set the cursor position for printing the temperature
                LCD_print(str);
                pwm_set_duty(80);
            }
            GPIO_READ_LOGIC_PIN(&ROOM,&someone_in);
            if(!someone_in){
                GPIO_WRITE_LOGIC_PIN(&power_up,GPIO_LOW);
            }
            pwm_set_duty(0);
        }
    }

    return 0;
}


// Timer1 overflow interrupt handler
ISR(TIMER1_OVF_vect) {
    // Check the state of PA2
    GPIO_READ_LOGIC_PIN(&ROOM,&someone_in);
    if (!someone_in) {
        timer_count++;
        if (timer_count >= 300) { // 300 seconds = 5 minutes
            // Set PA1 to low
            GPIO_WRITE_LOGIC_PIN(&power_up,GPIO_LOW);
            timer_count = 0; // Reset the counter
        }
    } else {
        timer_count = 0; // Reset the counter if PA2 is high
    }
}

