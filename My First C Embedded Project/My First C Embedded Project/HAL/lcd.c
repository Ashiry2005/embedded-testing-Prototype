/*
 * lcd.c
 *
 * Created: 2/8/2026 2:43:08 AM
 *  Author: Ahmed El Ashiry
 */ 
#include "lcd.h"
#include "../Library/Macros.h"
#include "../MCAL/DIO_Driver/DIO_interface.h"
#include "../MCAL/DIO_Driver/DIO_Private.h"
#include "../Library/Std.h"



void LCD_EnablePulse(void) {
	SetPinVal(EN_PORT, EN_PIN, VAL_HIGH);
	_delay_ms(1);
	SetPinVal(EN_PORT, EN_PIN, VAL_LOW);
	_delay_ms(2);
}

void LCD_sendcommand(uint8 cmd) {
	SetPinVal(RS_PORT, RS_PIN, VAL_LOW);
	
	LCD_DATA_REG = (LCD_DATA_REG & 0x0F)|(cmd & 0xF0);
	LCD_EnablePulse();
	LCD_DATA_REG = (LCD_DATA_REG & 0x0F)|(cmd <<4);
	LCD_EnablePulse();
}

void LCD_senddata(uint8 data) {
	SetPinVal(RS_PORT, RS_PIN, VAL_HIGH);
	
	LCD_DATA_REG = (LCD_DATA_REG & 0x0F)|(data & 0xF0);
	LCD_EnablePulse();
	LCD_DATA_REG = (LCD_DATA_REG & 0x0F)|(data <<4);
	LCD_EnablePulse();
}


 void LCD_init(void){
	 SetPinDir(EN_PORT,EN_PIN,OUTPUT);
	 SetPinDir(RS_PORT, RS_PIN,OUTPUT);
	 SetPinDir(PORT_D, DIO_PIN4, OUTPUT);
	 SetPinDir(PORT_D, DIO_PIN5, OUTPUT);
	 SetPinDir(PORT_D, DIO_PIN6, OUTPUT);
	 SetPinDir(PORT_D, DIO_PIN7, OUTPUT);
	 _delay_ms(20);
     LCD_sendcommand(0x33);
     LCD_sendcommand(0x32);
     LCD_sendcommand(0x28);    // 4-bit, 2 lines
     LCD_sendcommand(0x0C);    // display ON, cursor OFF
     LCD_sendcommand(0x01);    // clear display
     _delay_ms(2);
 }
void LCD_createchar(uint8 location, uint8*pattern){
	uint8 i;
	LCD_sendcommand(0x40 + (location*8));
	for (i =0; i <8; i++) {
		LCD_senddata(pattern[i]);
	}
	LCD_sendcommand(0x80);
}

	
void LCD_sendstring(const uint8 *str)
{
	while(*str != '\0')  // Loop until we reach the end of the string
	{
		LCD_senddata(*str);  // Send the current character
		str++;                
	}

}
	void LCD_moveCursor(uint8 row, uint8 col) {
		uint8 lcdMemory;
		switch(row){
			case 0:
			lcdMemory =col;
			break;
			case 1:
			lcdMemory = col + 0x40;
			break;
		}
		LCD_sendcommand(lcdMemory | LCD_SET_CURSOR_LOCATION);
	}	

