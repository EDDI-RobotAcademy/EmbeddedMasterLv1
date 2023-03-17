#ifndef __LED_H__
#define __LED_H__

#include "../pin/pin.h"

enum LED_STATUS {
    LED_OFF,
    LED_ON
};

typedef struct {
    int status;
    pin *pin_info_ptr;
} led;

void init_led(led *, int, const pin *);

void turn_off_led(led *);
void turn_on_led(led *);

void blink_led(led *, double);

#endif /* __LED_H__ */
