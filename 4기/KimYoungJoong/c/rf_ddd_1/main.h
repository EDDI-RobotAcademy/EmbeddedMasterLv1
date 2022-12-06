/*
1. RF 송수신기가 존재한다.

2. 송신기가 날리는 정보는 600 ~ 1400이라는 숫자값을 가지고 수신됩니다.

3. 수신기에는 총 8개의 채널이 존재합니다.

4. 실제로는 조종기측에서 무언가를 제어할 때 위의 수치값들이 바뀌지만

   이 부분은 고려하지 않고 랜덤 값으로 처리하겠습니다.

5. 각 채널들은 LED를 제어하기 위한 용도로 활용될 수도 있으며

   서보 모터나 DC 모터를 제어하는데 활용할 수도 있습니다.

6. 서보 모터는 500 ~ 2500의 범주를 가지고 있습니다.

7. DC 모터는 0 ~ 255의 범주를 가지고 있습니다.

8. 수신기가 각 채널별로 수신한 정보를 바탕으로 LED, 서보, DC 모터를 제어할 수 있도록

*/
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define RANDOM_DATA_MIN 600
#define RANDOM_DATA_MAX 1400

#define BLDC_DATA_MIN   0
#define BLDC_DATA_MAX   255

#define SERVO_DATA_MIN  500
#define SERVO_DATA_MAX  2500

#define LED_OFF_DATA    0
#define LED_ON_DATA     1

#define RF_PROTOCOL_LENGTH  7
#define RF_PROTOCOL_DATA_LENGTH 4
#define RX_DATA_LENGTH  7
#define TX_DATA_LENGTH  7


/*
[0]STX          0x02
[1]RF_CH         0x01    (binary)
[2]lENGTH        0x01    (binary)
[3]SERVO_DATA_H  0xFF
[4]SERVO_DATA_L  0xFF
    500 ~ 2500

[5]CHECKSUM      0XFF
    RF_CH~ ~ DATA
    [3] ~ [6]

[6]ETX       0x03
*/

typedef struct _rf_receive_info rf_receive_info;
typedef struct _rf_receive_method_table rf_receive_method_table;
typedef struct _rf_receive_handler rf_receive_handler;
typedef struct _data_trans_value data_trans_value;

typedef struct _rf_transmit_info rf_transmit_info;
typedef struct _rf_transmit_method_table rf_transmit_method_table;
typedef struct _rf_transmit_handler rf_transmit_handler;

struct _rf_receive_info
{
    uint8_t new_rxd[RX_DATA_LENGTH];
    uint8_t current_rxd[RX_DATA_LENGTH];
    uint8_t rxd_flag;
};

struct _data_trans_value
{
    float bldc_dto_data;      //0 ~ 255
    float servo_dto_data;    //500 ~ 2500
    float led_dto_data;          //0 ~ 1
};

struct _rf_receive_method_table
{
    void ( *rf_receive_data)(rf_receive_handler *rf_r_handler, rf_transmit_handler *rf_t_handler);
    bool ( *check_receive_data)(rf_receive_handler *rf_r_handler);
    void ( *rf_receive_data_trans_convert_object)(rf_receive_handler *rf_r_handler);
    uint8_t (*rf_receive_data_checksum)(rf_receive_handler *rf_r_handler);
};

struct _rf_receive_handler
{
    data_trans_value *dto;
    rf_receive_method_table *tbl;
    rf_receive_info *rf_rev_info;
};




struct _rf_transmit_info
{
    int rf_ch;
    uint8_t txd[TX_DATA_LENGTH];
    uint16_t bldc_data;
    uint16_t servo_data;
    uint16_t led_data;
};

struct _rf_transmit_method_table
{
    uint16_t ( *random_data_generator)(rf_transmit_handler *rf_t_handler, int device_type);
    void( *rf_transmit_data_make)(rf_transmit_handler *rf_t_handler);
    uint8_t (*rf_transmit_data_checksum)(rf_transmit_handler *rf_t_handler);
    void( *rf_transmit_data_send)(rf_transmit_handler *rf_t_handler, rf_receive_handler *rf_r_handler);
};

struct _rf_transmit_handler
{
    rf_transmit_method_table *tbl;
    rf_transmit_info *trm_info;
};