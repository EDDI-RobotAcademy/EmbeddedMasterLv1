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



#include "main.h"
#include "device.h"


enum polymorphism_protocol {
    BLDC,
    SERVO,
    LED,
    END
};
enum RF_CH{
    START,
    BLDC_RF_CH,
    SERVO_RF_CH,
    LED_RF_CH
};

#define POLY_CALL_BUFFER_COUNT          (END)
#define POLY_CALL_BUFFER                ((END) - (1))

// void (*) (void) -> polymorphism_call_ptr_t로 대체
typedef void* (* polymorphism_call_ptr_t) (void*);

void* polymorphism_not_impl(void)
{
    printf("아직 구현되지 않은 스펙입니다!\n");
}

// void (*)(void) 타입
// polymorphism_call_table[] 배열명 = {func1, func2, func3} -> non c99
// [0 ... x] 몇 개 배치할지 -> c99
const polymorphism_call_ptr_t polymorphism_call_table[POLY_CALL_BUFFER_COUNT] = {
        [0 ... POLY_CALL_BUFFER] = &polymorphism_not_impl,
        #include "polymorphism_call.h"
		// [nr] = sym
		// polymorphism_call_table[0] = proc_bldc
		// polymorphism_call_table[1] = proc_servo
        // polymorphism_call_table[2] = proc_led
};

uint8_t rf_receive_data_checksum(rf_receive_handler *rf_r_handler)
{
    uint8_t checksum = 0xFF;
    int data_length_start = 1;
    int data_leng_end = 5;
    for(data_length_start; data_length_start < data_leng_end; data_length_start++)
    {
        checksum += rf_r_handler->rf_rev_info->new_rxd[data_length_start++];
    }
    return ~checksum;
}
bool check_receive_data(rf_receive_handler *rf_r_handler)
{
    uint8_t checksum = 0;
    checksum = rf_receive_data_checksum(rf_r_handler);
    //printf("rx checksum : %02x\n",checksum);
    if(rf_r_handler->rf_rev_info->new_rxd[0] != 0x02)
    {
        memset(rf_r_handler->rf_rev_info->new_rxd, 0, sizeof(uint8_t) * RF_PROTOCOL_LENGTH);
        printf("stx error\n");
        return false;
        
    }
    if(rf_r_handler->rf_rev_info->new_rxd[5] != checksum)
    {
        
        memset(rf_r_handler->rf_rev_info->new_rxd, 0, sizeof(uint8_t) * RF_PROTOCOL_LENGTH);
        printf("checksum error\n");
        return false;
    }
    if(rf_r_handler->rf_rev_info->new_rxd[6] != 0x03)
    {
        memset(rf_r_handler->rf_rev_info->new_rxd, 0, sizeof(uint8_t) * RF_PROTOCOL_LENGTH);
        printf("etx error\n");
        return false;
    }
    else 
    {
        memcpy(rf_r_handler->rf_rev_info->current_rxd, rf_r_handler->rf_rev_info->new_rxd, sizeof(uint8_t) * RF_PROTOCOL_LENGTH);
        return true;
    }
}
void rf_receive_data(rf_receive_handler *rf_r_handler, rf_transmit_handler *rf_t_handler)
{
    int i = 0;
    if(rf_r_handler->rf_rev_info->new_rxd[0] != '0')
    {
        memcpy(rf_r_handler->rf_rev_info->new_rxd, rf_t_handler->trm_info->txd, sizeof(rf_t_handler->trm_info->txd));
    }
    /*
    printf("RX : ");
    for(i; i < RF_PROTOCOL_LENGTH; i++)
    {
        //printf("[%d] :%02x\n", i, rf_t_handler->trm_info->txd[i]);
        printf("%02x ", rf_t_handler->trm_info->txd[i]);
    }
    printf("\n");
    */
}   
void rf_receive_data_trans_convert_object(rf_receive_handler *rf_r_handler)
{
    uint16_t servo_data = 0;
    uint16_t bldc_data = 0;
    uint16_t led_data = 0;
    switch(rf_r_handler->rf_rev_info->current_rxd[1])   //rf_ch
    {
        case BLDC_RF_CH:
            //printf("bldc rf_r_handler->rf_rev_info->current_rxd[3] : %02x\n", rf_r_handler->rf_rev_info->current_rxd[3]);
            //printf("bldc rf_r_handler->rf_rev_info->current_rxd[4] : %02x\n", rf_r_handler->rf_rev_info->current_rxd[4]);
            bldc_data = rf_r_handler->rf_rev_info->current_rxd[3] << 8;
            bldc_data |= rf_r_handler->rf_rev_info->current_rxd[4] & 0xFF;
            //printf("bldc_data :%d\n",bldc_data);
            //y = 0.3188x - 191.25
            rf_r_handler->dto->bldc_dto_data = 0.3188 * bldc_data - 191.25;
            printf("rf_ch1 : %0.2f\n", rf_r_handler->dto->bldc_dto_data);
            
            break;

        case SERVO_RF_CH:
            //printf("servo rf_r_handler->rf_rev_info->current_rxd[3] : %02x\n", rf_r_handler->rf_rev_info->current_rxd[3]);
            //printf("servo rf_r_handler->rf_rev_info->current_rxd[4] : %02x\n", rf_r_handler->rf_rev_info->current_rxd[4]);
            servo_data = rf_r_handler->rf_rev_info->current_rxd[3] << 8;
            servo_data |= rf_r_handler->rf_rev_info->current_rxd[4] & 0xFF;
            //printf("servo_data :%d\n",servo_data);
            //y= 2.5x -1000
            rf_r_handler->dto->servo_dto_data = 2.5 * servo_data - 1000;
            printf("rf_ch2 : %0.2f\n", rf_r_handler->dto->servo_dto_data);
            break;

        case LED_RF_CH:
            //printf("led rf_r_handler->rf_rev_info->current_rxd[3] : %02x\n", rf_r_handler->rf_rev_info->current_rxd[3]);
            //printf("led rf_r_handler->rf_rev_info->current_rxd[4] : %02x\n", rf_r_handler->rf_rev_info->current_rxd[4]);
            led_data = rf_r_handler->rf_rev_info->current_rxd[3] << 8;
            led_data |= rf_r_handler->rf_rev_info->current_rxd[4] & 0xFF;
            //printf("led_data :%d\n",led_data);
            //y = 0.0013x - 0.75
            rf_r_handler->dto->led_dto_data = 0.0013 *led_data - 0.75;
            printf("rf_ch3 : %0.2f\n", rf_r_handler->dto->led_dto_data);
            break;    

        default:
            break;

    }
}

