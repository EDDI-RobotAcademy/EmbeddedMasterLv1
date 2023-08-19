#ifndef __PRODUCT_SERVICE_COMMAND_TABLE_MAPPER_H__
#define __PRODUCT_SERVICE_COMMAND_TABLE_MAPPER_H__

#include "product_service_command.h"
#include "product_service_handler.h"

#define __PRODUCT_SERVICE_CALL_TABLE(number, function_prototype) [number] = function_prototype,

__PRODUCT_SERVICE_CALL_TABLE(PRODUCT_REGISTER_SERVICE, product_register_service)
__PRODUCT_SERVICE_CALL_TABLE(PRODUCT_LIST_SERVICE, product_list_service)

#endif
