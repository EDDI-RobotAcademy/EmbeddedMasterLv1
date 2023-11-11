#include "roll_dice_service_command_table.h"
#include "roll_dice_service_command_handler.h"

#include <stdio.h>
#include "roll_dice_service_command.h"

void roll_dice_service_not_implemented (void)
{
    printf("아직 구현되지 않은 스펙입니다!\n");
}

const const roll_dice_service_call_ptr_t roll_dice_service_command_table[ROLL_DICE_SERVICE_EXECUTE_BUFFER_COUNT] = {
    [0 ... ROLL_DICE_SERVICE_EXECUTE_BUFFER] = roll_dice_service_not_implemented,
    #include "roll_dice_service_command_table_mapper.h"
};
