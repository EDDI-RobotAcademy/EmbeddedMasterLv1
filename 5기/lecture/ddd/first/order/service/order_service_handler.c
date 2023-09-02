#include "order_service_handler.h"

#include "response/order_response.h"
#include "request/order_request.h"
#include "../entity/order.h"

#include "../repository/order_repository_command.h"
#include "../repository/order_repository_handler.h"
#include "../repository/order_repository_command_table.h"

#include "../../product/repository/product_repository_command.h"
#include "../../product/repository/product_repository_handler.h"
#include "../../product/repository/product_repository_command_table.h"

#include "../../command/command.h"
#include "../../session/session.h"

#include <stdio.h>

void order_register_service (order_request *order_request_object)
{
    int command;
    int member_unique_id;

    printf("order service: register()\n");
    printf("주문할 상품 번호를 눌러주세요!\n");

    product_repository_table[PRODUCT_FIND_ALL_REPOSITORY](NULL);

    command = input_user_command();
    member_unique_id = find_unique_id_from_session();
    printf("found member unique id: %d\n", member_unique_id);
    //member_repository_table[MEMBER_FIND_BY_]
}

void order_list_service (order_request *order_request_object)
{
    printf("order service: list()\n");

    order_repository_table[ORDER_FIND_ALL_REPOSITORY](order_request_object);
}
