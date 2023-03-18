#ifndef __LED_REPOSITORY_H__
#define __LED_REPOSITORY_H__

#include "../entity/led.h"

enum led_repository {
    SET_DIRECTION,
    GPIO_WRITE,
    LED_IO_END
};

void set_direction (led led_entity);
void gpio_write (led led_entity);

#endif
