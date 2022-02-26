/*
 */

#include <avr/io.h>

#define F_CPU       16000000L
#include <avr/delay.h>

int main(void)
{

    DDRB = 0x20;

    while(1)
    {
        // 13번 핀
        PORTB = 0x00;
        _delay_ms(500);
        PORTB = 0x20;
        _delay_ms(500);
    }

    return 0;
}
