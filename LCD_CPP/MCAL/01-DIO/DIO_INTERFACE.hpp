/*
 * DIO_INTERFACE.h
 *
 *  Created on: Aug 28, 2021
 *      Author: Muhannad Shmouty
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "../../Services/STD_TYPES.hpp"
#define DIO_u8_PORTA 0
#define DIO_u8_PORTB 1
#define DIO_u8_PORTC 2
#define DIO_u8_PORTD 3

#define DIO_u8_PORT_OUTPUT 0xFF
#define DIO_u8_INPUT 0
#define DIO_u8_OUTPUT 1

#define DIO_u8_LOW 0
#define DIO_u8_HIGH 1

/***   PORTA PINS   ***/
#define DIO_u8_PIN_A0 ((DIO_u8_PORTA<<4) | 0x00)
#define DIO_u8_PIN_A1 ((DIO_u8_PORTA<<4) | 0x01)
#define DIO_u8_PIN_A2 ((DIO_u8_PORTA<<4) | 0x02)
#define DIO_u8_PIN_A3 ((DIO_u8_PORTA<<4) | 0x03)
#define DIO_u8_PIN_A4 ((DIO_u8_PORTA<<4) | 0x04)
#define DIO_u8_PIN_A5 ((DIO_u8_PORTA<<4) | 0x05)
#define DIO_u8_PIN_A6 ((DIO_u8_PORTA<<4) | 0x06)
#define DIO_u8_PIN_A7 ((DIO_u8_PORTA<<4) | 0x07)


/***   PORTB PINS   ***/
#define DIO_u8_PIN_B0 ((DIO_u8_PORTB<<4) | 0x00)
#define DIO_u8_PIN_B1 ((DIO_u8_PORTB<<4) | 0x01)
#define DIO_u8_PIN_B2 ((DIO_u8_PORTB<<4) | 0x02)
#define DIO_u8_PIN_B3 ((DIO_u8_PORTB<<4) | 0x03)
#define DIO_u8_PIN_B4 ((DIO_u8_PORTB<<4) | 0x04)
#define DIO_u8_PIN_B5 ((DIO_u8_PORTB<<4) | 0x05)
#define DIO_u8_PIN_B6 ((DIO_u8_PORTB<<4) | 0x06)
#define DIO_u8_PIN_B7 ((DIO_u8_PORTB<<4) | 0x07)


/***   PORTC PINS   ***/
#define DIO_u8_PIN_C0 ((DIO_u8_PORTC<<4) | 0x00)
#define DIO_u8_PIN_C1 ((DIO_u8_PORTC<<4) | 0x01)
#define DIO_u8_PIN_C2 ((DIO_u8_PORTC<<4) | 0x02)
#define DIO_u8_PIN_C3 ((DIO_u8_PORTC<<4) | 0x03)
#define DIO_u8_PIN_C4 ((DIO_u8_PORTC<<4) | 0x04)
#define DIO_u8_PIN_C5 ((DIO_u8_PORTC<<4) | 0x05)
#define DIO_u8_PIN_C6 ((DIO_u8_PORTC<<4) | 0x06)
#define DIO_u8_PIN_C7 ((DIO_u8_PORTC<<4) | 0x07)


/***   PORTD PINS   ***/
#define DIO_u8_PIN_D0 ((DIO_u8_PORTD<<4) | 0x00)
#define DIO_u8_PIN_D1 ((DIO_u8_PORTD<<4) | 0x01)
#define DIO_u8_PIN_D2 ((DIO_u8_PORTD<<4) | 0x02)
#define DIO_u8_PIN_D3 ((DIO_u8_PORTD<<4) | 0x03)
#define DIO_u8_PIN_D4 ((DIO_u8_PORTD<<4) | 0x04)
#define DIO_u8_PIN_D5 ((DIO_u8_PORTD<<4) | 0x05)
#define DIO_u8_PIN_D6 ((DIO_u8_PORTD<<4) | 0x06)
#define DIO_u8_PIN_D7 ((DIO_u8_PORTD<<4) | 0x07)



void DIO_voidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction);
void DIO_voidSetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);
void DIO_voidSetPinDirection(u8 Copy_u8Pin, u8 Copy_u8Direction);
void DIO_voidSetPinValue(u8 Copy_u8Pin, u8 Copy_u8Value);

u8 DIO_u8ReadPinValue(u8 Copy_u8Port ,u8 Copy_u8Pin);
void DIO_voidActivatePullup(u8 Copy_u8Port ,u8 Copy_u8Pin);

#endif /* DIO_INTERFACE_H_ */
