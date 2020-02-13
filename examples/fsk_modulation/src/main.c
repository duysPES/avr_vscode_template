/**
 * 
 * Modulates data on a bit by bit basis using the following specification
 * 
 * Marking Frequency = 1Khz
 * Spacking Frequency = 2Khz
 * 
 **/

#ifndef __AVR_ATmega2560__
#define __AVR_ATmega2560__
#endif

// #define __STDC_CONSTANT_MACROS
#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>
#include "../../../lib/def.h"
#include "../lib/modulate.h"

int main()
{
	SETBIT(DDRB, FSK_PIN); // set FSK for output
	SETBIT(DDRB, DBG_PIN);

	C_SETBIT(FSK_COMB);   // default it to HIGH
	C_CLEARBIT(DBG_COMB); // default to LOW

	// const byte packet[] = {0x1A, 0x2B, 0x3C, 0x4D, 0x5E};
	const byte x = 0x45;
	while (1)
	{
		// modulate(packet, 5);
		modulate_byte(x);
		_delay_ms(500);
	}
	return 0;
}