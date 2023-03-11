#include <stdio.h>

#include "save_to_void_pointer_array.h"
#include "../flexible_type.h"

void save_bool(void *arr[])
{
    arr[0] = any_type.void_pointer_type_array[0];
}

void save_char(void *arr[])
{
    arr[0] = any_type.void_pointer_type_array[0];
}

void save_unsigned_char(void *arr[])
{
    arr[0] = any_type.void_pointer_type_array[0];
}

void save_short(void *arr[])
{
    arr[0] = any_type.void_pointer_type_array[0];
}

void save_unsigned_short(void *arr[])
{
    arr[0] = any_type.void_pointer_type_array[0];
}

void save_int(void *arr[])
{
    arr[0] = any_type.void_pointer_type_array[0];
}

void save_unsigned_int(void *arr[])
{
    arr[0] = any_type.void_pointer_type_array[0];
}

void save_long(void *arr[])
{
    arr[0] = any_type.void_pointer_type_array[0];
}

void save_unsigned_long(void *arr[])
{
    arr[0] = any_type.void_pointer_type_array[0];
}

void save_long_long(void *arr[])
{
    arr[0] = any_type.void_pointer_type_array[0];
}

void save_unsigned_long_long(void *arr[])
{
    arr[0] = any_type.void_pointer_type_array[0];
}

void save_float(void *arr[])
{
    arr[0] = any_type.void_pointer_type_array[0];
}

void save_double(void *arr[])
{
    arr[0] = any_type.void_pointer_type_array[0];
}

void save_long_double(void *arr[])
{
    arr[0] = any_type.void_pointer_type_array[0];
    arr[1] = any_type.void_pointer_type_array[1];
}

void save_char_pointer(void *arr[])
{
    arr[0] = any_type.void_pointer_type_array[0];
}

void save_int_pointer(void *arr[])
{
    arr[0] = any_type.void_pointer_type_array[0];
}

void save_double_pointer(void *arr[])
{
    arr[0] = any_type.void_pointer_type_array[0];
}

void save_void_pointer(void *arr[])
{
    arr[0] = any_type.void_pointer_type_array[0];
}

void save_other(void *arr[])
{
    printf("이 타입에 대한 정의가 없습니다.\n");
}