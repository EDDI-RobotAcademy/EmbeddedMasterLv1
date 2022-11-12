/*6. 6. 우리가 실제 사용하는 다양한 웹/앱은 버튼이 존재하며 이 버튼 클릭에 대한 핸들러가 존재합니다.

   C언어 관점에서 이 버튼을 언제 어떤 상황에서든 재사용할 수 있도록 프로그래밍 해봅시다.     */
#include <stdio.h>
#include <stdlib.h>

#include "device.h"

enum polymorphimsm_protocol{
        HANDLER1,
        HANDLER2,
        HANDLER3,
        HANDLER4,
        HANDLER5,
        HANDLER6,
        HANDLER7,
        HANDLER8,
        HANDLER9,
        END
};
#define POLY_CALL_BUFFER_COUNT          (END)
#define POLY_CALL_BUFFER                ((END) - (1))

// void (*) (void) -> polymorphism_call_ptr_t로 대체
typedef void (* polymorphism_call_ptr_t) (void);

void polymorphism_not_impl(void)
{
    printf("아직 구현되지 않은 스펙입니다!\n");
}

// void (*)(void) 타입
// polymorphism_call_table[] 배열명 = {func1, func2, func3} -> non c99
// [0 ... x] 몇 개 배치할지 -> c99
const polymorphism_call_ptr_t polymorphism_call_table[POLY_CALL_BUFFER_COUNT] = {
        [0 ... POLY_CALL_BUFFER] = &polymorphism_not_impl,
        #include "polymorphism_call.h"
		// [nr] = sym
		// polymorphism_call_table[0] = proc_camera
		// polymorphism_call_table[1] = proc_bldc
};

void function_handler(int command) 
{
    polymorphism_call_table[command]();
}

int main (void)
{
    int command = 0;
    while(1)
    {
        scanf("%d",&command);
        function_handler(command);
    }
    return 0;
}
