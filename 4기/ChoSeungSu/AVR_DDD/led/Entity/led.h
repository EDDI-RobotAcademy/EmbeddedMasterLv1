#ifndef __LED_H__
#define __LED_H__

#define LED_OFF 0
#define LED_ON 1

typedef struct _led_object
{
    char status;

} led_object ;

led_object * init_led(void);
void blink_led(led_object * led_obj_ptr);


#endif 

