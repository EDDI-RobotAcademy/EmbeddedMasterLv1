#include "product_command_handler.h"
#include "../entity/product.h"

#include "../service/product_service_command.h"
#include "../service/product_service_handler.h"
#include "../service/product_service_command_table.h"

#include "../service/request/product_request.h"

#include "../../ui/console/user_input.h"
#include "../../session/session.h"

#include <stdio.h>
#include <string.h>

void product_register (void)
{

}

void product_list (void)
{
    printf("product controller: list()\n");

    product_service_table[PRODUCT_LIST_SERVICE](NULL);
}