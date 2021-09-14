/*
 * LCD_program.cpp
 *
 *  Created on: Aug 30, 2021
 *      Author: Muhannad Shmouty
 */

#include "../../Services/STD_TYPES.hpp"
#include "../../Services/BIT_MATH.hpp"
#include "../../MCAL/01-DIO/DIO_interface.hpp"

#include <util/delay.h>

#include "../01-LCD/LCD_config.hpp"
#include "../01-LCD/LCD_interface.hpp"
#include "../01-LCD/LCD_private.hpp"

LCD::LCD(u8 _u8_LCD_D0, u8 _u8_LCD_D1, u8 _u8_LCD_D2, u8 _u8_LCD_D3, u8 _u8_LCD_D4,
				u8 _u8_LCD_D5, u8 _u8_LCD_D6, u8 _u8_LCD_D7, u8 _u8_LCD_RS ,u8 _u8_LCD_EN){
	// 8 bit mode
	this->four_bit_mode = false;
	this->DATA_PORT[0] = _u8_LCD_D0;
	this->DATA_PORT[1] = _u8_LCD_D1;
	this->DATA_PORT[2] = _u8_LCD_D2;
	this->DATA_PORT[3] = _u8_LCD_D3;
	this->DATA_PORT[4] = _u8_LCD_D4;
	this->DATA_PORT[5] = _u8_LCD_D5;
	this->DATA_PORT[6] = _u8_LCD_D6;
	this->DATA_PORT[7] = _u8_LCD_D7;
	this->u8_LCD_EN = _u8_LCD_EN;
	this->u8_LCD_RS = _u8_LCD_RS;
}

LCD::LCD(u8 _u8_LCD_D4, u8 _u8_LCD_D5, u8 _u8_LCD_D6, u8 _u8_LCD_D7, u8 _u8_LCD_RS ,u8 _u8_LCD_EN)
{
	this->four_bit_mode = true;
	this->DATA_PORT[4] = _u8_LCD_D4;
	this->DATA_PORT[5] = _u8_LCD_D5;
	this->DATA_PORT[6] = _u8_LCD_D6;
	this->DATA_PORT[7] = _u8_LCD_D7;
	this->u8_LCD_EN = _u8_LCD_EN;
	this->u8_LCD_RS = _u8_LCD_RS;
}

