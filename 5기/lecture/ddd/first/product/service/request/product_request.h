#ifndef __PRODUCT_REQUEST_H__
#define __PRODUCT_REQUEST_H__

#include "../../entity/product.h"

typedef struct _product_request product_request;
struct _product_request
{
    char name[PRODUCT_NAME_MAX];
    int price;
    char *details[PRODUCT_DETAILS_MAX];
};

product_request *init_product_request (char *name, int price, char *password);
void print_product_request (product_request *product_request_object);
product *to_member (product_request *product_request_object);
void free_member_request (product_request *product_request_object);

#endif
