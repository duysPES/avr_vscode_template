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
	SETBIT(DDRB, PB7);		 // set output LED
	SETBIT(TCCR1B, WGM12);   // set timer on CTC mode
	SETBIT(TCCR1B, CS10);	// set timer to use F_CPU; no prescaler
	SETBIT(TIMSK1, OCIE1A);  // enable CTC interrupt

	OCR1A = TIMER_COMP;
	C_SETBIT(OUTPUT_LED);
	sei();

	for (;;) {
	}
	return 0;
}

ISR(TIMER1_COMPA_vect) {
	C_FLIPBIT(OUTPUT_LED);
}