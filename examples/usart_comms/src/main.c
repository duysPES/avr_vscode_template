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
#include "../lib/def.h"
#include "../lib/usart.h"

int main() {
	usart_init(MYUBRR);
	while (1) {
	}
	return 0;
}