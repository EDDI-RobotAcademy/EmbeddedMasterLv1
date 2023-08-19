#ifndef __PRODUCT_REPOSITORY_HANDLER_H__
#define __PRODUCT_REPOSITORY_HANDLER_H__

#include "../entity/product.h"
#include "../service/response/product_response.h"

product_response *product_save_repository (void *);
product_response *product_find_by_id_repository (void *);
product_response *product_find_all_repository (void *);

#endif
