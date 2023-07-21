#ifndef __MEMBER_SERVICE_COMMAND_TABLE_H__
#define __MEMBER_SERVICE_COMMAND_TABLE_H__

#include <stdio.h>
#include "member_service_command.h"

#include "request/member_request.h"

typedef void (* member_service_call_ptr_t) (member_request *);

void member_service_not_implemented (member_request *nothing)
{
    printf("아직 구현되지 않은 스펙입니다!\n");
}

const member_service_call_ptr_t member_service_table[MEMBER_SERVICE_CALL_BUFFER_COUNT] = {
        [0 ... MEMBER_SERVICE_CALL_BUFFER] = &member_service_not_implemented,
#include "member_service_command_table_mapper.h"
};

#endif
