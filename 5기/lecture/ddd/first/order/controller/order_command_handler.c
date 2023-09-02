#include "order_command_handler.h"
#include "../entity/order.h"

#include "../service/order_service_command.h"
#include "../service/order_service_handler.h"
#include "../service/order_service_command_table.h"

#include "../service/request/order_request.h"

#include "../../ui/console/user_input.h"
#include "../../session/session.h"

#include <stdio.h>
#include <string.h>

void order_register (void)
{
    printf("order controller: register()\n");

    order_service_table[ORDER_REGISTER_SERVICE](NULL);
}

void order_list (void)
{
    printf("order controller: list()\n");

    order_service_table[ORDER_LIST_SERVICE](NULL);
}