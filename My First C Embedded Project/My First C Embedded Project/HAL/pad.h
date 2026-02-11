/*
 * pad.h
 *
 * Created: 2/9/2026 6:59:02 PM
 *  Author: Ahmed El Ashiry
 */ 


#ifndef PAD_H_
#define PAD_H_
#include "../Library/std.h"
#include "../MCAL/DIO_Driver/DIO_interface.h"
#include "../MCAL/DIO_Driver/DIO_Private.h"

#define Row_Num 4
#define Col_num 4
#define Row_port PORT_A
#define Row_pin DIO_PIN0
#define Col_port PORT_B
#define Col_pin DIO_PIN0
uint8 pressed_key (void);
void keypad_init (void);

#endif

