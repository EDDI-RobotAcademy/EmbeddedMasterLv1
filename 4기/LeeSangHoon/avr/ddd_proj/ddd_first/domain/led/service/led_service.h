#ifndef __LED_SERVICE_H__
#define __LED_SERVICE_H__

#include "../entity/led.h"

enum led_domain_service {
    LED_ON,
    LED_OFF,
    LED_TOGGLE,
    LED_END
};

void led_on (led led_entity);
void led_off (led led_entity);
void led_toggle (led led_entity);

#endif
