/*
 * DIO_program.c
 *
 * Created: 2/6/2026 9:35:08 PM
 *  Author: Ahmed El Ashiry
 */ 
#include "DIO_interface.h"
#include "DIO_private.h"
#include "../../Library/Std.h"
#include "../../Library/Macros.h"


static volatile uint8* getDDR(PORT_t port) {
	switch (port) {
		case PORT_A: return &DDRA;
		case PORT_B: return &DDRB;
		case PORT_C: return &DDRC;
		case PORT_D: return &DDRD;
	}
	return NULL_PTR;
}

static volatile uint8* getPORT(PORT_t port) {
	switch(port) {
		case PORT_A: return &PORTA;
		case PORT_B: return &PORTB;
		case PORT_C: return &PORTC;
		case PORT_D: return &PORTD;
	}
	return NULL_PTR;
}

static volatile uint8* getPIN(PORT_t port){
	switch(port) {
		case PORT_A: return &PINA;
		case PORT_B: return &PINB;
		case PORT_C: return &PINC;
		case PORT_D: return &PIND;
		}
		return NULL_PTR;
}

void SetPortDir(PORT_t port, DIR_t dir) {
	volatile uint8 *DDR =getDDR(port) ;
	if (DDR == NULL_PTR) return;
	if(dir==OUTPUT) {
		*DDR=0xFF;
	} else {
		*DDR=0x00;
		}
	}
void SetPinDir(PORT_t port, PIN_t pin, DIR_t dir) {
	volatile uint8 *DDR =getDDR( port) ;
	if (DDR == NULL_PTR) return ;
	if (dir==OUTPUT) {
		BIT_SET(*DDR, pin);
	}
	else {
		BIT_CLR (*DDR, pin);
	}
}


void SetPinVal(PORT_t port, PIN_t pin, VAL_t val){
	volatile uint8 *PORT =getPORT( port);
	if (PORT==NULL_PTR) return ;
	if (val== VAL_HIGH) {
		 BIT_SET(*PORT, pin);
	}
	else {
		BIT_CLR(*PORT, pin);
	}
}
void SetPortVal(PORT_t port, uint8 value ) {
	volatile uint8 *PORT =getPORT(port);
	if (PORT==NULL_PTR) return;
	*PORT = value;
}

uint8 ReadPinVal(PORT_t port, PIN_t pin){
	volatile uint8 *PIN =getPIN(port);
	if (PIN==NULL_PTR) return 0;
	return BIT_GET(*PIN, pin);
	
}
uint8 ReadPortVal(PORT_t port) {
	volatile uint8* PIN = getPIN(port);
	if (PIN == NULL_PTR) return 0;

	return *PIN;   // Return all 8 bits
}
