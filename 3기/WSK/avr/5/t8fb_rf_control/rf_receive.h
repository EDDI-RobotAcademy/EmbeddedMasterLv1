#ifndef __RF_RECV_H__
#define __RF_RECV_H__

#include <stdint.h>

#define COUNT_s     0.000005

typedef struct receiver_
{
    uint16_t ch1;
    uint16_t ch2;
    uint16_t ch3;
    uint16_t ch4;
    uint16_t ch5;
    uint16_t ch6;
    uint16_t ch7;
    uint16_t ch8;

    uint16_t remainder_value;
}
receiver;

void rf_recv_init (void);

#endif // __RF_RECV_H__
