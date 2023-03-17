#ifndef __LED_REPOSITORY_H__
#define __LED_REPOSITORY_H__

#include "../entity/led.h"

enum led_repository {
    LED_OUT,
    LED_IO_END
};

void led_out (led led_entity);

#endif
