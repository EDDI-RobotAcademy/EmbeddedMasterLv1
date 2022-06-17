/*
 */

#include <avr/io.h>
#include "hcsr04.h"

int main(void)
{

    // Insert code
    hcsr04_init();

    while(1)
    ;

    return 0;
}

ISR(PCINT0_vect)
{
    sbi(PCIFR, PCIF0);  //PCINT0 flag clear
    sbi(TIFR0, TOV0);    //Timer0 Overflow flag clear
    if((PORTB & ECHO) == 1)
    {
        //Clock select : 16MHz / 8 = 2MHz Timer start
        TCNT0 = 0;
        cbi(TCCR0B, CS02);
        sbi(TCCR0B, CS01);
        cbi(TCCR0B, CS00);
    }
    else if((PORTB & ECHO) == 0)
    {
        duration = TCNT0 * 0.5; //duration은 ECHO핀에서 HIGH가 유지된 시간 (us)
        cbi(TCCR0B, CS02 | CS01 | CS00);    //Timer stop
    }
}
