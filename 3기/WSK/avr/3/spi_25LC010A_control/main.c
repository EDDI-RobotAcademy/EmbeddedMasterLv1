/*
 */
#define F_CPU       16000000UL

#include <avr/io.h>
#include <avr/delay.h>

#include "uart.h"
#include "spi_25LC010A.h"

int main(void)
{

    // 필요한 사항
    // 1. UART
    // 2. SPI
    uint8_t i;

    spi_init();

    uart_init();

    for (i = 0; i < 128; i++)
    {
        eeprom_write_byte(i, i);
    }

    for (i = 0; i < 128; i++)
    {
        uart_print_8bit_num(eeprom_read_byte(i));
        //uart_trans('\r');
        uart_string_trans("\n\r\0");
    }

    while(1)
    {
        //uart_string_trans("Hello AVR: EDDI Robot Academy\n\r\0");
        //_delay_ms(500);
    }

    return 0;
}
