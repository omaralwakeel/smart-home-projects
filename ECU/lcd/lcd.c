
#include"lcd.h"
void LCD_pulseEnable() {
    LCD_PORT |= (1 << EN_PIN);
    _delay_us(1);
    LCD_PORT &= ~(1 << EN_PIN);
    _delay_us(100);
}

void LCD_sendNibble(uint8_t nibble) {
    LCD_PORT &= 0xC3; // Clear bits D4-D7
    LCD_PORT |= (nibble << D4_PIN) & 0x3C; // Set bits D4-D7 according to nibble
    LCD_pulseEnable();
}

void LCD_command(uint8_t cmd) {
    LCD_PORT &= ~(1 << RS_PIN); // Command mode
    LCD_sendNibble(cmd >> 4);
    LCD_sendNibble(cmd);
    _delay_ms(2); // Wait for the command to be processed
}

void LCD_data(uint8_t data) {
    LCD_PORT |= (1 << RS_PIN); // Data mode
    LCD_sendNibble(data >> 4);
    LCD_sendNibble(data);
    _delay_ms(2); // Wait for the data to be written
}

void LCD_init() {
    LCD_DDR |= (1 << RS_PIN) | (1 << EN_PIN) | (1 << D4_PIN) | (1 << D5_PIN) | (1 << D6_PIN) | (1 << D7_PIN);
    
    _delay_ms(15);
    LCD_sendNibble(0x03);
    _delay_ms(5);
    LCD_sendNibble(0x03);
    _delay_us(150);
    LCD_sendNibble(0x03);
    _delay_ms(2);
    LCD_sendNibble(0x02);
    _delay_ms(2);

    LCD_command(0x28);
    LCD_command(0x0C);
    LCD_command(0x06);
    LCD_command(0x01);
    _delay_ms(2);
}

void LCD_print(const char *str) {
    while (*str) {
        LCD_data(*str);
        str++;
    }
}

void LCD_setCursor(uint8_t row, uint8_t col) {
    uint8_t row_offsets[] = {0x00, 0x40, 0x10, 0x50};
    LCD_command(0x80 | (col + row_offsets[row]));
}
void LCD_defineCustomChar(uint8_t location, const uint8_t charMap[8]) {
    LCD_command(_LCD_CGRAM_START + (location * 8));
    for (uint8_t i = 0; i < 8; i++) {
        LCD_data(charMap[i]);
    }
}

void LCD_printFloat(float value, uint8_t decimalPlaces) {
    char buffer[16]; // Adjust the buffer size as needed
    snprintf(buffer, sizeof(buffer), "%.*f", decimalPlaces, value);
    LCD_print(buffer);
}

