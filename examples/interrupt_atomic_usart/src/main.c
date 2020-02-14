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
#include <util/atomic.h>
#include "../../../lib/def.h"

#define BAUDRATE 9600
#define BAUD_PRESCALER (((F_CPU / (BAUDRATE * 16UL))) - 1)

volatile byte counter = 0;

void init_interrupts() {
	// USART Control and Status Register B
	SETBIT(UCSR0B, RXCIE0);  // set RX recieve interrupt flag

	// External Interrupt Control Register A
	SETBITMASK(EICRA, 0x02);  // generates interrupt on falling edge of INT0

	//External Interrupt Mask Register
	SETBIT(EIMSK, INT0);  // enable external interrupt pin INT0_

	sei();
}

int main(void) {
	SETBIT(UCSR0B, RXEN0);  // RX on
	SETBIT(UCSR0B, TXEN0);  // TX on

	// write to USART Control and Status Register C
	CLEARBIT(UCSR0C, USBS0);   // 1 stop bit
	SETBITMASK(UCSR0C, 0x03);  // 8 bit data

	UBRR0 = BAUD_PRESCALER;

	init_interrupts();
	for (;;) {
		// show casing ATOMIC operation, so that ISR and main loop
		// doesn't clobber value at counter!
		ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
			counter++;
		}
	}
	return 0;
}

// handle USART communication by triggering an echo
// when byte is recieved!
ISR(USART0_RX_vect) {
	char recv_byte;
	recv_byte = UDR0;
	UDR0 = recv_byte;
}

// increment a value when a pin detects falling edge occurs
ISR(INT0_vect) {
	counter++;
}