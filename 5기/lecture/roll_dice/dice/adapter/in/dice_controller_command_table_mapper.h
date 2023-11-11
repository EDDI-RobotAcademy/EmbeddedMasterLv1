#ifndef __DICE_CONTROLLER_COMMAND_TABLE_MAPPER_H__
#define __DICE_CONTROLLER_COMMAND_TABLE_MAPPER_H__

#include "dice_controller_command.h"
#include "dice_controller_command_handler.h"

#define __DICE_CONTROLLER_COMMAND_TABLE(number, function_prototype) [number] = function_prototype,

__DICE_CONTROLLER_COMMAND_TABLE(DICE_ROLL, roll_dice)

#endif