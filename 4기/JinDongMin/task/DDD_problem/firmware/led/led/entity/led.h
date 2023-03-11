#ifndef __LED_H__
#define __LED_H__

enum LED_STATUS {
    LED_OFF,
    LED_ON
};

typedef struct _led_object led_object;

struct _led_object {
    int status;
};

void change_led_status(led_object *, int);

#endif // __LED_H__