rf_receive_handler *allocate_rf_r_handler()
{
    rf_receive_handler *rf_r_handler;
    rf_receive_method_table *tbl;
    data_trans_value *dto;
    rf_r_handler = (rf_receive_handler*)malloc(sizeof(rf_receive_handler));
    if(rf_r_handler == NULL)
    {
        printf("rf_r_handler 동적 할당 실패\n");
        exit(-1);
    }

    tbl = (rf_receive_method_table*)malloc(sizeof(rf_receive_method_table));
    tbl->rf_receive_data = rf_receive_data;
    tbl->check_receive_data = check_receive_data;
    tbl->rf_receive_data_checksum = rf_receive_data_checksum;
    tbl->rf_receive_data_trans_convert_object = rf_receive_data_trans_convert_object;
    rf_r_handler->tbl = tbl;
    if(rf_r_handler->tbl == NULL)
    {
        printf("rf_receive_method_table 동적 할당 실패\n");
        exit(-1);
    }

    dto = (data_trans_value*)malloc(sizeof(data_trans_value));
    rf_r_handler->dto = (data_trans_value*)malloc(sizeof(data_trans_value));
    rf_r_handler->dto = dto;
    if(rf_r_handler->dto == NULL)
    {
        printf("rf_r_handler->dto 동적 할당 실패\n");
        exit(-1);
    }
    
    rf_r_handler->rf_rev_info = (rf_receive_info*)malloc(sizeof(rf_receive_info));
    return rf_r_handler;
}

