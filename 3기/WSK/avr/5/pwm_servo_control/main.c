/*
 */

#define F_CPU   16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define sbi(PORTx, BITx)        (PORTx |= (1 << BITx))
#define cbi(PORTx, BITx)        (PORTx &= ~(1 << BITx))

void fast_pwm_mode_for_servo (void)
{
        cbi(SREG, 7);

        sbi(TCCR1A, COM1A1);
        sbi(TCCR1A, COM1B1);

        sbi(TCCR1A, WGM11);
        sbi(TCCR1B, WGM12);
        sbi(TCCR1B, WGM13);

        sbi(TCCR1B, CS11);

        ICR1 = 39999;
        // 우리가 RC에서 사용하는 모든 제품군은 모두 20ms로 규격되어 있음
        // 즉 동작 주파수가 반드시 50 HZ에 맞춰야 함
        // 0부터 카운팅하니까 40000-1

        DDRB = 0x02;

        sbi(SREG, 7);
}

int main(void)
{

    // Insert code
    fast_pwm_mode_for_servo();

    while(1)
    {

        OCR1A = 1000;
        _delay_ms(1000);

        OCR1A = 3000;
        _delay_ms(1000);

        OCR1A = 5000;
        _delay_ms(1000);

        OCR1A = 3000;
        _delay_ms(1000);
    }

    return 0;
}
