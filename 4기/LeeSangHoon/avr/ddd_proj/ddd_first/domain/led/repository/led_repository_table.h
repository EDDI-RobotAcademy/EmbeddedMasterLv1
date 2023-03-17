#ifndef __LED_REPOSITORY_TABLE_H__
#define __LED_REPOSITORY_TABLE_H__

#include "led_repository.h"

typedef void (* led_repository_call_ptr_t) (led led_entity);

const led_repository_call_ptr_t led_repository_call_table[] = {
    set_direction,
    gpio_write,
};

#endif // __LED_REPOSITORY_TABLE_H__

