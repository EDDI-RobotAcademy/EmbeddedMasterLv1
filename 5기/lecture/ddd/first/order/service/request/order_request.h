#ifndef __PRODUCT_REQUEST_H__
#define __PRODUCT_REQUEST_H__

#include "../../entity/order.h"

typedef struct _order_request order_request;
struct _order_request
{
    int member_unique_id;
    int product_unique_id;
};

order_request *init_order_request (int member_unique_id, int product_unique_id);
void print_order_request (order_request *order_request_object);
order *to_order (order_request *order_request_object);
void free_order_request (order_request *order_request_object);

#endif
