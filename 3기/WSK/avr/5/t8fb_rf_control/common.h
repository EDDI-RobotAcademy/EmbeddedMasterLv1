#ifndef  __COMMON_H__
#define __COMMON_H__

#define F_CPU       16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <util/delay.h>

#define s_to_us     1000000
#define us_to_s     0.000001F

#define sbi(PORTx, BITx)        (PORTx |= (1 << BITx))
#define cbi(PORTx, BITx)        (PORTx &= ~(1 << BITx))

#endif // __COMMON_H__
