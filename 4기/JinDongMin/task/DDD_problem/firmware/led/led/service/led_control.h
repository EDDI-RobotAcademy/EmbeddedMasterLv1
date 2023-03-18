#ifndef __LED_CONTROL_H__
#define __LED_CONTROL_H__

#include "../entity/led.h"

void turn_on_led(led_object *);
void turn_off_led(led_object *);
void toggle_led(led_object *);

#endif // __LED_CONTROL_H__