void LCD::begin(void) {
	/*
	 * Configuring the 4-bit and 8-bit modes initialization
	 * Check DataSheet Page 14
	 */

	for (int PIN = 0; PIN < DATA_PINS; PIN++)
	{
		DIO_voidSetPinDirection(DATA_PORT[PIN], DIO_u8_OUTPUT);
	}

	// Set RS and EN pins to OUTPUT
	DIO_voidSetPinDirection(u8_LCD_RS, DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(u8_LCD_EN, DIO_u8_OUTPUT);

	_delay_ms(50); // Wait for more than 30ms after Vdd rises to 4.5 Volt

	if (four_bit_mode)
	{
		DIO_voidSetPinValue(u8_LCD_RS, DIO_u8_LOW);

		// Supposing that the LCD is in 4-bit Mode
		// Set the LCD to 8-bit Mode
		this->sendByte((u8)(CLCD_u8_8_BIT_MODE << 4));
		_delay_ms(5);

		// Sent again to handle if the LCD is waiting for the second half
		this->sendByte((u8)(CLCD_u8_8_BIT_MODE << 4));
		_delay_ms(5);

		// Once more!
		this->sendByte((u8)(CLCD_u8_8_BIT_MODE << 4));
		_delay_ms(5);

		// Send the 4-bit function set
		this->sendByte(CLCD_u8_4_BIT_MODE_1);
		_delay_ms(5);

		this->sendByte(CLCD_u8_4_BIT_MODE_1);
		_delay_ms(5);

		this->sendByte(CLCD_u8_4_BIT_MODE_2);
		_delay_ms(5);
	}
	else
	{
		// Function Set
		this->sendCommand(CLCD_u8_8_BIT_MODE);
		// Wait more than 39 microseconds
		_delay_ms(1);
	}

	// Display ON/OFF Control
	this->sendCommand(CLCD_u8_DISPLAY_CONTROL);
	// Wait more than 39 microseconds
	_delay_ms(1);

	// Display Clear
	this->sendCommand(CLCD_u8_DISPLAY_CLEAR);
	// Wait for more than 1.53 ms
	_delay_ms(5);

	// Entry Mode Set
	this->sendCommand(CLCD_u8_ENTRY_MODE);
	// Wait more than 39 microseconds
	_delay_ms(1);
}


void LCD::write(u8 Copy_u8_Data) {
	// RegisterSelect - > Data
	DIO_voidSetPinValue(u8_LCD_RS, DIO_u8_HIGH);

	if (four_bit_mode){
		// Send the Second 4 bits of the data
		this->writeFourBit(Copy_u8_Data);
	}
	else {
		// 8-bit mode
		this->sendByte(Copy_u8_Data);
	}
}

void LCD::writeFourBit(u8 Copy_u8_Data){
	this->sendByte(Copy_u8_Data >> 4);
	this->sendByte(Copy_u8_Data & 0x0F);
}

void LCD::sendByte(u8 Copy_u8_Data)
{
	for (int PIN = 0; PIN < DATA_PINS; PIN++)
	{
		DIO_voidSetPinValue(DATA_PORT[PIN], get_bit(Copy_u8_Data, PIN));
	}

	// Applying Falling Edge on EN pin
	DIO_voidSetPinValue(u8_LCD_EN, DIO_u8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(u8_LCD_EN, DIO_u8_LOW);
	_delay_ms(1);
}

void LCD::sendCommand(u8 Copy_u8_Command) {
	// RegisterSelect -> Command
	DIO_voidSetPinValue(u8_LCD_RS, DIO_u8_LOW);


	if (four_bit_mode){
		// Send Command on two steps
		this->writeFourBit(Copy_u8_Command);
	}
	else{
		this->sendByte(Copy_u8_Command);
	}
}

void LCD::print(s8 * Copy_u8_Ptr_String) {
	u8 LOC_u8_Iterator = 0;
	while (Copy_u8_Ptr_String[LOC_u8_Iterator] != '\0') {
		this->write(Copy_u8_Ptr_String[LOC_u8_Iterator]);
		LOC_u8_Iterator++;
	}
}

void LCD::print(u64 Copy_u64Number) {
	u64 LOC_u64Reversed = 1;
	if (Copy_u64Number == 0)
	{
		this->write('0');
	}
	else
	{
		while (Copy_u64Number != 0) {
			LOC_u64Reversed = (LOC_u64Reversed * 10) + (Copy_u64Number % 10);
			Copy_u64Number /= 10;
		}

		while (LOC_u64Reversed != 1) {
			this->write((LOC_u64Reversed % 10) + '0');
			LOC_u64Reversed /= 10;
		}
	}
}

void LCD::setCursor(u8 Copy_u8Row, u8 Copy_u8Coloumn)
{
	if (Copy_u8Row == CLCD_u8_ROW_00)
	{
		this->sendCommand(CLCD_u8DDRAM_OFFSET + Copy_u8Coloumn);
	}
	else
	{
		this->sendCommand(CLCD_u8DDRAM_OFFSET + Copy_u8Coloumn + CLCD_u8DDRAM_ROW_SHIFT);
	}
}

void LCD::sendExtraChar(void)
{
	this->sendCommand(CLCD_u8_CGRAM_OFFSET);
	u8 LOC_u8Iterator;
	for (LOC_u8Iterator = 0; LOC_u8Iterator < (sizeof(LOC_u8StaticArray) / sizeof(LOC_u8StaticArray[0])); LOC_u8Iterator++)
	{
		this->write(LOC_u8StaticArray[LOC_u8Iterator]);
	}
	this->sendCommand(CLCD_u8DDRAM_OFFSET);
}

void LCD::clear(void)
{
	this->sendCommand(CLCD_u8_CLEAR_LCD_COMMAND);
}


void LCD::showCursor(void){
	this->sendCommand(CLCD_u8_DISPLAY_CONTROL | (1<<CLCD_u8_Cursor_bit));
}

void LCD::hideCursor(void){
	this->sendCommand(CLCD_u8_DISPLAY_CONTROL & (~(1<<CLCD_u8_Cursor_bit)));
}

void LCD::blinkCursor(bool active){
	if (active){
		this->sendCommand(CLCD_u8_DISPLAY_CONTROL | (1<<CLCD_u8_Blink_bit));
	}
	else
	{
		this->sendCommand(CLCD_u8_DISPLAY_CONTROL & (~(1<<CLCD_u8_Blink_bit)));
	}
}
