#ifndef __FLEXIBLE_TYPE_H__
#define __FLEXIBLE_TYPE_H__

#include <stdbool.h>
#include "../sizes.h"

#define LARGEST_DATA_TYPE_SIZE      SIZEOF_LONG_DOUBLE
#define VOID_POINTER_ARRAY_LENGTH   LARGEST_DATA_TYPE_SIZE / SIZEOF_VOID_POINTER

typedef union _flexible_type flexible_type;

union _flexible_type
{
    bool bool_type;
    char char_type;
    unsigned char unsigned_char_type;
    short short_type;
    unsigned short unsigned_short_type;
    int int_type;
    unsigned int unsigned_int_type;
    long long_type;
    unsigned long unsigned_long_type;
    long long long_long_type;
    unsigned long long unsigned_long_long_type;
    float float_type;
    double double_type;
    long double long_double_type;
    char *char_pointer_type;
    int *int_pointer_type;
    double *double_pointer_type;
    void *void_pointer_type_array[VOID_POINTER_ARRAY_LENGTH];
};

flexible_type any_type;

#endif // __FLEXIBLE_TYPE_H__