/**
 *
 * Definitions of portable utilities.
 *
 * **/

#ifndef __AVR_DEF_H__
#define __AVR_DEF_H__

#include <util/delay.h>
/********************** ALIASES AND TYPEDEFS ******************************/
#define true 1
#define false 0
#define BITS_IN_BYTE 8
#define BITS_IN_WORD 16

typedef unsigned char uint8_t;
typedef unsigned int uint16_t;

typedef uint8_t byte;
typedef uint16_t word;

/**************************************************************************/

/********************** BIT MANIPULATION **********************************/
//  Usage:
//  #define BUILTIN_LED PORTA, PA3
//
//  C_SETBIT(BUILTIN_LED)   // turns it on
//  C_CLEARBIT(BUILTIN_LED) // turns if off
//
#define CLEAR(ADDRESS) (ADDRESS = 0x00)
#define SET(ADDRESS) (ADDRESS = 0xff)

#define UPPER_16(DATA) ((unsigned char)(DATA >> 8))
#define LOWER_16(DATA) ((unsigned char)(DATA))

#define SETBIT(ADDRESS, BIT) (ADDRESS |= (1 << BIT))
#define CLEARBIT(ADDRESS, BIT) (ADDRESS &= ~(1 << BIT))
#define FLIPBIT(ADDRESS, BIT) (ADDRESS ^= (1 << BIT))
#define CHECKBIT(ADDRESS, BIT) (ADDRESS & (1 << BIT))

#define SETBITMASK(x, y) (x |= (y))
#define CLEARBITMASK(x, y) (x &= (~y))
#define FLIPBITMASK(x, y) (x ^= (y))
#define CHECKBITMASK(x, y) (x & (y))

#define VARFROMCOMB(x, y) x
#define BITFROMCOMB(x, y) y

#define C_SETBIT(comb) SETBIT(VARFROMCOMB(comb), BITFROMCOMB(comb))
#define C_CLEARBIT(comb) CLEARBIT(VARFROMCOMB(comb), BITFROMCOMB(comb))
#define C_FLIPBIT(comb) FLIPBIT(VARFROMCOMB(comb), BITFROMCOMB(comb))
#define C_CHECKBIT(comb) CHECKBIT(VARFROMCOMB(comb), BITFROMCOMB(comb))
/*************************************************************************/

/********************** TIME RELATED *************************************/
volatile static __inline__ void delay_ms(unsigned int ms) {
	do {
		_delay_ms(1);
	} while (ms--);
}

volatile static __inline__ void delay_us(unsigned int us) {
	do {
		_delay_us(1);
	} while (us--);
}

/*************************************************************************/

#endif