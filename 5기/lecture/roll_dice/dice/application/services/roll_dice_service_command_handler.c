#include "roll_dice_service_command_handler.h"

#include "../../adapter/out/in_memory/dice_in_memory_adapter_command.h"
#include "../../adapter/out/in_memory/dice_in_memory_adapter_command_handler.h"
#include "../../adapter/out/in_memory/dice_in_memory_adapter_command_table.h"

#include <stdio.h>

void roll_dice_service_execute(void)
{
    printf("domain service - roll_dice_service_execute()\n");

    dice_in_memory_adapter_command_table[DICE_IN_MEMORY_ADAPTER_STORE]();
}
