#ifndef __DTO_H__
#define __DTO_H__

#define LED_THRESHOLD_INIT_START    1000
#define LED_THRESHOLD_OFF           800
#define LED_THRESHOLD_ON            1200

#define LED_STATUS_DEFAULT          0
#define LED_STATUS_ON               1
#define LED_STATUS_OFF              2
#define LED_STATUS_KEEP             3


enum wireless_communication_list{
    RF,
    WIFI,
    UART,
    BLUE_TOOTH,
    COMMUNICATION_LIST_END
};


typedef struct _data_trans_object data_trans_object;
struct _data_trans_object
{
    float servo;
    float dc_motor;
    int dc_motor_sub_order;

    int led;
    int led_status;
};
data_trans_object *dto_data;

void servo_data_trans_object(int comm, int ch);
void dc_motor_data_trans_object(int comm, int ch, int sub_order);
void led_data_trans_object(int comm, int ch);
void led_status_printf (int led_status, int ch);
#endif