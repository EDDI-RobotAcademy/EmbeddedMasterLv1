#define F_CPU       16000000UL

#include "uart.h"

//#define sbi(PORTX, BITX)        (PORTX |= (1 << BITX))
//#define cbi(PORTX, BITX)        (PORTX &= ~(1 << BITX))

#define UART_BUF                (10)

// PC 와 보드가 양방향 통신을 수행할 수 있는 상태가 됨
void uart_init (void)
{
    //sbi (UCSR0A, U2X0)
    // Double the USART Transmission Speed 모드가 설정됨
    UCSR0A |= (1 << U2X0);

    // Baud Rate = 16 MHz / 8 * (UBRRn + 1)
    // (16 * 10^6) / (8 * 208) = 9615.38461538
    // 실제 우리가 통신할 때 9600 을 적지만
    // 정확하게 9600 형태가 되지는 않는다.
    // 어느정도 오차를 포함하고 있음을 상기합시다.
    UBRR0H = 0x00;
    UBRR0L = 207;

    // Asynchronous USART 설정: 7, 6번 비트 0
    // Parity Disable: 5, 4번 비트 0
    // Stop 비트: 4번 비트 0 -> 1비트 사용함을 의미함
    // UCSZn2 비트는 UCSRnB 에 존재하는 비트이며
    // 현재는 설정되지 않았으므로 0으로 취급한다.
    // 실제 표에서 나타나는 UCSZn2 ~ 0 까지의 숫자가 011로
    // 해당 모듈을 통해 전송되는 문자가 8비트(1바이트)임을 의미합니다.
    UCSR0C |= 0x6;

    // UCSRnB 에서 4번, 3번 비트가 활성화되어
    // 송신, 수신을 모두 활성화한 상태입니다.
    UCSR0B |= (1 << RXEN0);
    UCSR0B |= (1 << TXEN0);
    //sbi(UCSR0B, RXEN0);
    //sbi(UCSR0B, TXEN0);
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
    // UCSR0A 레지스터의 5번 비트가 1인지 확인
    // 이 뜻이 새로운 데이터를 쓸 준비가 되었는지 확인하는 작업
    while (!(UCSR0A & (1 << UDRE0)))
    {
        ;
    }

    // 전송할 바이트(문자 1개)를 UDRn 레지스터에 기록하여 전송함
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
    return 0;
}

void uart_print_8bit_num (uint8_t no)
{
    char num_string[4] = "0";
    int i, index = 0;

    if (no > 0)
    {
        for (i = 0; no != 0; i++)
        {
            num_string[i] = no % 10 + '0';
            no = no / 10;
        }

        num_string[i] = '\0';
        index = i - 1;
    }

    for (i = index; i >= 0; i--)
    {
        uart_trans(num_string[i]);
    }
}
