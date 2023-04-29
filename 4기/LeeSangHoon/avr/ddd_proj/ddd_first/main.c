/*
 */

#include <avr/io.h>

#define F_CPU   16000000UL
#include <util/delay.h>

#include "domain/led/entity/led.h"
#include "domain/led/service/led_service_table.h"

#include "domain/led/form/led_control_form.h"

#include "domain/pin/pin_map.h"

#include "domain/pin/form/pin_control_form.h"
#include "domain/pin/service/pin_service_table.h"

/*
static unsigned char *pin_map_vo[3] = {
    (unsigned char *)0x31,
    (unsigned char *)0x37,
    (unsigned char *)0x34
};
*/

int main(void)
{
    //led_entity_init(PIN_PORT13, OUTPUT_MODE, LED_STATUS_OFF);
    // TODO: Need to convert set Direction to table
    //led_service_call_table[] -> pin_service_call_table
    //pin_control_form = { PIN_PORT13, OUTPUT_MODE };
    set_pin_control_form(PIN_PORT13, OUTPUT_MODE);
    pin_service_call_table[PIN_DIRECTION] (
        convert_pin_control_data(pin_control_form) );

    while(1)
    {
#if 1
        set_led_control_form(LED_STATUS_OFF);
        led_service_call_table[LED_OFF](
            convert_led_control_data(led_control_form));
        _delay_ms(500);
        set_led_control_form(LED_STATUS_ON);
        led_service_call_table[LED_ON](
            convert_led_control_data(led_control_form));
        _delay_ms(500);
#else
        PORTB = 0x20;
        _delay_ms(500);
        PORTB = 0x00;
        _delay_ms(500);
#endif
    }

    return 0;
}
