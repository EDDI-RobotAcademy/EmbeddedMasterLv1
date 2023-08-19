#ifndef __PRODUCT_COMMAND_CALL_TABLE_MAPPER_H__
#define __PRODUCT_COMMAND_CALL_TABLE_MAPPER_H__

#include "product_command.h"
#include "product_command_handler.h"

#define __PRODUCT_COMMAND_CALL_TABLE(number, function_prototype) [number] = function_prototype,

__PRODUCT_COMMAND_CALL_TABLE(PRODUCT_LIST, product_list)

#endif
