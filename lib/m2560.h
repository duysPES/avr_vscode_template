/**
 * 
 * Extended from def.h to be more specific towards the
 * atmega2560. This is sort of going into Arduino land, to make
 * HAL or an attempt at it anyways. 
 * 
 * Include this file at the top of your main if you are using the m2560.
 * 
 **/

#ifndef __H_M2560__
#define __H_M2560__
#include <avr/io.h>
#include "def.h"

/*
 * Since "Pin" number is completely arbitrary and in Arduino world
 * each board has a predetermined mapping of pins to the a number system.
 * 
 * Therefore, to keep this library from being too incredibly forced to use
 * the same mapping as arduino we implement a very easy number system to
 * address the correct pin. A-J consists of 8 pins for each DDRn and the 
 * numbering system starts like so:
 * 
 * A0 = 0
 * A1 = 1
 * ..
 * ..
 * J8 = 80
 */
volatile static __inline__ void pinMode(byte pin, PINMODE mode) {
	byte ddrn = (byte)() switch (mode) {
	case OUTPUT:
		/* code */
		break;

	case INPUT:
		break;

	case INPUT_PULLUP:
		break;
	}
}
#endif