#ifndef __LED_REPOSITORY_H__
#define __LED_REPOSITORY_H__

#include "../entity/led.h"
#include "../../pin/service/request/pin_request.h"

enum led_repository {
    SET_DIRECTION,
    GPIO_WRITE,
    LED_IO_END
};

void set_legacy_direction (struct _pin_request);
void gpio_legacy_write (struct _pin_request);
void gpio_write (struct _pin_request);

#endif
