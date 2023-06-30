#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "receiver.h"

#include "../protocol/protocol_handler.h"
// protocol 정보를 관리해야 해서 handler mapping 애야함.
#include "../protocol/protocol_call_table.h"
// protocol table도 가지고 있어야함.

void recv_command_from_outbound (void){
    int command;

    //printf("외부에서 명령이 들어온다 가정(랜덤 생성)\n");
    printf("Only Camera Protocol\n");
    srand(time(NULL));

    //command = rand() % PROTOCOL_CALL_BUFFER_COUNT;
    command = 0;
    printf("수신된 명령 : %d\n", command);

    protocol_call_table[command]();
}