#include "product_request.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

product_request *init_product_request (char *name, int price, char *details)
{
    int name_length = strlen(name);
    int details_length = strlen(details);
    product_request *product_request_object = (product_request *)malloc(sizeof(product_request));

    strncpy(product_request_object->name, name, name_length);
    product_request_object->price = price;
    strncpy(product_request_object->details, details, details_length);

    return product_request_object;
}

void print_product_request (product_request *product_request_object)
{
    printf("product request name: %s\n", product_request_object->name);
    printf("product request price: %s\n", product_request_object->price);
    printf("product request details: %s\n", product_request_object->details);
}

product *to_product (product_request *product_request_object)
{
    product *product_object = init_product(
            product_request_object->name,
            product_request_object->price,
            product_request_object->details);

    return product_object;
}

void free_product_request (product_request *product_request_object)
{
    printf("free product_request memory\n");

    free(product_request_object);
}