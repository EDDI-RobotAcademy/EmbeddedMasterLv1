#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "product.h"

int unique_product_value_count = 0;

product *init_product (char *name, int price, char *details)
{
    int name_length = strlen(name);
    int details_length = strlen(details);
    product *product_object = (product *)malloc(sizeof(product));

    strncpy(product_object->name, name, name_length);
    product_object->price = price;
    strncpy(product_object->details, details, details_length);
    product_object->unique_value = unique_product_value_count++;

    return product_object;
}

void print_product (product *product_object)
{
    printf("product unique value: %d\n", product_object->unique_value);
    printf("product name: %s\n", product_object->name);
    printf("product price: %d\n", product_object->price);
    printf("product details: %s\n", product_object->details);
}

void free_product (product *product_object)
{
    printf("free product memory\n");
    printf("product_object: 0x%x\n", product_object);

    free(product_object);
}