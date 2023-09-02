#ifndef __ORDER_REPOSITORY_HANDLER_H__
#define __ORDER_REPOSITORY_HANDLER_H__

#include "../entity/order.h"
#include "../service/response/order_response.h"

order_response *order_save_repository (void *);
order_response *order_find_by_id_repository (void *);
order_response *order_find_all_repository (void *);

#endif
