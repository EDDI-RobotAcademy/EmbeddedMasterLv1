#include "led_service.h"
#include "../repository/led_repository_table.h"

void led_on (led led_entity)
{
    led_repository_call_table[SET_DIRECTION](led_entity);
    led_repository_call_table[GPIO_WRITE](led_entity);
}

void led_off (led led_entity)
{
    led_repository_call_table[SET_DIRECTION](led_entity);
    led_repository_call_table[GPIO_WRITE](led_entity);
}

void led_toggle (led led_entity)
{

}
