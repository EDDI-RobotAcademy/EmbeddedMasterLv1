#ifndef __COMMAND_CALL_TABLE_MAPPER_H__
#define __COMMAND_CALL_TABLE_MAPPER_H__

#include "command.h"
#include "command_handler.h"

#define __COMMAND_CALL_TABLE(number, function_prototype) [number] = function_prototype,

__COMMAND_CALL_TABLE(EXIT, program_exit)
__COMMAND_CALL_TABLE(MEMBER, invoke_member_call_table)

#endif