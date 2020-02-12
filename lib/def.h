/**
 *
 * Definitions of portable utilities.
 *
 * **/

#ifndef __AVR_DEF_H__
#define __AVR_DEF_H__

/********************** ALIASES AND TYPEDEFS ******************************/
#define true 1
#define false 0

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

#endif