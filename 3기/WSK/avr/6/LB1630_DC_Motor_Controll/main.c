/*
 */

#include <avr/io.h>
#include <avr/interrupt.h>

#define F_CPU       16000000UL
#include <avr/delay.h>

#define IN1     PD0

#include <math.h>

void init_dc_motor(void)
{
    DDRB = 0xFF;
    DDRD = 0xFF;        //-> 어떤 핀을 출력 설정으로 하는건지 명시성이 떨어지지만 핀이 input 상태일때 floating (입력쪽은 그라운드로 안빠져 있으면 floating상태가 된다.)
                        //상태이면 전압이 튀고 있으므로 누설 전류가 발생해 소비 전력 측면에서 좋지 않다. 그래서 전부 출력설정하면 사용하지 않는 핀은 LOW 상태가 돼 소비 전력 측면에서 좋다.
    //Fast PWM mode set
    TCCR2A |= (1 << WGM21) | (1 << WGM20);
    TCCR2B |= (1 << WGM22);

    TCCR2A |= (1 << COM2A1) | (1 << COM2B1);

    //select timer clock source
    TCCR2B |= (1 << CS22);  //clkT2S / 64   = 16MHz / 64 = 250KHz
}

int main(void)
{

    // Insert code
    int count = 0;
    double speed, t;
    unsigned char velocity;

    init_dc_motor();

    DDRB &= ~(1 << DDB5);

    PORTB |= (1 << PORTB4);
    PCICR |= (1 << PCIE0);
    PCMSK0 |= (1 << PCINT5);    //PB5핀 인터럽트 설정

    sei();

    while(1)
    {
        t = (double)count / 180.0 * 3.14192;
        speed = 255 * sin(t);
        velocity = (unsigned int)fabs(speed);

        if(speed >= 0)
        {
            PORTD |= 0x08;
            PORTB &= ~0x08;
            OCR2A = 0;
            OCR2B = 255 - velocity;


        }

        else
        {
            PORTD &= ~0x08;
            PORTB |= 0x08;
            OCR2A = velocity;
            OCR2B = 0;
        }

        count++;
        _delay_ms(20);
    }

    return 0;
}

ISR (PCINT0_vect)
{
    PORTB ^= 0x10;  //PB4 핀 출력 토글
}
