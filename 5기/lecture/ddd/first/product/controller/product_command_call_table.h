#ifndef __PRODUCT_COMMAND_CALL_TABLE_H__
#define __PRODUCT_COMMAND_CALL_TABLE_H__

#include <stdio.h>
#include "product_command.h"

typedef void (* product_call_ptr_t) (void);

void product_protocol_not_implemented (void)
{
    printf("아직 구현되지 않은 스펙입니다!\n");
}

const product_call_ptr_t product_call_table[PRODUCT_CALL_BUFFER_COUNT] = {
        [0 ... PRODUCT_CALL_BUFFER] = &product_protocol_not_implemented,
#include "product_command_call_table_mapper.h"
};

#endif
