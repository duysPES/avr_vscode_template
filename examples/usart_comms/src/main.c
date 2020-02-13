/**
 * 
 * Example to show how to setup USART
 * 
 * Marking Frequency = 1Khz
 * Spacking Frequency = 2Khz
 * 
 **/
#define __STDC_CONSTANT_MACROS
#include <avr/io.h>
#include <stdint.h>
#include "../../../lib/def.h"
#include "../lib/usart.h"

#define BAUDRATE 9600
int main() {
	usart_init(BAUDRATE);
	while (1) {
		usart_transmit('a');
		usart_transmit('\r');
		usart_transmit('\n');
		_delay_ms(500);
	}
	return 0;
}