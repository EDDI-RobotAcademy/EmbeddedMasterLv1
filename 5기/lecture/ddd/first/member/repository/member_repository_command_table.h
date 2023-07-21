#ifndef __MEMBER_REPOSITORY_COMMAND_TABLE_H__
#define __MEMBER_REPOSITORY_COMMAND_TABLE_H__

#include <stdio.h>
#include "member_repository_command.h"

#include "../entity/member.h"

typedef void (* member_repository_call_ptr_t) (member *);

void member_repository_not_implemented (member *nothing)
{
    printf("아직 구현되지 않은 스펙입니다!\n");
}

const member_repository_call_ptr_t member_repository_table[MEMBER_REPOSITORY_CALL_BUFFER_COUNT] = {
        [0 ... MEMBER_REPOSITORY_CALL_BUFFER] = &member_repository_not_implemented,
#include "member_repository_command_table_mapper.h"
};

#endif
