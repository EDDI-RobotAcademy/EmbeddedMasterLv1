#ifndef __ORDER_REPOSITORY_COMMAND_TABLE_H__
#define __ORDER_REPOSITORY_COMMAND_TABLE_H__

#include <stdio.h>
#include "order_repository_command.h"

#include "../entity/order.h"
#include "../service/response/order_response.h"

typedef order_response (* order_repository_call_ptr_t) (void *);

order_response *order_repository_not_implemented (void *nothing)
{
    printf("아직 구현되지 않은 스펙입니다!\n");
    return NULL;
}

const static order_repository_call_ptr_t order_repository_table[ORDER_REPOSITORY_CALL_BUFFER_COUNT] = {
        [0 ... ORDER_REPOSITORY_CALL_BUFFER] = (order_repository_call_ptr_t const) order_repository_not_implemented,
#include "order_repository_command_table_mapper.h"
};

#endif
