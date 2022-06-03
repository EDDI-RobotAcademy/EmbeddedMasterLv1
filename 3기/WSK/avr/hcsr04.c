//#include <util/delay.h>
#include "hcsr04.h"

void hcsr04_init(void)
{
    cbi(SREG, 7);
    sbi(DDRB, TRIG);    //trig 핀 출력설정
    cbi(DDRB, ECHO);   //echo 핀 입력설정
    //The pin change interrupt PCI0 will trigger if any enabled PCINT7..0 pin toggles.
    //PB5는 PCINT5이므로 PIC0를 트리거한다.
    //PCINT와 INT의 차이는 PCINT는 edge trigger 설정이 불가하지만 INT는 EICRA레지스터에서 어느 edge를 trigger로 할 것인지 설정할 수 있다.
    //또 PCINT는 여러 핀이 하나의 인터럽트 벡터에 묶여있어 인터럽트가 발생할때 어느 핀에서 인터럽트가 발생한 것인지 ISR에서 구분해줘야하지만
    //INT는 하나의 핀이 하나의 인터럽트 벡터에 묶여있어 구분해줄 필요가 없다.
    sbi(PCICR, PCIE0); //Pin Change Interrupt Enable
    sbi(PCMSK0, PCINT5);    //PCINT5에 해당하는 핀만 인터럽트 허용

    //타이머 설정(Timer0)
    //Normal mode : 단순히 카운터가 증가하고 오버플로우되기를 반복한다. upcounter로 동작한다. 오버플로우되면 TOV 플래그가 set된다.
    //Timer interrupt를 enable해서 ISR 루틴을 돌면 TOV가 자동으로 flag가 클리어 되지만 인터럽트를 이용하지 않으면 유저가 직접 클리어해야 한다.
    //TOV flag를 클리어하지 않고 9번쨰 비트로 이용할 수도 있다
    cbi(TCCR0B, WGM02);
    cbi(TCCR0A, WGM01);
    cbi(TCCR0A, WGM00);

    cbi(TCCR0B, CS02 | CS01 | CS00);    //Timer stop

    cbi(TIMSK0, TOIE0); //Timer Overflow Interrupt disable

    sbi(SREG, 7);
}

double get_distance(void)
{
    PORTB |= (1 << TRIG);

    _delay_us(10);
    PORTB |= (1 << TRIG);


}

