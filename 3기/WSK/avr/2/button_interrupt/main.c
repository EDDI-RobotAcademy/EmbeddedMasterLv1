/*
 */

#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{

    // Insert code

    DDRB |= (1 << 0);

    // LED와 연결된 핀(풀업 설정)
    PORTB |= (1 << PORT0);

    // PCMSK0에 대한 스캔 설정
    PCICR |= (1 << PCIE0);

    // PCINT0에 대한 상태가 변경됨에 따라 인터럽트 발생!
    PCMSK0 |= (1 << PCINT1);

    // 인터럽트 활성화!
    sei();

    while(1)
    ;

    return 0;
}

ISR (PCINT0_vect)
{
    PORTB ^= (1 << 0);
}
