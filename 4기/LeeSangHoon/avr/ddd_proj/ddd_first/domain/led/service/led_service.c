#include "led_service.h"
#include "../repository/led_repository_table.h"

void led_on (led led_entity)
{
    led_repository_call_table[LED_OUT](led_entity);
}

void led_off (void)
{
    for (int i = 0; i < 1000000; i++) {
        ;
    }
}

void led_toggle (void)
{
    for (int i = 0; i < 1000000; i++) {
        ;
    }
}
