#include "rf_receive.h"
#include "common.h"

void rf_recv_init (void)
{
    cbi(SREG, 7);

    // INT0 Rising Edge ON
    EICRA = 0x03;
    // INT0 Enable
    EIMSK = 0x01;
    sbi(EIFR, INTF0);

    // INT0 핀 입력 (PD2)
    cbi(DDRD, 2);

    // pull up 설정
    sbi(PORTD, 2);

    sbi(SREG, 7);
}
