#define __AVR_ATtiny84A__

#include <avr/io.h>
#include <util/delay.h>

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