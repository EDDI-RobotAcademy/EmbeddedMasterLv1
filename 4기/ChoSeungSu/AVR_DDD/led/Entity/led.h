#ifndef __LED_H__
#define __LED_H__

#include "../Master.h"

#define LED_OFF 0
#define LED_ON 1

typedef struct _led_object
{
    uint8_t status  : 1 ;

} led_object ;


void blink_led(led_object * led_obj_ptr);


#endif 

