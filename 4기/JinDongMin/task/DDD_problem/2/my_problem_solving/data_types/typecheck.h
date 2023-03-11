#ifndef __TYPECHECK_H__
#define __TYPECHECK_H__

#include <stdbool.h>
#include "data_type.h"

#define typecheck(T)                    _Generic((T),   \
    bool: TYPENAME_BOOL,                                \
    char: TYPENAME_CHAR,                                \
    unsigned char: TYPENAME_UNSIGNED_CHAR,              \
    short: TYPENAME_SHORT,                              \
    unsigned short: TYPENAME_UNSIGNED_SHORT,            \
    int: TYPENAME_INT,                                  \
    unsigned int: TYPENAME_UNSIGNED_INT,                \
    long: TYPENAME_LONG,                                \
    unsigned long: TYPENAME_UNSIGNED_LONG,              \
    long long: TYPENAME_LONG_LONG,                      \
    unsigned long long: TYPENAME_UNSIGNED_LONG_LONG,    \
    float: TYPENAME_FLOAT,                              \
    double: TYPENAME_DOUBLE,                            \
    long double: TYPENAME_LONG_DOUBLE,                  \
    char *: TYPENAME_CHAR_POINTER,                      \
    int *: TYPENAME_INT_POINTER,                        \
    double *: TYPENAME_DOUBLE_POINTER,                  \
    void *: TYPENAME_VOID_POINTER,                      \
    default: TYPENAME_OTHER                             \
)

#endif // __TYPECHECK_H__