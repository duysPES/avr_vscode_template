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

#include <avr/io.h>
#include <util/delay.h>
#include "../lib/def.h"

#define FSK_PIN PB7
#define FSK_COMB PORTB, FSK_PIN

#define MARK_CYCLES 4
#define SPACE_CYCLES 8

#define MARK_DELAY 500   // 10000 / 2
#define SPACE_DELAY 250  // 500 / 2

static inline void modulate_bit(byte &bit) {
	if (bit) {
		for (byte i = 0; i < MARK_CYCLES; i++) {
			C_CLEARBIT(FSK_COMB);
			_delay_us(MARK_DELAY);
			C_SETBIT(FSK_COMB);
			_delay_us(MARK_DELAY);
		}
	} else {
		for (byte i = 0; i < SPACE_CYCLES; i++) {
			C_CLEARBIT(FSK_COMB);
			_delay_us(SPACE_DELAY);
			C_SETBIT(FSK_COMB);
			_delay_us(SPACE_DELAY);
		}
	}
}

static inline void modulate_byte(byte b) {
	for (byte i = 0; i < BITS_IN_BYTE; i++) {
		byte bit = (b >> i) & 0x01;
		modulate_bit(bit);
	}
}

int main() {
	SETBIT(DDRB, FSK_PIN);  // set FSK for output
	C_SETBIT(FSK_COMB);		// default it to HIGH
	const byte x = 0xAD;
	while (1) {
		modulate_byte(x);
		_delay_ms(100);
	}
	return 0;
}