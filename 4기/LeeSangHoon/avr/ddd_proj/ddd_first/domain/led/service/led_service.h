#ifndef __LED_SERVICE_H__
#define __LED_SERVICE_H__

//#include "../entity/led.h"
#include "../form/led_control_form.h"

enum led_domain_service {
    LED_ON,
    LED_OFF,
    LED_TOGGLE,
    LED_END
};

void led_on (struct _pin_request);
void led_off (struct _pin_request);
void led_toggle (struct _pin_request);

#endif
