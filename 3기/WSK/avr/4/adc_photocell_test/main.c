/*
 */

#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/delay.h>
#include <stdio.h>
#include "uart.h"

void adc_init (unsigned char channel)
{
    // 기준 전압 선택
    ADMUX |= 0x40;

    // 분주비
    ADCSRA |= 0x07;
    // ADC 활성화
    ADCSRA |= 0x80; // (1 << ADEN)
    // 트리거 설정 (자동 트리거)
    ADCSRA |= 0x20;

    // 변환 채널 선택
    ADMUX |= ((ADMUX & 0xE0) | channel);
    // ADC 변환 시작
    ADCSRA |= 0x40;
}

int read_adc (void)
{
    while (!(ADCSRA & 0x10))
    {
    ;
    }

    return ADC;
}

void int_to_string (int n, char *buf)
{
    sprintf(buf, "%04d", n);
    buf[4] = '\0';
}

int main(void)
{

    // Insert code

    int read;
    char buf[5];

    uart_init();
    adc_init(0);

    DDRB |= (1<<0);


    while(1)
    {
        read = (read_adc() >> 6);
        int_to_string(read, buf);
        uart_string_trans(buf);
        uart_string_trans("\n\r\0");
        if(read < 10)
        {
            PORTB |= (1 << 0);
        }
        else
            PORTB &= ~(1 << 0);
    }

    return 0;
}
