#ifndef __DTO_H__
#define __DTO_H__

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

    float led;
};
data_trans_object *dto_data;

void servo_data_trans_object(int comm, int ch);
void dc_motor_data_trans_object(int comm, int ch, int sub_order);
#endif