#ifndef __DICE_IN_MEMORY_ADAPTER_COMMAND_TABLE_MAPPER_H__
#define __DICE_IN_MEMORY_ADAPTER_COMMAND_TABLE_MAPPER_H__

#include "dice_in_memory_adapter_command.h"
#include "dice_in_memory_adapter_command_handler.h"

#define __DICE_IN_MEMORY_ADAPTER_COMMAND_TABLE(number, function_prototype) [number] = function_prototype,

__DICE_IN_MEMORY_ADAPTER_COMMAND_TABLE(DICE_IN_MEMORY_ADAPTER_STORE, store_dice_number)

#endif