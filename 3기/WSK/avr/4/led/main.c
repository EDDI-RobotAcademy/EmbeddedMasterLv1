#include <avr/io.h>
#include <util/delay.h>

#define LED     0x01

void setup(void)
{
    int     loop_count;
    int     i;

    DDRB = LED;

    loop_count = 20;
    for (i=0; i<loop_count; i++)
    {
        PORTB ^= LED;
        _delay_ms(500);
    }
}

void loop(void)
{
}

int main(void)
{
    setup();

    while (1)
    {
        loop();
    }
}

