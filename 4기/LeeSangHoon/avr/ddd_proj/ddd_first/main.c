/*
 */

#include <avr/io.h>

#define F_CPU   16000000UL
#include <util/delay.h>

#include "domain/led/entity/led.h"
#include "domain/pin/pin_map.h"
#include "domain/led/service/led_service_table.h"

int main(void)
{
    led_entity_init(PIN_PORT13, OUTPUT_MODE, LED_STATUS_OFF);
    // TODO: Need to convert set Direction to table
    //led_service_call_table[]

    while(1)
    {
        set_led_status(LED_STATUS_OFF);
        led_service_call_table[LED_OFF](led_entity);
        _delay_ms(500);
        set_led_status(LED_STATUS_ON);
        led_service_call_table[LED_ON](led_entity);
        _delay_ms(500);
    }

    return 0;
}
