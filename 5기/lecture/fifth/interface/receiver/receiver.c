#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "receiver.h"

#include "../protocol/protocol_handler.h"
#include "../protocol/protocol_call_table.h"

void recv_command_from_outbound (void)
{
    int command;

    printf("외부에서 명령이 들어온다 가정(랜덤 생성)\n");
    srand(time(NULL));

    command = rand() % 11;
    printf("수신된 명령: %d\n", command);

    protocol_call_table[command]();
}