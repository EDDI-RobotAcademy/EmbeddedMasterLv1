#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "receiver.h"

#include "../protocol/protocol_handler.h"
#include "../protocol/protocol_call_table.h"

void recv_command_from_outbound (void)
{
    int command, behavior;

    printf("외부에서 카메라 제어 명령이 들어온다 가정(랜덤 생성)\n");

    command = CAMERA;
	
    srand(time(NULL));
    behavior = rand() % 4;
	
    printf("수신된 명령, 동작 지시 : %d, %d\n", command, behavior);
    
    protocol_call_table[command](&behavior);
}
