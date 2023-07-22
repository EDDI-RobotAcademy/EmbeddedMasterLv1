#ifndef __COMMAND_CALL_TABLE_H__
#define __COMMAND_CALL_TABLE_H__

#include <stdio.h>

#include "command.h"

typedef void (* command_call_ptr_t) (void);

void protocol_not_implemented (void)
{
    printf("아직 구현되지 않은 스펙입니다!\n");
}

const command_call_ptr_t command_call_table[COMMAND_CALL_BUFFER_COUNT] = {
        [0 ... COMMAND_CALL_BUFFER] = &protocol_not_implemented,
#include "command_call_table_mapper.h"
};

#endif