#ifndef __PROTOCOL_CALL_TABLE_H__
#define __PROTOCOL_CALL_TABLE_H__

#include <stdio.h>
#include "protocol.h"

// void (*)(void*) == protocol_call_ptr_type
// int (*)(int)

typedef void (*protocol_call_ptr_t) (void* p);

void protocol_not_implemented (void* p)
{
    printf("미구현 스펙 입니다.\n");
}

const protocol_call_ptr_t protocol_call_table[PROTOCOL_CALL_BUFFER_COUNT] = {
    [0 ... PROTOCOL_CALL_BUFFER] = &protocol_not_implemented,
    #include "protocol_call_table_mapper.h"
};

#endif