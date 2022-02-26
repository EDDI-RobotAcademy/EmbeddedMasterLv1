/*
 */

#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
    //DDRB &= ~(1 << DDB5);
    DDRB = 0x08;

    // LED와 연결된 핀(풀업 설정)
    PORTB |= (1 << PORT3);

    // PCMSK0에 대한 스캔 설정
    PCICR |= (1 << PCIE0);

    // PCINT5(13번 핀)에 대한 상태가 변경됨에 따라 인터럽트 발생!
    PCMSK0 |= (1 << PCINT5);

    // 인터럽트 활성화!
    // # define sei()  __asm__ __volatile__ ("sei" ::: "memory")
    sei();

    while(1)
    ;

    return 0;
}

ISR (PCINT0_vect)
{
    PORTB ^= 0x08;
}
