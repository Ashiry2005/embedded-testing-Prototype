#define F_CPU 8000000ul

#include "HAL/lcd.h"

#define LED_PORT PORT_A
#define LED_PIN DIO_PIN0
#define SW_PORT PORT_C
#define SW_PIN DIO_PIN0

int main(void)
{
	SetPinDir(LED_PORT, LED_PIN, OUTPUT);
	SetPinDir(SW_PORT, SW_PIN, INPUT);

	SetPinVal(LED_PORT, LED_PIN, VAL_LOW);
	SetPinVal(SW_PORT, SW_PIN, VAL_HIGH);  

	LCD_init();

	while(1)
	{
		if (ReadPinVal(SW_PORT, SW_PIN) == 0)    
		{
			SetPinVal(LED_PORT, LED_PIN, VAL_HIGH);

			LCD_sendcommand(LCD_CLEAR_COMMAND);
			LCD_moveCursor(0,0);
			LCD_sendstring((uint8*)"BUTTON ON");
		}
		else  
		{
			SetPinVal(LED_PORT, LED_PIN, VAL_LOW);

			LCD_sendcommand(LCD_CLEAR_COMMAND);
		}
	}
}
