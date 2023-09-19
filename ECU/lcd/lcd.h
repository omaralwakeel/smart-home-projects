#ifndef LCD_H
#define LCD_H



/* ----------------- Includes -----------------*/
#include "../../MCAL/LAYPRARIES.h"


/* ----------------- Macro Declarations -----------------*/
#define _LCD_CLEAR                      0X01
#define _LCD_RETURN_HOME                0x02
#define _LCD_ENTRY_MODE_DEC_SHIFT_OFF   0x04
#define _LCD_ENTRY_MODE_DEC_SHIFT_ON    0x05
#define _LCD_ENTRY_MODE_INC_SHIFT_OFF   0x06
#define _LCD_ENTRY_MODE_INC_SHIFT_ON    0x07
#define _LCD_CURSOR_MOVE_SHIFT_LEFT     0x10
#define _LCD_CURSOR_MOVE_SHIFT_RIGHT    0x14
#define _LCD_DISPLAY_SHIFT_LEFT         0x18
#define _LCD_DISPLAY_SHIFT_RIGHT        0x1C
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF 0x0C
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_ON  0x0D
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_OFF  0x0E
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_ON   0x0F
#define _LCD_DISPLAY_OFF_CURSOR_OFF              0x08
#define _LCD_8BIT_MODE_2_LINE           0x38
#define _LCD_4BIT_MODE_2_LINE           0x28

#define _LCD_CGRAM_START                0x40
#define _LCD_DDRAM_START                0x80

#ifndef LCD_PORT
#define LCD_PORT     PORTC
#endif

#ifndef LCD_DDR
#define LCD_DDR      DDRC
#endif

#ifndef RS_PIN
#define RS_PIN       PC0
#endif

#ifndef EN_PIN
#define EN_PIN       PC1
#endif

#ifndef D4_PIN
#define D4_PIN       PC2
#endif

#ifndef D5_PIN
#define D5_PIN       PC3
#endif

#ifndef D6_PIN
#define D6_PIN       PC4
#endif

#ifndef D7_PIN
#define D7_PIN       PC5
#endif


#define LCD_CMD      0
#define LCD_DATA     1


/* ----------------- Macro Functions Declarations -----------------*/

/* ----------------- Data Type Declarations -----------------*/


/* ----------------- Software Interfaces Declarations -----------------*/
void LCD_command(uint8 cmd);
void LCD_data(uint8 data);
void LCD_init();
void LCD_print(const char *str);
void LCD_setCursor(uint8_t row, uint8_t col);
void LCD_defineCustomChar(uint8_t location, const uint8_t charMap[8]);
void LCD_printFloat(float value, uint8_t decimalPlaces);
#endif // LCD_H
