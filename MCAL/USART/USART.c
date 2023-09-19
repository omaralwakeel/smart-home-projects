#include "USART.h"

static void paiority_number(USART_T *usart);
static void character_size(USART_T *usart);

std_return_type USART_INT(USART_T *usart) {
    std_return_type ret = E_OK;
    
    if (usart == NULL) {
        ret = E_NOT_OK;
    } else {
        // Calculate baud rate register value
        uint16_t baud_rate_register_value = (8000000UL  / (16UL * usart->BAUD_RATE)) - 1;
        UBRRL = baud_rate_register_value;
        UBRRH = (baud_rate_register_value >> 8);
        RESIVE_EN();
        TRANSMIT_EN();
        
        // Set frame format: 8 data bits, no parity, 1 stop bit
        UCSRC |=(usart->NO_STOPBI_BIT << USBS);
        
        paiority_number(usart);
        
        
        // Enable or disable interrupts
        if (usart->RX_INT_EN) {
            RX_INT_EN();
        } else {
            RX_INT_DIS();
        }

        if (usart->TX_INT_EN) {
            TX_INT_EN();
        } else {
            TX_INT_DIS();
        }

        if (usart->EMPTY_DATA_INT_EN) {
            EMPTY_DATA_INT_EN();
        } else {
            EMPTY_DATA_INT_DIS();
        }
    }
    
    return ret;
}

void USART_TRANSIMIT(char DATA) {
    // Wait for the transmit buffer to be empty
    while (!(UCSRA & (1 << UDRE)));

    // Transmit data
    UDR = DATA;
}

std_return_type USART_RESIVE(char *DATA) {
    std_return_type ret = E_OK;
    
    if (DATA == NULL) {
        ret = E_NOT_OK;
    } else {
        while (!(UCSRA & (1 << RXC)));

        // Read received data
        *DATA = UDR;
    }
    
    return ret;
}

std_return_type USART_RESIVE_STRING(char *data, uint16_t max_length) {
    std_return_type ret = E_OK;
    uint16_t count = 0;

    if (data == NULL) {
        ret = E_NOT_OK;
    } else {
        while (count < max_length - 1) {
            // Wait for and read a character
            while (!(UCSRA & (1 << RXC)));
            char received_char = UDR;

            // Check for newline or null character
            if (received_char == '\n' || received_char == '\0') {
                break;
            }

            // Store the character
            data[count] = received_char;
            count++;
        }

        // Null-terminate the string
        data[count] = '\0';
    }

    return ret;
}

static void paiority_number(USART_T *usart) {
    switch (usart->NO_STOPBI_BIT) {
        case no:
            DIS_POIRT();
            break;
        case even:
            EVEN_POIRT();
            break;
        case odd:
            ODD_POIRT();
            break;
    }
}

static void character_size(USART_T *usart) {
    switch (usart->CHAR_SIZE) {
        case five_bit:
            RESET_BIT(UCSRB, UCSZ0);
            RESET_BIT(UCSRB, UCSZ1);
            RESET_BIT(UCSRC, UCSZ2);
            break;
        case sex_bit:
            SET_BIT(UCSRB, UCSZ0);
            RESET_BIT(UCSRB, UCSZ1);
            RESET_BIT(UCSRC, UCSZ2);
            break;
        case seven_bit:
            RESET_BIT(UCSRB, UCSZ0);
            SET_BIT(UCSRB, UCSZ1);
            RESET_BIT(UCSRC, UCSZ2);
            break;
        case eight_bit:
            SET_BIT(UCSRB, UCSZ0);
            SET_BIT(UCSRB, UCSZ1);
            RESET_BIT(UCSRC, UCSZ2);
            break;
        case nine_bit:
            SET_BIT(UCSRB, UCSZ0);
            SET_BIT(UCSRB, UCSZ1);
            SET_BIT(UCSRC, UCSZ2);
            SET_BIT(UCSRB, RXB8);
            break;
    }
}
