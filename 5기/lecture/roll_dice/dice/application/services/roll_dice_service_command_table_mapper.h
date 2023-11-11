#ifndef __ROLL_DICE_SERVICE_COMMAND_TABLE_MAPPER_H__
#define __ROLL_DICE_SERVICE_COMMAND_TABLE_MAPPER_H__

#include "roll_dice_service_command.h"
#include "roll_dice_service_command_handler.h"

#define __ROLL_DICE_SERVICE_COMMAND_TABLE(number, function_prototype) [number] = function_prototype,

__ROLL_DICE_SERVICE_COMMAND_TABLE(ROLL_DICE_SERVICE_EXECUTE, roll_dice_service_execute)

#endif