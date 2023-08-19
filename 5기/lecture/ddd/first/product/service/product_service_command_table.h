#ifndef __PRODUCT_SERVICE_COMMAND_TABLE_H__
#define __PRODUCT_SERVICE_COMMAND_TABLE_H__

#include <stdio.h>
#include "product_service_command.h"

#include "request/product_request.h"

typedef void (* product_service_call_ptr_t) (product_request *);

void product_service_not_implemented (product_request *nothing)
{
    printf("아직 구현되지 않은 스펙입니다!\n");
}

const product_service_call_ptr_t product_service_table[PRODUCT_SERVICE_CALL_BUFFER_COUNT] = {
        [0 ... PRODUCT_SERVICE_CALL_BUFFER] = &product_service_not_implemented,
#include "product_service_command_table_mapper.h"
};

#endif
