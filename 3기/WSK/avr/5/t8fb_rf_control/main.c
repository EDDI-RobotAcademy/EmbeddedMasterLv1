/*
 */

#include "common.h"
#include "rf_receive.h"
#include "uart.h"

receiver channel;

uint16_t duty;
uint16_t t1, t2;

uint8_t rising_cnt = 0;
uint8_t falling_cnt = 0;

void rf_ppm_timer_set (void)
{
    cbi(SREG, 7);

    sbi(TCCR1A, COM1A1);
    sbi(TCCR1A, COM1B1);

    sbi(TCCR1A, WGM11);
    sbi(TCCR1B, WGM12);
    sbi(TCCR1B, WGM13);

    sbi(TCCR1B, CS11);

    ICR1 = 39999;

    sbi(SREG, 7);
}
int main(void)
{
    FILE *fp = fdevopen(usart_tx_char, NULL);

    uart_init();
    printf("UART Init Success!\n\r\0");

    rf_ppm_timer_set();
    printf("RF PPM Timer Init Success!\n\r\0");

    rf_recv_init();
    printf("RF Receiver Init Success!\n\r\0");


    while(1)
    {
        printf("ch1: %d, ch2: %d, ch3: %d. ch4: %d,\
         ch5: %d, ch6: %d, ch7: %d, ch8: %d\n\r\0",
         channel.ch1, channel.ch2, channel.ch3, channel.ch4,
         channel.ch5, channel.ch6, channel.ch7, channel.ch8);

         _delay_ms(700);
    }

    return 0;
}

ISR (INT0_vect)
{
    // Rising Edge면
    if (EICRA == 0x03)
    {
        t1 = TCNT1;

        // Falling Edge
        EICRA = 0x02;
        sbi(EIFR, INTF0);

        rising_cnt++;
    }
    else
    {
        t2 = TCNT1;

        falling_cnt++;

        // 시간 계산 (us)
        if(t1 > t2)
        {
            duty = 39999 - t1 + t2;
        }
        else
        {
            duty = t2 - t1;
        }

        duty = duty / 2;

        // Rising Edge
        EICRA = 0x03;
        sbi(EIFR, INTF0);

    }

    if (duty > 4000)
    {
        rising_cnt = 0;
        falling_cnt = 0;
    }

    switch (rising_cnt + falling_cnt)
    {
        case 2:
            channel.ch1 = duty;
            break;
        case 4:
            channel.ch2 = duty;
            break;
        case 6:
            channel.ch3 = duty;
            break;
        case 8:
            channel.ch4 = duty;
            break;
        case 10:
            channel.ch5 = duty;
            break;
        case 12:
            channel.ch6 = duty;
            break;
        case 14:
            channel.ch7 = duty;
            break;
        case 16:
            channel.ch8 = duty;
            break;
        case 18:
            channel.remainder_value = duty;
            falling_cnt = 0;
            rising_cnt = 0;
            break;

    }

}
