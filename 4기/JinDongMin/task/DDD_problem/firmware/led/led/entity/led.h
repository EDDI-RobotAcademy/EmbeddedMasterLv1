#ifndef __LED_H__
#define __LED_H__

#include "../../pin/pin.h"

typedef enum _LED_STATUS LED_STATUS;

enum _LED_STATUS {
    LED_OFF,
    LED_ON,
    LED_END
};

typedef struct _led_object led_object;

struct _led_object {
    pin *pin_info_ptr;
    LED_STATUS status;
};

void init_led(led_object *, const pin *);
void set_led_status(led_object *, LED_STATUS);
LED_STATUS get_led_status(const led_object *);

#endif // __LED_H__
