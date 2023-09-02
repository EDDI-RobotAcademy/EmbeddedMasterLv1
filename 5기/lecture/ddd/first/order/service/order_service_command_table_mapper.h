#ifndef __ORDER_SERVICE_COMMAND_TABLE_MAPPER_H__
#define __ORDER_SERVICE_COMMAND_TABLE_MAPPER_H__

#include "order_service_command.h"
#include "order_service_handler.h"

#define __ORDER_SERVICE_CALL_TABLE(number, function_prototype) [number] = function_prototype,

__ORDER_SERVICE_CALL_TABLE(ORDER_REGISTER_SERVICE, order_register_service)
__ORDER_SERVICE_CALL_TABLE(ORDER_LIST_SERVICE, order_list_service)

#endif
