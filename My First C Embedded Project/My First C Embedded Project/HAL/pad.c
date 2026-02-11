/*
 * pad.c
 *
 * Created: 2/9/2026
 * Author: Ahmed El Ashiry
 */

#include "pad.h"
#include "../MCAL/DIO_Driver/DIO_interface.h"
#include "../Library/Std.h"
#include <util/delay.h>
uint8 rows,col;
static uint8 buttons[4][4] = {
	{'H','E','L','O'},
	{'B','Y','E','x'},
	{7,8,9,'C'},
	{'*',0,'#','D'}
};

void keypad_init (void) { 
for (uint8 i =0; i <4; i++) 
SetPinDir(Row_port, Row_pin + i, OUTPUT);

for (uint8 i =0; i <4; i++) {
SetPinDir(Col_port,Col_pin + i, INPUT);
SetPinVal(Col_port, Col_pin + i, VAL_HIGH);}
}

uint8 pressed_key(void) {
	for (rows = 0; rows <4; rows ++) {
		SetPinVal(Row_port, Row_pin+rows, VAL_LOW);
		for (col = 0; col < 4; col ++) {
			if ((ReadPinVal(Col_port,Col_pin+col))==0) {
				_delay_ms(20);
				return buttons[rows][col];}
		}
		SetPinVal(Row_port, Row_pin+rows, VAL_HIGH);
	}
	return 0xFF;
}
