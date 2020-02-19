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

// static inline void setbit(unsigned char *address, unsigned char bit) {
// 	*address |= (1 << bit);
// }

static inline void setbit(volatile unsigned char *address, unsigned char bit) {
	*address |= (1 << bit);
}

static inline void clearbit(volatile unsigned char *address, unsigned char bit) {
	*address &= ~(1 << bit);
}

int main() {
	// setbit(DDRB, PB7);
	SETBIT(DDRB, PB7);
	byte x = 0;
	while (true) {
		setbit(&x, PB7);
		// SETBIT(PORTB, PB7);
		_delay_ms(500);
		clearbit(&PORTB, PB7);
		// CLEARBIT(PORTB, PB7);
		// CLEARBIT(PORTB, PB7);

		_delay_ms(500);
	}

	return 0;
}