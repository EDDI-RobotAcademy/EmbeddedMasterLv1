#ifndef __MEMBER_SERVICE_COMMAND_TABLE_MAPPER_H__
#define __MEMBER_SERVICE_COMMAND_TABLE_MAPPER_H__

#include "member_service_command.h"
#include "member_service_handler.h"

#define __MEMBER_SERVICE_CALL_TABLE(number, function_prototype) [number] = function_prototype,

__MEMBER_SERVICE_CALL_TABLE(MEMBER_REGISTER_SERVICE, member_register_service)
__MEMBER_SERVICE_CALL_TABLE(MEMBER_LOGIN_SERVICE, member_login_service)
__MEMBER_SERVICE_CALL_TABLE(MEMBER_LIST_SERVICE, member_list_service)

#endif
