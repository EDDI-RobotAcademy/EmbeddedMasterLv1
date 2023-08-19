#include "product_service_handler.h"

#include "response/product_response.h"
#include "request/product_request.h"
#include "../entity/product.h"

#include "../repository/product_repository_command.h"
#include "../repository/product_repository_handler.h"
#include "../repository/product_repository_command_table.h"

#include <stdio.h>

void product_register_service (product_request *product_request_object)
{
    printf("product service: register()\n");
}

void product_list_service (product_request *product_request_object)
{
    printf("product service: list()\n");

    product_repository_table[PRODUCT_FIND_ALL_REPOSITORY](product_request_object);
}
