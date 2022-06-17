#ifndef __HCSR04_H__
#define __HCSR04_H__

#define F_CPU   16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>

#include <util/delay.h>

#define sbi(PORTx, BITx)    (PORTx |= (1<<BITx))
#define cbi(PORTx, BITx)    (PORTx &= ~(1<<BITx))

#define TRIG    PB4
#define ECHO    PB5

double duration;
void hcsr04_init(void);
double get_distance(void);

#endif

