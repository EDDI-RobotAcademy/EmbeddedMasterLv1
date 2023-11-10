#ifndef __DICE_IN_MEMORY_ADAPTER_COMMAND_TABLE_H__
#define __DICE_IN_MEMORY_ADAPTER_COMMAND_TABLE_H__

#include "dice_in_memory_adapter_command.h"

typedef void (* dice_in_memory_adapter_call_ptr_t) (void);

void dice_in_memory_adapter_not_implemented (void);

extern const dice_in_memory_adapter_call_ptr_t dice_in_memory_adapter_command_table[DICE_IN_MEMORY_ADAPTER_CALL_BUFFER_COUNT];

#endif