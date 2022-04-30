#define F_CPU   16000000UL

#include "uart.h"

#define sbi(PORTX, BITX)    (PORTX |= (1 << BITX))
#define cbi(PORTX, BITX)    (PORTX &= ~(1 << BITX))

#define UART_BUF            (10)

// PC 와 보드가 양방향 통신을 수행할 수 있는 상태가 됨
void uart_init (void)
{
    //sbi (UCSR0A, U2X0)
    UCSR0A |= (1 << U2X0);

    UBRR0H = 0x00;
    UBRR0L = 207;

    UCSR0C |= 0x6;

    UCSR0B |= (1 << RXEN0);
    UCSR0B |= (1 << TXEN0);
    //sbi (UCSR0B, RXEN0);
    //sbi (UCSR0B, TXEN0);
}

unsigned char uart_recv (void)
{
    while (!(UCSR0A & (1 << RXC0)))
    {
        ;
    }

    return UDR0;
}

void uart_trans (char data)
{
    while (!(UCSR0A & (1 << UDRE0)))
    {
        ;
    }

    UDR0 = data;
}

void uart_string_trans (char *str)
{
    while (*str != '\0')
    {
        uart_trans(*str);
        str++;
    }
}

void uart_print (char *name, long val)
{
    char debug_buf[UART_BUF] = { '\0' };

    uart_string_trans(name);
    uart_string_trans(" = ");

    itoa((val), debug_buf, UART_BUF);
    uart_string_trans(debug_buf);
    uart_string_trans("\n");
}

int usart_tx_char (char ch, FILE *fp)
{
    while (!(UCSR0A & (1 << UDRE0)));

    UDR0 = ch;

    return 0;
}

void uart_print_8bit_num (uint8_t no)
{
    char num_string[4] = "0";
    int i, index = 0;

    if(no > 0)
    {
        for (i = 0; no != 0; i++)
        {
            num_string[i] = no % 10 + '0';
            no = no / 10;
        }

        num_string[i] = '\0';
        index = i -1;

        for (i = index; i >= 0; i--)
        {
            uart_trans(num_string[i]);
        }
    }
}

