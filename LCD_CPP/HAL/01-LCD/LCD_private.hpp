/*
 * LCD_private.h
 *
 *  Created on: Aug 30, 2021
 *      Author: Muhannad Shmouty
 */

#ifndef HAL_01_LCD_LCD_PRIVATE_HPP_
#define HAL_01_LCD_LCD_PRIVATE_HPP_

// Function set Flags
#define CLCD_u8_8_BIT_MODE 			0b00111100
#define CLCD_u8_4_BIT_MODE_1		0b00000010
#define CLCD_u8_4_BIT_MODE_2		0b00001100
#define CLCD_u8_DISPLAY_CONTROL 	0b00001100
#define CLCD_u8_DISPLAY_CLEAR		0b00000001
#define CLCD_u8_ENTRY_MODE 			0b00000110
#define CLCD_u8DDRAM_OFFSET			0x80
#define CLCD_u8DDRAM_ROW_SHIFT 		0x40

// Bit fields for functions
#define	CLCD_u8_Cursor_bit 			0b00000001
#define	CLCD_u8_Blink_bit 			0b00000000

#define CLCD_u8_CGRAM_OFFSET 		0x40

#define CLCD_u8_CLEAR_LCD_COMMAND 	0b00000001


#define CLCD_u8_4_DATA_LENGTH 		0
#define CLCD_u8_8_DATA_LENGTH 		1
#endif /* HAL_01_LCD_LCD_PRIVATE_HPP_ */
