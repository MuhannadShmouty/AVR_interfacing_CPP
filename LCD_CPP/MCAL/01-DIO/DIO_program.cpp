/*
 * DIO_program.c
 *
 *  Created on: Aug 30, 2021
 *      Author: Muhannad Shmouty
 */


#include <util/delay.h>

#include "../../Services/BIT_MATH.hpp"
#include "../../Services/STD_TYPES.hpp"
#include "DIO_INTERFACE.hpp"
#include "DIO_PRIVATE.hpp"



void DIO_voidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction) {
	switch (Copy_u8Port) {
	case DIO_u8_PORTA:
		DDRA = Copy_u8Direction;
		break;
	case DIO_u8_PORTB:
		DDRB = Copy_u8Direction;
		break;
	case DIO_u8_PORTC:
		DDRC = Copy_u8Direction;
		break;
	case DIO_u8_PORTD:
		DDRD = Copy_u8Direction;
		break;
	}
}

void DIO_voidSetPortValue(u8 Copy_u8Port, u8 Copy_u8Value) {
	switch (Copy_u8Port) {
	case DIO_u8_PORTA:
		PORTA = Copy_u8Value;
		break;
	case DIO_u8_PORTB:
		PORTB = Copy_u8Value;
		break;
	case DIO_u8_PORTC:
		PORTC = Copy_u8Value;
		break;
	case DIO_u8_PORTD:
		PORTD = Copy_u8Value;
		break;
	}
}

void DIO_voidSetPinDirection(u8 Copy_u8Pin, u8 Copy_u8Direction) {
	u8 Loc_u8Port = (Copy_u8Pin & 0xF0) >> 4;
	u8 Loc_u8PortPin = Copy_u8Pin & 0x0F;
	switch (Loc_u8Port) {
	case DIO_u8_PORTA:
		switch (Copy_u8Direction) {
		case DIO_u8_INPUT:
			clear_bit(DDRA, Loc_u8PortPin);
			break;
		case DIO_u8_OUTPUT:
			set_bit(DDRA, Loc_u8PortPin);
			break;
		}
		break;

	case DIO_u8_PORTB:
		switch (Copy_u8Direction) {
		case DIO_u8_INPUT:
			clear_bit(DDRB, Loc_u8PortPin);
			break;
		case DIO_u8_OUTPUT:
			set_bit(DDRB, Loc_u8PortPin);
			break;
		}
		break;

	case DIO_u8_PORTC:
		switch (Copy_u8Direction) {
		case DIO_u8_INPUT:
			clear_bit(DDRC, Loc_u8PortPin);
			break;
		case DIO_u8_OUTPUT:
			set_bit(DDRC, Loc_u8PortPin);
			break;
		}
		break;

	case DIO_u8_PORTD:
		switch (Copy_u8Direction) {
		case DIO_u8_INPUT:
			clear_bit(DDRD, Loc_u8PortPin);
			break;
		case DIO_u8_OUTPUT:
			set_bit(DDRD, Loc_u8PortPin);
			break;
		}
		break;
	}
}

void DIO_voidSetPinValue(u8 Copy_u8Pin, u8 Copy_u8Value) {
	u8 Loc_u8Port = (Copy_u8Pin & 0xF0) >> 4;
	u8 Loc_u8PortPin = Copy_u8Pin & 0x0F;
	switch (Loc_u8Port) {
		case DIO_u8_PORTA:
			switch (Copy_u8Value) {
			case DIO_u8_LOW:
				clear_bit(PORTA, Loc_u8PortPin);
				break;
			case DIO_u8_HIGH:
				set_bit(PORTA, Loc_u8PortPin);
				break;
			}
			break;

		case DIO_u8_PORTB:
			switch (Copy_u8Value) {
			case DIO_u8_LOW:
				clear_bit(PORTB, Loc_u8PortPin);
				break;
			case DIO_u8_HIGH:
				set_bit(PORTB, Loc_u8PortPin);
				break;
			}
			break;

		case DIO_u8_PORTC:
			switch (Copy_u8Value) {
			case DIO_u8_LOW:
				clear_bit(PORTC, Loc_u8PortPin);
				break;
			case DIO_u8_HIGH:
				set_bit(PORTC, Loc_u8PortPin);
				break;
			}
			break;

		case DIO_u8_PORTD:
			switch (Copy_u8Value) {
			case DIO_u8_LOW:
				clear_bit(PORTD, Loc_u8PortPin);
				break;
			case DIO_u8_HIGH:
				set_bit(PORTD, Loc_u8PortPin);
				break;
			}
			break;
		}
}

u8 DIO_u8ReadPinValue(u8 Copy_u8Pin){
	u8 Loc_u8Port = (Copy_u8Pin & 0xF0) >> 4;
	u8 Loc_u8PortPin = Copy_u8Pin & 0x0F;
	u8 LOC_u8_pinState = 0;
	switch (Loc_u8Port) {
		case DIO_u8_PORTA:
			LOC_u8_pinState = 3;//get_bit(PINA, Copy_u8Pin);
			break;
		case DIO_u8_PORTB:
			LOC_u8_pinState = get_bit(PINB, Loc_u8PortPin);
			break;
		case DIO_u8_PORTC:
			LOC_u8_pinState = get_bit(PINC, Loc_u8PortPin);
			break;
		case DIO_u8_PORTD:
			LOC_u8_pinState = get_bit(PIND, Loc_u8PortPin);
			break;
		}
	return LOC_u8_pinState;
}


void DIO_voidActivatePullup(u8 Copy_u8Port ,u8 Copy_u8Pin){
	DIO_voidSetPinDirection(Copy_u8Pin, DIO_u8_INPUT);
	DIO_voidSetPinValue(Copy_u8Pin, DIO_u8_HIGH);
}
