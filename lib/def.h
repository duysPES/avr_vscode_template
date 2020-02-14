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

typedef enum { LOW,
			   HIGH } PINSTATE;

typedef enum { INPUT = 0,
			   OUTPUT = 1,
			   INPUT_PULLUP = 2 } PINMODE;

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

/* Clears a register */
#define CLEAR(ADDRESS) (ADDRESS = 0x00)

/* Sets a register to one */
#define SET(ADDRESS) (ADDRESS = 0xff)

/* Extracts the upper value of a 16bit value */
#define UPPER_16(DATA) ((unsigned char)(DATA >> 8))

/* Extracts the lower 16bit value*/
#define LOWER_16(DATA) ((unsigned char)(DATA))

/* Sets a particular bit in byte */
#define SETBIT(ADDRESS, BIT) (ADDRESS |= (1 << BIT))

/*Clears a particular bit in byte*/
#define CLEARBIT(ADDRESS, BIT) (ADDRESS &= ~(1 << BIT))

/* Flips a bit in a byte 1->0 || 0->1*/
#define FLIPBIT(ADDRESS, BIT) (ADDRESS ^= (1 << BIT))

/* Checks to see if particular bit is set or not */
#define CHECKBIT(ADDRESS, BIT) (ADDRESS & (1 << BIT))

/* Sets contents of x based on the value of y */
#define SETBITMASK(x, y) (x |= (y))

/* Clears contents of x based on value of y */
#define CLEARBITMASK(x, y) (x &= (~y))

/* Flips contents of x based on that of y */
#define FLIPBITMASK(x, y) (x ^= (y))

/*Checks if bits are set based on y */
#define CHECKBITMASK(x, y) (x & (y))

#define VARFROMCOMB(x, y) x
#define BITFROMCOMB(x, y) y

#define C_SETBIT(comb) SETBIT(VARFROMCOMB(comb), BITFROMCOMB(comb))
#define C_CLEARBIT(comb) CLEARBIT(VARFROMCOMB(comb), BITFROMCOMB(comb))
#define C_FLIPBIT(comb) FLIPBIT(VARFROMCOMB(comb), BITFROMCOMB(comb))
#define C_CHECKBIT(comb) CHECKBIT(VARFROMCOMB(comb), BITFROMCOMB(comb))
/*************************************************************************/

/*********************** ARDUINO FAMILY ***********************************/

/*
 * Creates a way to change pin state, arduino-like
 */
#define digitalWrite(comb, state) (state ? SETBIT(VARFROMCOMB(comb), BITFROMCOMB(comb)) : CLEARBIT(VARFROMCOMB(comb), BITFROMCOMB(comb)))

/*
 * Creates a way to read digital pin state, arduino-like
 */
#define digitalRead(comb) CHECKBIT(VARFROMCOMB(comb), BITFROMCOMB(comb))

/**************************************************************************/

/********************** TIME RELATED *************************************/

/*
 * dynamically create millisecond delay
 * Note because of the overhead of the function call, this delay
 * isn't extremely accurate. 
 */
volatile static __inline__ void delay_ms(unsigned int ms) {
	do {
		_delay_ms(1);
	} while (ms--);
}

/**
 * dynamically create microsecond delay
 * Note because of the overhead of the function call, this delay
 * isn't extremely accurate. 
 **/
volatile static __inline__ void delay_us(unsigned int us) {
	do {
		_delay_us(1);
	} while (us--);
}

/*************************************************************************/

#endif