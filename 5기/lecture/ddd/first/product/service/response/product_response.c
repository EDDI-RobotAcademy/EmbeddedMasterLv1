#include "product_response.h"

#include <string.h>
#include <stdlib.h>

product_response *init_product_response (int unique_value, char *name, int price, char *details)
{
    int name_length = strlen(name);
    int details_length = strlen(details);
    product_response *product_response_object = (product_response *)malloc(sizeof(product_response));

    product_response_object->unique_value = unique_value;
    strncpy(product_response_object->name, name, name_length);
    product_response_object->price = price;
    strncpy(product_response_object->details, details, details_length);

    return product_response_object;
}