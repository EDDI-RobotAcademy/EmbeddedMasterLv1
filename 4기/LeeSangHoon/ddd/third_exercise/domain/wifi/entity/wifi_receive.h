#ifndef __WIFI_RECEIVE_H__
#define __WIFI_RECEIVE_H__

enum wifi_protocol
{
    DC_MOTOR,
    SERVO_MOTOR,
    LED,
    PROTOCOL_END
};

typedef struct _wifi_receive_object wifi_receive_object;

struct _wifi_receive_object
{
    int service_number;
    int service_number_data;
    int dc_motor_direction;
};

wifi_receive_object wifi_receive_object_data;

void receive_wifi_data (void);
void get_random_wifi_data (void);
void print_wifi_data (void);


#endif
