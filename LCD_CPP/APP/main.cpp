/*
 * main.cpp
 *
 *  Created on: Sep 7, 2021
 *      Author: Muhannad Shmouty
 */


#include "../Services/BIT_MATH.hpp"
#include "../Services/STD_TYPES.hpp"

#include "../MCAL/01-DIO/DIO_INTERFACE.hpp"

#include <util/delay.h>

#include "../HAL/01-LCD/LCD_interface.hpp"



LCD my_lcd (DIO_u8_PIN_A4, DIO_u8_PIN_A5, DIO_u8_PIN_A6, DIO_u8_PIN_A7, DIO_u8_PIN_B0, DIO_u8_PIN_B1);

int main(void)
{
	my_lcd.begin();
	while (1){
		my_lcd.print("Hello, world!");
		my_lcd.showCursor();
		_delay_ms(500);
		my_lcd.clear();
		_delay_ms(500);
	}

}
