/**
 * 
 * Example to show an interrupt driven USART communication
 * 
 * 
 **/

#define __STDC_CONSTANT_MACROS
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdint.h>
#include "../../../lib/def.h"

#define OUTPUT_LED PORTB, PB7

#define BAUD 250
#define PRESCALER 1
#define TIMER_COMP (unsigned int)(((1.0 / (float)BAUD / PRESCALER) / (1.0 / (float)F_CPU)) - 1)

int main(void) {
	SETBIT(DDRB, PB7);		// set output LED
	SETBIT(TCCR1B, WGM12);  // set timer on CTC mode
	SETBIT(TCCR1B, CS10);   // set timer to use F_CPU; no prescaler

	OCR1A = TIMER_COMP;
	C_SETBIT(OUTPUT_LED);

	for (;;) {
		if (CHECKBIT(TIFR1, OCF1A)) {
			C_FLIPBIT(OUTPUT_LED);  // toggle pin on/off
			SETBIT(TIFR1, OCF1A);   // setting this to 1 clears the flag
		}
	}
	return 0;
}
