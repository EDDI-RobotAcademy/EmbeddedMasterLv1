#include "order_response.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

order_response *init_order_response (int unique_value, int member_unique_id, int product_unique_id)
{
    order_response *order_response_object = (order_response *)malloc(sizeof(order_response));

    order_response_object->unique_value = unique_value;
    order_response_object->member_unique_id = member_unique_id;
    order_response_object->product_unique_id = product_unique_id;

    return order_response_object;
}

void print_order_response (order_response *order_response_object)
{
    printf("order unique value: %d\n", order_response_object->unique_value);
    printf("order member id: %s\n", order_response_object->member_unique_id);
    printf("order product id: %d\n", order_response_object->product_unique_id);
}