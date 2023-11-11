#include "dice_controller_command_table.h"
#include "dice_controller_command_handler.h"

#include <stdio.h>
#include "dice_controller_command.h"

void dice_protocol_not_implemented (void)
{
    printf("아직 구현되지 않은 스펙입니다!\n");
}

const dice_call_ptr_t dice_controller_table[DICE_CALL_BUFFER_COUNT] = {
    [0 ... DICE_CALL_BUFFER] = dice_protocol_not_implemented,
    #include "dice_controller_command_table_mapper.h"
};
