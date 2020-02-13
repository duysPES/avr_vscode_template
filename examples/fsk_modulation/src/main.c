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

#define __STDC_CONSTANT_MACROS
#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>
#include "../lib/def.h"
#include "../lib/modulate.h"

int main() {
	SETBIT(DDRB, FSK_PIN);  // set FSK for output
	C_SETBIT(FSK_COMB);		// default it to HIGH
	const byte x[5] = {0xAD, 0xFF, 0x12, 0x45, 0xDA};

	byte x = UINT8_C(120);
	while (1) {
		modulate(x, sizeof(x) / sizeof(x[0]));
		_delay_ms(100);
	}
	return 0;
}