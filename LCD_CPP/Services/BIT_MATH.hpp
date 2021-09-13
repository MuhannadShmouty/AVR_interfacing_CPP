/*
 * BIT_MATH.h
 *
 *  Created on: Aug 28, 2021
 *      Author: Muhannad Shmouty
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define set_bit(byte, bit) (byte |= (1 << (bit)))
#define get_bit(byte, bit) ((byte) >> (bit) & 1)
#define clear_bit(byte, bit) (byte &= ~(1 << (bit)))
#define toggle_bit(byte, bit) (byte ^= (1 << (bit)))


#endif /* BIT_MATH_H_ */
