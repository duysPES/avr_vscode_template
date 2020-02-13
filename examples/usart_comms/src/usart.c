
/**
 * 
 * This example uses TX0 and RX0 for usart communication
 * 
 * 
 * **/

#include "../lib/usart.h"

/**
 * calculates the required ubrr value based on 
 * clock speed and preferred baudrate. 
 * 
 * - 
 * 	Note if UBRR is fractional, it will truncate.
 * 	Also that means transmit speed isn't exactly desired
 * 	baudrate
 * **/
unsigned int ubrr_calc(unsigned int baudrate) {
	return F_CPU / 16 / baudrate - 1;
}

/**
 * 
 * Example of how to initialize a USART
 * **/
void usart_init(unsigned long baudrate) {
	// write to USART Baud Rate Register
	UBRR0 = ubrr_calc(baudrate);

	// write to USART Control and Status Register B
	SETBIT(UCSR0B, RXEN0);  // RX on
	SETBIT(UCSR0B, TXEN0);  // TX on

	// write to USART Control and Status Register C
	SETBIT(UCSR0C, USBS0);	 // 2 stop bit
	SETBITMASK(UCSR0C, 0x03);  // 8 bit daata
}

/**
 * 
 * Transmit data on USART channel
 * **/

void usart_transmit(byte data) {
	// wait for current transmit buffer to empty
	// while (!(UCSR0A & (1 << UDRE0)))
	// 	;

	while (!CHECKBIT(UCSR0A, UDRE0))
		;
	// by writing to data to register it will send
	UDR0 = data;
}

/**
 * 
 * Receive data on USART channel
 * **/
unsigned char usart_recieve(void) {
	// wait for data to be recieved
	while (!CHECKBIT(UCSR0A, RXC0))
		;

	// return data from buffer
	return UDR0;
}
