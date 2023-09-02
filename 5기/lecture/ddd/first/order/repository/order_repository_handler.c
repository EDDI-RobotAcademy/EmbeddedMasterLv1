#include "order_repository_handler.h"
#include "../../data_structure/queue/queue.h"

#include "../../session/session.h"

#include <stdio.h>

struct _custom_queue *order_queue;

order_response *order_save_repository (void *order_object)
{
    printf("order repository: save()\n");

    order_queue = enqueue_data(order_queue, order_object, ORDER_REQUEST);
    return NULL;
}

order_response *order_find_by_id_repository (void *finding_order_idx)
{
    printf("order repository: find_by_id()\n");

    order *found_order = find_queue_data(order_queue, finding_order_idx, ORDER_REQUEST);
    order_response *order_response_object = init_order_response(
            found_order->unique_value,
            found_order->member_unique_id,
            found_order->product_unique_id);

    return order_response_object;
}

order_response *order_find_all_repository (void *order_object)
{
    printf("order repository: find_all()\n");
    print_queue_data(order_queue, ORDER_REQUEST);
    return NULL;
}