#ifndef __DICE_CONTROLLER_COMMAND_TABLE_H__
#define __DICE_CONTROLLER_COMMAND_TABLE_H__

#include "dice_controller_command.h"

typedef void (* dice_call_ptr_t) (void);

void dice_protocol_not_implemented (void);

extern const dice_call_ptr_t dice_controller_table[DICE_CALL_BUFFER_COUNT];

#endif