/*
 * DIO_interface.h
 *
 * Created: 2/6/2026 8:55:57 PM
 *  Author: Ahmed El Ashiry
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
#include "../../Library/Std.h"
typedef enum port{
	PORT_A,
	PORT_B,
	PORT_C,
	PORT_D
	} PORT_t;
typedef enum pin {
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
	} PIN_t;
	
typedef enum dir{
	INPUT,
	OUTPUT
	} DIR_t;	
typedef enum val {
	VAL_LOW,
	VAL_HIGH
	} VAL_t;

void SetPinDir(PORT_t port, PIN_t pin, DIR_t dir);
void SetPortDir(PORT_t port, DIR_t dir);
void SetPinVal(PORT_t port, PIN_t pin, VAL_t val);
void SetPortVal(PORT_t port, uint8 value );
uint8 ReadPinVal(PORT_t port, PIN_t pin);
uint8 ReadPortVal(PORT_t port);




#endif /* DIO_INTERFACE_H_ */