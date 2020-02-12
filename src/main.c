/**
 * 
 * Example main.c
 * 
 * Change definition for board, to utilize intellisense for correct board.
 * 
 **/

#ifndef __AVR_ATmega2560__
#define __AVR_ATmega2560__
#endif

#include <avr/io.h>
#include <util/delay.h>
#include "../lib/def.h"

#define BUILTIN_LED PORTB, PB7

int main() {
	SETBIT(DDRB, PB7);
	while (1) {
		C_SETBIT(BUILTIN_LED);  // hello
		_delay_us(500);
		C_CLEARBIT(BUILTIN_LED);
		_delay_us(500);
	}

	return 0;
}