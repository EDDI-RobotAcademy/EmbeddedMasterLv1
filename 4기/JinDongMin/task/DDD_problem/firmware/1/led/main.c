#include <avr/io.h>

#include "entity/led/led.h"

#define TIME_TO_BLINK_LED   500

pin pin_of_pb5;
led led1;

int main(void)
{
    init_pin(&pin_of_pb5, &PORTB, PORTB4);
    init_led(&led1, LED_OFF, &pin_of_pb5);

    while (1)
    {
        blink_led(&led1, TIME_TO_BLINK_LED);
    }

    return 0;
}
