#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "device.h"

enum polymorphism_protocol {
    CAMERA,
    DCMOTOR,
    BLDC,
    PMSM,
    ACIM,
    LED,
    I2C,
    SPI,
    CAN,
    ECAP,
    END
};

#define POLY_CALL_BUFFER_COUNT  (END)
#define POLY_CALL_BUFFER        ((END) - (1))

// void (*) (void) 대신 polymorphism_call_ptr_t를 사용하겠다
typedef void (* polymorphism_call_ptr_t)(void);

void polymorphism_not_impl(void)
{
    printf("아직 구현되지 않은 스펙입니다!\n");
}

// 타입: void (*) void
// 배열 이름: polymorphism_call_table
// [0 ... x] 인덱스 0 ~ x 요소를 초기화하겠다 <- c99
// {func1, func2, func3} <- non c99
const polymorphism_call_ptr_t polymorphism_call_table[POLY_CALL_BUFFER_COUNT] = {
    [0 ... POLY_CALL_BUFFER] = polymorphism_not_impl,
    #include "polymorphism_call.h"
    // [nr] = sym
    // polymorphism_call_ptr_t[0] = proc_camera
    // polymorphism_call_ptr_t[1] = proc_bldc
};

void recv_command_from_pc(void)
{
    int command;

    printf("명령이 들어온다 가정하고 진행(랜덤으로 만들기)!\n");

    command = rand() % POLY_CALL_BUFFER_COUNT;
    printf("수신된 명령: %d(가정 - 랜덤)\n", command);

    polymorphism_call_table[command]();
}

int main(void)
{
    srand(time(NULL));

    recv_command_from_pc();

    return 0;
}
