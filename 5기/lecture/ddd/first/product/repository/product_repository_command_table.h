#ifndef __PRODUCT_REPOSITORY_COMMAND_TABLE_H__
#define __PRODUCT_REPOSITORY_COMMAND_TABLE_H__

#include <stdio.h>
#include "product_repository_command.h"

#include "../entity/product.h"
#include "../service/response/product_response.h"

typedef product_response (* product_repository_call_ptr_t) (void *);

product_response *product_repository_not_implemented (void *nothing);

extern const product_repository_call_ptr_t product_repository_table[PRODUCT_REPOSITORY_CALL_BUFFER_COUNT];

#endif
