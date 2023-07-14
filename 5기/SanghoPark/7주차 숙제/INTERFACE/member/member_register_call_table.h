#ifndef __MEMBER_REGISTER_CALL_TABLE_H__
#define __MEMBER_REGISTER_CALL_TABLE_H__

#include <stdio.h>
#include "member.h"

typedef void* (*member_register_ptr_t) (char* pId, char* pPassword);

void* member_handler_not_implemented (char* pId, char* pPassword)
{
    printf("미구현 스펙 입니다.\n");

    return (void*)-1;
}

const member_register_ptr_t member_register_call_table[MEMBER_REGISTER_CALL_BUFFER_COUNT] = {
    [0 ... MEMBER_REGISTER_CALL_BUFFER] = &member_handler_not_implemented,
    #include "member_register_call_table_mapper.h"
};

#endif