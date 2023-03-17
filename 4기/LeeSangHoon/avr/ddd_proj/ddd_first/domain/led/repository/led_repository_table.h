#ifndef __LED_REPOSITORY_TABLE_H__
#define __LED_REPOSITORY_TABLE_H__

#include "led_repository.h"
#include "../entity/led.h"

typedef void (* led_repository_call_ptr_t) (led led_entity);

const led_repository_call_ptr_t led_repository_call_table[] = {
    led_out,
};

#endif // __LED_REPOSITORY_TABLE_H__

