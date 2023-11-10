#ifndef __ROLL_DICE_SERVICE_COMMAND_TABLE_H__
#define __ROLL_DICE_SERVICE_COMMAND_TABLE_H__

#include "roll_dice_service_command.h"

typedef void (* roll_dice_service_call_ptr_t) (void);

void roll_dice_service_not_implemented (void);

extern const roll_dice_service_call_ptr_t roll_dice_service_command_table[ROLL_DICE_SERVICE_EXECUTE_BUFFER_COUNT];

#endif