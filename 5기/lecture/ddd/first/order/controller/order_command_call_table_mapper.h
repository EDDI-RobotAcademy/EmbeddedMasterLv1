#ifndef __ORDER_COMMAND_CALL_TABLE_MAPPER_H__
#define __ORDER_COMMAND_CALL_TABLE_MAPPER_H__

#include "order_command.h"
#include "order_command_handler.h"

#define __ORDER_COMMAND_CALL_TABLE(number, function_prototype) [number] = function_prototype,

__ORDER_COMMAND_CALL_TABLE(ORDER_REGISTER, order_register)
__ORDER_COMMAND_CALL_TABLE(ORDER_LIST, order_list)

#endif
