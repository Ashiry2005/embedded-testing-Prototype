#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "HAL/lcd.h"
#include "HAL/pad.h"
#include <math.h>
int main(void)
{
	uint8 key;
	uint8 curRow = 0;
	uint8 curCol = 0;
	uint8 str[2];

	keypad_init();
	LCD_init();
	LCD_sendcommand(LCD_CLEAR_COMMAND);

	while(1)
	{
		key = pressed_key();

		if(key != 0xFF)
		{
			str[0] = key;
			str[1] = '\0';

			if(key == 'x')
			{
				if(curCol > 0) curCol--;
				LCD_moveCursor(curRow, curCol);
				str[0] = ' ';
				LCD_sendstring(str);
				LCD_moveCursor(curRow, curCol);
			}
			else
			{
				LCD_sendstring(str);
				curCol++;
				if(curCol > 15)
				{
					curCol = 0;
					curRow = (curRow == 0) ? 1 : 0;
					LCD_moveCursor(curRow, curCol);
				}
			}

			_delay_ms(50);
		}
	}
}
