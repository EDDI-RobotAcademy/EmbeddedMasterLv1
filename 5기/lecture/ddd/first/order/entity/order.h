#ifndef __ORDER_H__
#define __ORDER_H__

#define ORDER_NAME_MAX        32
#define ORDER_DETAILS_MAX     32

typedef struct _order order;
struct _order
{
    int unique_value;
    int member_unique_id;
    int product_unique_id;
};

extern int unique_order_value_count;

order *init_order (int member_unique_id, int product_unique_id);
void print_order (order *order_object);
void free_order (order *order_object);

#endif