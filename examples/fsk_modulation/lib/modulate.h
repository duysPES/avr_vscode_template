
/**
 * 
 * Functions that modulates information based on specifications.
 * 
 * BAUDRATE = 250
 * 
 * Spacing FREQ is 2Khz
 * Marking FREQ is 1Khz
 * 
 * Spacing CYCLES = 1 / BAUDRATE * 2000 = 8
 * Marking CYCLES = 1 / BAUDRATE * 1000 = 4
 * 
 * Spacing Delay = 1 / BAUDRATE / SPACING_CYCLES / 2 = 500 us 
 * Marking Delay = 1 / BAUDRATE / MARKING_CYCLES / 2  = 250 us
 * 
 * **/

#ifndef __MODULATE_H__
#define __MODULATE_H__

#include "def.h"

#define FSK_PIN PB7
#define FSK_COMB PORTB, FSK_PIN

#define BAUDRATE 250

#define MARK_FREQ 2000
#define SPACE_FREQ 1000

#define MARK_CYCLES 4
#define SPACE_CYCLES 8

#define MARK_DELAY 500   // 10000 / 2
#define SPACE_DELAY 250  // 500 / 2

static inline void modulate_bit(byte& bit) {
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

static inline void modulate(const byte* b, byte size) {
	for (byte i = 0; i < size; i++) {
		modulate_byte(*b++);
	}
}

#endif
