#ifndef __LED_H__
#define __LED_H__

#include "../../pin/pin.h"

enum LED_STATUS {
    LED_OFF,
    LED_ON
};

typedef struct _led_object led_object;

struct _led_object {
    pin *pin_info_ptr;
    int status;
};

void init_led(led_object *, pin *);
void change_led_status(led_object *, int);

#endif // __LED_H__
