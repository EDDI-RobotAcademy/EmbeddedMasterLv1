#include "led_service.h"
#include "../repository/led_repository_table.h"

void led_on (struct _pin_request led_pin_request)
{
    //led_repository_call_table[SET_DIRECTION](led_entity);
    led_repository_call_table[GPIO_WRITE](led_pin_request);
}

void led_off (struct _pin_request led_pin_request)
{
    //led_repository_call_table[SET_DIRECTION](led_entity);
    led_repository_call_table[GPIO_WRITE](led_pin_request);
}

void led_toggle (struct _pin_request led_pin_request)
{

}
