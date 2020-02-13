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
		byte recv_data = usart_recieve();
		char str[] = "You said: ";

		for (byte i = 0; i < sizeof(str) / sizeof(str[0]); i++) {
			usart_transmit(str[i]);
		}
		usart_transmit(recv_data);
		usart_transmit('\r');
		usart_transmit('\n');
	}
	return 0;
}