uint16_t random_data_generator(rf_transmit_handler *rf_t_handler, int device_type)
{
    uint16_t led_data, bldc_data, servo_data;
    uint8_t led_datah = 0, led_datal = 0;
    uint8_t servo_datah = 0, servo_datal = 0;
    uint8_t bldc_datah = 0, bldc_datal = 0;
    if(device_type == BLDC)
    return bldc_data = rand() % (RANDOM_DATA_MAX - RANDOM_DATA_MIN + 1) + RANDOM_DATA_MIN;
    else if(device_type == SERVO)
    return servo_data = rand() % (RANDOM_DATA_MAX - RANDOM_DATA_MIN + 1) + RANDOM_DATA_MIN;
    else if(device_type == LED)
    return led_data = rand() % (RANDOM_DATA_MAX - RANDOM_DATA_MIN + 1) + RANDOM_DATA_MIN;
    
    /*
    bldc_datah = (bldc_data & 0xFF00) >> 8;
    bldc_datal = (bldc_data & 0x00FF);
    servo_datah = (servo_data & 0xFF00) >> 8;
    servo_datal = (servo_data & 0x00FF);
    led_datah = (led_data & 0xFF00) >> 8;
    led_datal = (led_data & 0x00FF);
    */
    //printf("bldc_data : %d, servo_data : %d ,led_data : %d\n", bldc_data, servo_data, led_data);


}
uint8_t rf_transmit_data_checksum(rf_transmit_handler *rf_t_handler)
{
    uint8_t checksum = 0xFF;
    int data_length_start = 1;
    int data_leng_end = 5;
    for(data_length_start; data_length_start < data_leng_end; data_length_start++)
    {
        checksum += rf_t_handler->trm_info->txd[data_length_start++];
    }
    
    return ~checksum;
}
void rf_transmit_data_make(rf_transmit_handler *rf_t_handler)
{
    uint16_t bldc_data;
    uint16_t servo_data;
    uint16_t led_data;
    static int i = 1;
    int j = 0;
    uint8_t checksum;

        rf_t_handler->trm_info->rf_ch = i;
        //printf("rf_t_handler->trm_info->rf_ch : %d\n", rf_t_handler->trm_info->rf_ch);
        rf_t_handler->trm_info->txd[0] = 0x02;  //STX
        switch(rf_t_handler->trm_info->rf_ch)
        {
            case BLDC_RF_CH:

                    rf_t_handler->trm_info->txd[1] = 0x01;  //RF_CH
                    rf_t_handler->trm_info->txd[2] = 0x07;  //LENGTH
                    bldc_data = rf_t_handler->tbl->random_data_generator(rf_t_handler, BLDC);
                    rf_t_handler->trm_info->txd[3] = (bldc_data & 0xFF00) >> 8;     //msb
                    rf_t_handler->trm_info->txd[4] = (bldc_data & 0x00FF);          //lsb
                break;

            case SERVO_RF_CH:

                    rf_t_handler->trm_info->txd[1] = 0x02;  //RF_CH
                    rf_t_handler->trm_info->txd[2] = 0x07;  //LENGTH
                    servo_data = rf_t_handler->tbl->random_data_generator(rf_t_handler, SERVO);
                    rf_t_handler->trm_info->txd[3] = (servo_data & 0xFF00) >> 8;    //msb
                    rf_t_handler->trm_info->txd[4] = (servo_data & 0x00FF);         //lsb
                break;

            case LED_RF_CH:

                    rf_t_handler->trm_info->txd[1] = 0x03;  //RF_CH
                    rf_t_handler->trm_info->txd[2] = 0x07;  //LENGTH
                    led_data = rf_t_handler->tbl->random_data_generator(rf_t_handler, LED);
                    rf_t_handler->trm_info->txd[3] = (led_data & 0xFF00) >> 8;  //msb
                    rf_t_handler->trm_info->txd[4] = (led_data & 0x00FF);       //lsb
                break;

            defualt:
                break;
        }
        checksum = rf_t_handler->tbl->rf_transmit_data_checksum(rf_t_handler);
        //printf("tx checksum : %02x\n",checksum);
        rf_t_handler->trm_info->txd[5] = rf_t_handler->tbl->rf_transmit_data_checksum(rf_t_handler);
        rf_t_handler->trm_info->txd[6] = 0x03;  //ETX
        
        //디버깅용
        /*
        printf("TX : ");
        for(j; j < 7; j++)
        {
            printf("%02x ", rf_t_handler->trm_info->txd[j]);
            //printf("rf_t_handler->trm_info->txd[%d] %02X\n",j ,rf_t_handler->trm_info->txd[j]);
        }
        j = 0;
        printf("\n");
        */
    if(i++ == 3) i = 1;
    


}
void rf_transmit_data_send (rf_transmit_handler *rf_t_handler, rf_receive_handler *rf_r_handler)
{
    memcpy(rf_r_handler->rf_rev_info->new_rxd, rf_t_handler, sizeof(rf_t_handler->trm_info->txd));
}

