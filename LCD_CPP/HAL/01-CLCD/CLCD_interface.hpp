/*
 * CLCD_interface.h
 *
 *  Created on: Aug 30, 2021
 *      Author: Muhannad Shmouty
 */

#ifndef HAL_01_CLCD_CLCD_INTERFACE_HPP_
#define HAL_01_CLCD_CLCD_INTERFACE_HPP_
// Rows
#define CLCD_u8_ROW_00 0
#define CLCD_u8_ROW_01 1

// Coloumns
#define CLCD_u8_COL_00 0
#define CLCD_u8_COL_01 1
#define CLCD_u8_COL_02 2
#define CLCD_u8_COL_03 3
#define CLCD_u8_COL_04 4
#define CLCD_u8_COL_05 5
#define CLCD_u8_COL_06 6
#define CLCD_u8_COL_07 7
#define CLCD_u8_COL_08 8
#define CLCD_u8_COL_09 9
#define CLCD_u8_COL_10 10
#define CLCD_u8_COL_11 11
#define CLCD_u8_COL_12 12
#define CLCD_u8_COL_13 13
#define CLCD_u8_COL_14 14
#define CLCD_u8_COL_15 15

#define DATA_PINS 8


class LCD{
	private:
		bool four_bit_mode;
		u8 DATA_PORT[DATA_PINS];
		u8 u8_LCD_RS;
		u8 u8_LCD_EN;
	public:
		// Constructors
		//LCD(bool four_bit);
		LCD(u8 u8_LCD_D0, u8 u8_LCD_D1, u8 u8_LCD_D2, u8 u8_LCD_D3, u8 u8_LCD_D4,
				u8 u8_LCD_D5, u8 u8_LCD_D6, u8 u8_LCD_D7, u8 u8_LCD_RS ,u8 u8_LCD_EN);
		LCD(u8 u8_LCD_D4, u8 u8_LCD_D5, u8 u8_LCD_D6, u8 u8_LCD_D7, u8 u8_LCD_RS ,u8 u8_LCD_EN);

		// Methods
		void begin(void);
		void write(u8 Copy_u8_Data);
		void print(s8* Copy_u8_Ptr_String);
		void print(u64 Copy_u64Number);
		void sendCommand(u8 Copy_u8_Command);
		void setCursor(u8 Copy_u8Row, u8 Copy_u8Coloumn);
		void clear(void);
		void sendExtraChar(void);
};


#endif /* HAL_01_CLCD_CLCD_INTERFACE_HPP_ */
