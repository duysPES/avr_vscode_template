
#include "../lib/usart.h"

void usart_init(word ubrr) {
	UBRR0H = (byte)(ubrr >> 8);
	UBRR0L = (byte)ubrr;

	UCSR0B = (1 << RXEN0) | (1 << TXEN0);

	UCSR0C = (1 << USBS0) | (3 << UCSZ00);
}