rf_transmit_handler *allocate_rf_t_handler()
{
    rf_transmit_handler *rf_t_handler;
    rf_transmit_method_table *tbl;
    rf_t_handler = (rf_transmit_handler*)malloc(sizeof(rf_transmit_handler));
    if(rf_t_handler == NULL)
    {
        printf("rf_t_handler 동적 할당 실패\n");
        exit(-1);
    }
    tbl = (rf_transmit_method_table*)malloc(sizeof(rf_transmit_method_table));
    tbl->random_data_generator = random_data_generator;
    tbl->rf_transmit_data_make = rf_transmit_data_make;
    tbl->rf_transmit_data_send = rf_transmit_data_send;
    tbl->rf_transmit_data_checksum = rf_transmit_data_checksum;
    
    rf_t_handler->tbl = tbl;
    if(rf_t_handler->tbl == NULL)
    {
        printf("rf_transmit_method_table 동적할당 실패\n");
        exit(-1);
    }
    rf_t_handler->trm_info = (rf_transmit_info*)malloc(sizeof(rf_transmit_info));
    if(rf_t_handler->tbl == NULL)
    {
        printf("rf_transmit_info 동적할당 실패\n");
        exit(-1);
    }

    return rf_t_handler;
}
int main (void)
{
    srand(time(NULL));// data 임의의 값 생성.
    rf_receive_handler *rf_r_handler_ch1;
    rf_receive_handler *rf_r_handler_ch2;
    rf_receive_handler *rf_r_handler_ch3;
    rf_transmit_handler *rf_t_handler_ch1;
    rf_transmit_handler *rf_t_handler_ch2;
    rf_transmit_handler *rf_t_handler_ch3;
    
    int device_type = 0;
    rf_r_handler_ch1 = allocate_rf_r_handler();
    rf_r_handler_ch2 = allocate_rf_r_handler();
    rf_r_handler_ch3 = allocate_rf_r_handler();
    rf_t_handler_ch1 = allocate_rf_t_handler();
    rf_t_handler_ch2 = allocate_rf_t_handler();
    rf_t_handler_ch3 = allocate_rf_t_handler();


    while(1)
    {
        rf_t_handler_ch1->trm_info->bldc_data = rf_t_handler_ch1->tbl->random_data_generator(rf_t_handler_ch1, BLDC);
        rf_t_handler_ch1->trm_info->txd[3] = (rf_t_handler_ch1->trm_info->bldc_data & 0xFF00) >> 8;
        rf_t_handler_ch1->trm_info->txd[4] = (rf_t_handler_ch1->trm_info->bldc_data & 0x00FF);
        rf_t_handler_ch1->tbl->rf_transmit_data_make(rf_t_handler_ch1);
        rf_t_handler_ch1->tbl->rf_transmit_data_send(rf_t_handler_ch1, rf_r_handler_ch1);
        rf_r_handler_ch1->tbl->rf_receive_data(rf_r_handler_ch1, rf_t_handler_ch1);
        if(rf_r_handler_ch1->tbl->check_receive_data(rf_r_handler_ch1))
        {
            rf_r_handler_ch1->tbl->rf_receive_data_trans_convert_object(rf_r_handler_ch1);
        }
        else
        {
            printf("rf_ch1_데이터 이상\n");
        }

        rf_t_handler_ch2->trm_info->servo_data = rf_t_handler_ch2->tbl->random_data_generator(rf_t_handler_ch2, SERVO);
        rf_t_handler_ch2->trm_info->txd[3] = (rf_t_handler_ch2->trm_info->servo_data & 0xFF00) >> 8;
        rf_t_handler_ch2->trm_info->txd[4] = (rf_t_handler_ch2->trm_info->servo_data & 0x00FF);
        rf_t_handler_ch2->tbl->rf_transmit_data_make(rf_t_handler_ch2);
        rf_t_handler_ch2->tbl->rf_transmit_data_send(rf_t_handler_ch2, rf_r_handler_ch2);
        rf_r_handler_ch2->tbl->rf_receive_data(rf_r_handler_ch2, rf_t_handler_ch2);
        if(rf_r_handler_ch2->tbl->check_receive_data(rf_r_handler_ch2))
        {
            rf_r_handler_ch2->tbl->rf_receive_data_trans_convert_object(rf_r_handler_ch2);
        }
        else
        {
            printf("rf_ch2_데이터 이상\n");
        }

        rf_t_handler_ch3->trm_info->led_data = rf_t_handler_ch3->tbl->random_data_generator(rf_t_handler_ch3, LED);
        rf_t_handler_ch3->trm_info->txd[3] = (rf_t_handler_ch3->trm_info->led_data & 0xFF00) >> 8;
        rf_t_handler_ch3->trm_info->txd[4] = (rf_t_handler_ch3->trm_info->led_data & 0x00FF);
        rf_t_handler_ch3->tbl->rf_transmit_data_make(rf_t_handler_ch3);
        rf_t_handler_ch3->tbl->rf_transmit_data_send(rf_t_handler_ch3, rf_r_handler_ch3);
        rf_r_handler_ch3->tbl->rf_receive_data(rf_r_handler_ch3, rf_t_handler_ch3);
        if(rf_r_handler_ch3->tbl->check_receive_data(rf_r_handler_ch3))
        {
            rf_r_handler_ch3->tbl->rf_receive_data_trans_convert_object(rf_r_handler_ch3);
        }
        else
        {
            printf("rf_ch3_데이터 이상\n");
        }

        polymorphism_call_table[BLDC](rf_r_handler_ch1);   //bldc
        polymorphism_call_table[SERVO](rf_r_handler_ch2);   //servo
        polymorphism_call_table[LED](rf_r_handler_ch3);   //led
    }

    return 0;
}