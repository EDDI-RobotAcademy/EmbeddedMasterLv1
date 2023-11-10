#include "dice_in_memory_adapter_command_table.h"
#include "dice_in_memory_adapter_command_handler.h"

#include <stdio.h>
#include "dice_in_memory_adapter_command.h"

void dice_in_memory_adapter_not_implemented (void)
{
    printf("아직 구현되지 않은 스펙입니다!\n");
}

const const dice_in_memory_adapter_call_ptr_t dice_in_memory_adapter_command_table[DICE_IN_MEMORY_ADAPTER_CALL_BUFFER_COUNT] = {
    [0 ... DICE_IN_MEMORY_ADAPTER_CALL_BUFFER] = dice_in_memory_adapter_not_implemented,
    #include "dice_in_memory_adapter_command_table_mapper.h"
};
