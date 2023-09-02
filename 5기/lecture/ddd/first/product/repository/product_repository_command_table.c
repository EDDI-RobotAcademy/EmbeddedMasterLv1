#include "product_repository_command_table.h"
#include "product_repository_handler.h"

typedef product_response (* product_repository_call_ptr_t) (void *);

product_response *product_repository_not_implemented (void *nothing)
{
    printf("아직 구현되지 않은 스펙입니다!\n");
    return NULL;
}

const product_repository_call_ptr_t product_repository_table[PRODUCT_REPOSITORY_CALL_BUFFER_COUNT] = {
        [0 ... PRODUCT_REPOSITORY_CALL_BUFFER] = (product_repository_call_ptr_t const) product_repository_not_implemented,
#include "product_repository_command_table_mapper.h"
};
