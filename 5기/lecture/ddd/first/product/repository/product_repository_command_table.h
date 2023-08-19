#ifndef __PRODUCT_REPOSITORY_COMMAND_TABLE_H__
#define __PRODUCT_REPOSITORY_COMMAND_TABLE_H__

#include <stdio.h>
#include "product_repository_command.h"

#include "../entity/product.h"
#include "../service/response/product_response.h"

typedef product_response (* product_repository_call_ptr_t) (void *);

product_response *product_repository_not_implemented (void *nothing)
{
    printf("아직 구현되지 않은 스펙입니다!\n");
    return NULL;
}

const static product_repository_call_ptr_t product_repository_table[PRODUCT_REPOSITORY_CALL_BUFFER_COUNT] = {
        [0 ... PRODUCT_REPOSITORY_CALL_BUFFER] = (product_repository_call_ptr_t const) product_repository_not_implemented,
#include "product_repository_command_table_mapper.h"
};

#endif
