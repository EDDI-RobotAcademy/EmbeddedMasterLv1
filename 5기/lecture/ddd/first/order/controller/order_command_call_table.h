#ifndef __ORDER_COMMAND_CALL_TABLE_H__
#define __ORDER_COMMAND_CALL_TABLE_H__

#include <stdio.h>
#include "order_command.h"

typedef void (* order_call_ptr_t) (void);

void order_protocol_not_implemented (void)
{
    printf("아직 구현되지 않은 스펙입니다!\n");
}

const order_call_ptr_t order_call_table[ORDER_CALL_BUFFER_COUNT] = {
        [0 ... ORDER_CALL_BUFFER] = &order_protocol_not_implemented,
#include "order_command_call_table_mapper.h"
};

#endif
