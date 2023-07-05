#ifndef __PROTOCOL_TABLE_H__
#define __PROTOCOL_TABLE_H__

#include "protocol.h"

// void(*)(void) = protocol_call_ptr_t
// int (*)(int)
typedef void (* protocol_call_ptr_t) (void);

void protocol_not_implemented (void)
{
    printf ("아직 구현되지 않은 스펙입니다! \n");
}

const protocol_call_ptr_t protocol_call_table [PROTOCOL_CALL_BUFFER_COUNT] =
{
    [0 ... PROTOCOL_CALL_BUFFER] = &protocol_not_implemented,
    #include "protocol_call_table_mapper.h"
};

#endif