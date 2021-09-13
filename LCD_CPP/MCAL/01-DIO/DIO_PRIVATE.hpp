/*
 * DIO_PRIVATE.h
 *
 *  Created on: Aug 28, 2021
 *      Author: Muhannad Shmouty
 */

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

/*  PORTA Register */
#define DDRA *((u8 volatile *) 0x3A)
#define PORTA *((u8 volatile *) 0x3B)
#define PINA *((u8 volatile *) 0x39)

/* PORTB REGISTER   */
#define DDRB *((u8 volatile *) 0x37)
#define PORTB *((u8 volatile *) 0x38)
#define PINB *((u8 volatile *) 0x36)

/* PORTC REGISTER   */
#define DDRC *((u8 volatile *) 0x34)
#define PORTC *((u8 volatile *) 0x35)
#define PINC *((u8 volatile *) 0x33)


/* PORTD REGISTER   */
#define DDRD *((u8 volatile *) 0x31)
#define PORTD *((u8 volatile *) 0x32)
#define PIND *((u8 volatile *) 0x30)

#endif /* DIO_PRIVATE_H_ */
