#include "order_request.h"

#include <stdlib.h>
#include <stdio.h>

order_request *init_order_request (int member_unique_id, int product_unique_id)
{
    order_request *order_request_object = (order_request *)malloc(sizeof(order_request));

    order_request_object->member_unique_id = member_unique_id;
    order_request_object->product_unique_id = product_unique_id;

    return order_request_object;
}

void print_order_request (order_request *order_request_object)
{
    printf("order member id: %d\n", order_request_object->member_unique_id);
    printf("order product id: %d\n", order_request_object->product_unique_id);
}

order *to_order (order_request *order_request_object)
{
    order *order_object = init_order(
            order_request_object->member_unique_id,
            order_request_object->product_unique_id);

    return order_object;
}

void free_order_request (order_request *order_request_object)
{
    printf("free order_request memory\n");

    free(order_request_object);
}