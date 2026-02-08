/*
 * lcd.h
 *
 * Created: 2/8/2026 2:35:32 AM
 *  Author: Ahmed El Ashiry
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "../MCAL/DIO_Driver/DIO_interface.h"
#include "../MCAL/DIO_Driver/DIO_Private.h"
#include <util/delay.h>

#define LCD_DATA_BITS_MODE 4
#define RS_PORT PORT_D
#define RS_PIN DIO_PIN0
#define EN_PORT PORT_D
#define EN_PIN DIO_PIN1

#define LCD_Data_PORT PORT_D

#define LCD_DATA_REG  PORTD
#define LCD_DDR_REG DDRD

#if (LCD_DATA_BITS_MODE == 4)

#define LCD_DB4_PIN	 DIO_PIN4
#define LCD_DB5_PIN  DIO_PIN5
#define LCD_DB6_PIN  DIO_PIN6
#define LCD_DB7_PIN	 DIO_PIN7

#endif


#define LCD_CLEAR_COMMAND 0x01
#define LCD_GO_TO_HOME 0x02
#define LCD_CURSOR_ON 0x0E
#define LCD_CURSOR_OFF 0x0C
#define LCD_CURSOR_BLINKING 0x0F
#define LCD_SET_CURSOR_LOCATION 0x80
#define LCD_TWO_LINES_8_BITS_MODE 0x38
#define LCD_TWO_LINES_4_BITS_MODE 0x28

void LCD_init(void);
void LCD_sendcommand(uint8 cmd);
void LCD_senddata(uint8 data);
void LCD_createchar(uint8 location, uint8*pattern);
void LCD_sendstring(const uint8 *str);
void LCD_moveCursor(uint8 row,uint8 col);


#endif /* LCD_H_ */