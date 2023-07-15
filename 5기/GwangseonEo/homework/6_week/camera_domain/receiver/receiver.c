#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "receiver.h"

#include "../protocol/protocol_handler.h"       // protocol 정보를 관리해야 해서 handler mapping 애야함.
#include "../protocol/protocol_call_table.h"    // protocol table도 가지고 있어야함.
#include "../protocol/camera/camera_handler.h"
#include "../protocol/camera/camera_call_table.h"

void recv_command_from_outbound (void){
    int command, camera_command;

    //printf("외부에서 명령이 들어온다 가정(랜덤 생성)\n");
    srand(time(NULL));

    //command = rand() % PROTOCOL_CALL_BUFFER_COUNT;
    command = 0;
    camera_command = rand() % CAMERA_CALL_BUFFER_COUNT;
    
    printf("수신된 명령 : %d\n", command);
    printf("수신된 카메라 기능 : %d\n", camera_command);

    protocol_call_table[command](&camera_command);
}