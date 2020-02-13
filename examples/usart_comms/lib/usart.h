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
#include "def.h"
#include "stdint.h"

#define BAUDRATE 9600
#define FOSC 16000000
#define MYUBRR FOSC / 16 / BAUDRATE - 1

void usart_init(word ubrr);

#endif
