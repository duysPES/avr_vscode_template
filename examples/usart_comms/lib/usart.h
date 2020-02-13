/**
 * 
 * Handles USART communication
 * 
 * **/

#ifndef __USART_H__
#define __USART_H__

#ifndef __AVR_ATmega2560__
#define __AVR_ATmega2560__
#endif

#include <avr/io.h>
#include "../../../lib/def.h"
#include "stdint.h"

unsigned int ubrr_calc(unsigned int baudrate);
void usart_init(unsigned long baudrate);
void usart_transmit(byte data);
unsigned char usart_recieve(void);

#endif
