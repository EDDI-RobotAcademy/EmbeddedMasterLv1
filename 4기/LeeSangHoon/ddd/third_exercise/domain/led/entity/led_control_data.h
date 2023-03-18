#ifndef __LED_CONTROL_DATA_H__
#define __LED_CONTROL_DATA_H__

typedef struct _led_control_object led_control_object;

struct _led_control_object
{
    int control_data;
};

led_control_object led_control_data;

void config_led_control_data (int);

#endif
