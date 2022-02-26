/*
 */
#define F_CPU           16000000UL

#include <avr/io.h>
#include <avr/delay.h>

#include "uart.h"

int main(void)
{

    // 필요한 사항
    // 1. UART          O
    // 2. SPI

    uart_init();

    while(1)
    {
        uart_string_trans("Hello AVR: EDDI Robot Academy\n\r\0");
        _delay_ms(500);
    }

    return 0;
}
