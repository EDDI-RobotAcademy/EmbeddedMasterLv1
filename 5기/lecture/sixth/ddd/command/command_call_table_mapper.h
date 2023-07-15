#ifndef __COMMAND_CALL_TABLE_MAPPER_H__
#define __COMMAND_CALL_TABLE_MAPPER_H__

#include "../member/member_handler.h"
#include "command_handler.h"
#include "command.h"

#define __COMMAND_CALL_TABLE(number, function_prototype) [number] = function_prototype,

__COMMAND_CALL_TABLE(EXIT, program_exit)
__COMMAND_CALL_TABLE(MEMBER_REGISTER, member_register)
__COMMAND_CALL_TABLE(MEMBER_LOGIN, member_login)

#endif