#define __AVR_ATtiny84A__

#define OFF(PORT, PIN) (PORT |= (0 << PIN))
#define ON(PORT, PIN) (PORT |= (1 << PIN))

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

typedef unsigned char byte;
typedef byte Pin;

volatile unsigned long milliseconds;

ISR(TIM0_COMPA_vect)
{
    ++milliseconds;
}

unsigned long millis(void)
{
    return milliseconds;
}

int main()
{

    DDRA = 0x01;
    while (1)
    {
        PORTA |= (1 << PA2);
        _delay_ms(1000);
        PORTA |= (0 << PA2);
        _delay_ms(1000);
    }

    return 0;
}