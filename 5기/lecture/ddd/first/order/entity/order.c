#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "order.h"

int unique_order_value_count = 0;

order *init_order (int member_unique_id, int product_unique_id)
{
    order *order_object = (order *)malloc(sizeof(order));

    order_object->member_unique_id = member_unique_id;
    order_object->product_unique_id = product_unique_id;
    order_object->unique_value = unique_order_value_count++;

    return order_object;
}

void print_order (order *order_object)
{
    printf("order unique value: %d\n", order_object->unique_value);
    printf("order name: %d\n", order_object->member_unique_id);
    printf("order price: %d\n", order_object->product_unique_id);
}

void free_order (order *order_object)
{
    printf("free product memory\n");
    printf("product_object: 0x%x\n", order_object);

    free(order_object);
}