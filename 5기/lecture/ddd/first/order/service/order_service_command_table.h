#ifndef __ORDER_SERVICE_COMMAND_TABLE_H__
#define __ORDER_SERVICE_COMMAND_TABLE_H__

#include <stdio.h>
#include "order_service_command.h"

#include "request/order_request.h"

typedef void (* order_service_call_ptr_t) (order_request *);

void order_service_not_implemented (order_request *nothing)
{
    printf("아직 구현되지 않은 스펙입니다!\n");
}

const order_service_call_ptr_t order_service_table[ORDER_SERVICE_CALL_BUFFER_COUNT] = {
        [0 ... ORDER_SERVICE_CALL_BUFFER] = &order_service_not_implemented,
#include "order_service_command_table_mapper.h"
};

#endif
