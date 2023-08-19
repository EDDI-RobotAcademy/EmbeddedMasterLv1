#ifndef __MEMBER_COMMAND_CALL_TABLE_MAPPER_H__
#define __MEMBER_COMMAND_CALL_TABLE_MAPPER_H__

#include "member_command.h"
#include "member_command_handler.h"

#define __MEMBER_COMMAND_CALL_TABLE(number, function_prototype) [number] = function_prototype,

__MEMBER_COMMAND_CALL_TABLE(MEMBER_REGISTER, member_register)
__MEMBER_COMMAND_CALL_TABLE(MEMBER_LOGIN, member_login)
__MEMBER_COMMAND_CALL_TABLE(MEMBER_LIST, member_list)

#endif
