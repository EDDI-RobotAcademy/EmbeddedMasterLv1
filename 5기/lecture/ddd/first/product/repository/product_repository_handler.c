#include "product_repository_handler.h"
#include "../../data_structure/queue/queue.h"

#include "../../session/session.h"

#include <stdio.h>

struct _custom_queue *product_queue;

product_response *product_save_repository (void *product_object)
{
    printf("product repository: save()\n");

    product_queue = enqueue_data(product_queue, product_object, PRODUCT_REQUEST);
    return NULL;
}

product_response *product_find_by_id_repository (void *finding_product_idx)
{
    printf("product repository: find_by_id()\n");

    product *found_product = find_queue_data(product_queue, finding_product_idx, PRODUCT_REQUEST);
    product_response *product_response_object = init_product_response(
            found_product->unique_value, found_product->name,
            found_product->price, found_product->details);

    return product_response_object;
}

product_response *product_find_all_repository (void *product_object)
{
    printf("product repository: find_all()\n");
    print_queue_data(product_queue, PRODUCT_REQUEST);
    return NULL;
}