/*
 */

#include <avr/io.h>

#define F_CPU   16000000UL
#include <util/delay.h>

#include "domain/led/entity/led.h"
#include "domain/utility/avr_pin.h"
#include "domain/led/service/led_service_table.h"

int main(void)
{
    led_entity_init(PIN_PORT13, LED_STATUS_ON);
    // pointer of function table: led_service

    while(1)
    {
        led_service_call_table[LED_ON](led_entity);
        _delay_ms(1000);
        set_led_status(LED_OFF);
        led_service_call_table[LED_ON](led_entity);
    }

    return 0;
}
