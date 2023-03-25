#ifndef __LED_CONTROL_H__
#define __LED_CONTROL_H__

#include "../entity/led.h"

typedef enum _LED_CONTROL LED_CONTROL;

enum _LED_CONTROL
{
    LED_TRUN_ON,
    LED_TURN_OFF,
    LED_TOGGLE,
    LED_CONTROL_END
};

void led_turn_on(led_object *);
void led_turn_off(led_object *);
void led_toggle(led_object *);

#endif // __LED_CONTROL_H__
