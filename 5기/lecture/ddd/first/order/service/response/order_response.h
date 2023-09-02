#ifndef __ORDER_RESPONSE_H__
#define __ORDER_RESPONSE_H__

#define ORDER_NAME_MAX            32
#define ORDER_DETAILS_MAX         32

typedef struct _order_response order_response;
struct _order_response
{
    int unique_value;
    int member_unique_id;
    int product_unique_id;
};

order_response *init_order_response (int unique_value, int member_unique_id, int product_unique_id);
void print_order_response (order_response *order_response_object);

#endif
