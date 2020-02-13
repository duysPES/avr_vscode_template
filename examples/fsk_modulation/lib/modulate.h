
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

#include "../../../lib/def.h"

#define FSK_PIN PB5
#define DBG_PIN PB0

#define FSK_COMB PORTB, FSK_PIN
#define DBG_COMB PORTB, DBG_PIN

#define BAUDRATE 250

#define MARK_FREQ 2000
#define SPACE_FREQ 1000

#define MARK_CYCLES 4
#define SPACE_CYCLES 8

#define MARK_DELAY 500  // 10000 / 2
#define SPACE_DELAY 250 // 500 / 2

static inline void modulate_bit(byte const &bit)
{
	if (bit)
	{
		C_SETBIT(DBG_COMB);
		for (byte i = 0; i < MARK_CYCLES; i++)
		{
			C_CLEARBIT(FSK_COMB);
			_delay_us(MARK_DELAY);
			C_SETBIT(FSK_COMB);
			_delay_us(MARK_DELAY);
		}
	}
	else
	{
		C_CLEARBIT(DBG_COMB);

		for (byte i = 0; i < SPACE_CYCLES; i++)
		{
			C_CLEARBIT(FSK_COMB);
			_delay_us(SPACE_DELAY);
			C_SETBIT(FSK_COMB);
			_delay_us(SPACE_DELAY);
		}
	}
}

// when modulating the byte, we must have LSb first in time
// with MSb last
static inline void modulate_byte(byte b)
{
	modulate_bit(0x00); // start_bit
	for (byte i = BITS_IN_BYTE; i > 0; i--)
	{
		byte bit = (b >> i) & 0x01;
		modulate_bit(bit);
	}

	modulate_bit(0x01); // stop_bit
}

static inline void modulate(const byte *b, byte size)
{
	for (byte i = 0; i < size; i++)
	{
		modulate_byte(*b++);
	}
}

#endif
