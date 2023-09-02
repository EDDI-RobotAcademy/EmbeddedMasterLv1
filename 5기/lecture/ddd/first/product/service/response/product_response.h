#ifndef __PRODUCT_RESPONSE_H__
#define __PRODUCT_RESPONSE_H__

#define PRODUCT_NAME_MAX            32
#define PRODUCT_DETAILS_MAX         32

typedef struct _product_response product_response;
struct _product_response
{
    int unique_value;
    char name[PRODUCT_NAME_MAX];
    int price;
    char *details[PRODUCT_DETAILS_MAX];
};

product_response *init_product_response (int unique_value, char *name, int price, char *details);
void print_product_response (product_response *product_response_object);

#endif
