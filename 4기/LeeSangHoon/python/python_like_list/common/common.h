#ifndef __COMMON_H__
#define __COMMON_H__

#define MEMORY_ALLOC_SUCCESS            1
#define MEMORY_ALLOC_FAILURE            0

#include <stdbool.h>

enum t_typename {
    TYPENAME_BOOL,
    TYPENAME_UNSIGNED_CHAR,
    TYPENAME_CHAR,
    TYPENAME_SHORT_INT,
    TYPENAME_UNSIGNED_SHORT_INT,
    TYPENAME_INT,
    TYPENAME_UNSIGNED_INT,
    TYPENAME_LONG_INT,
    TYPENAME_UNSIGNED_LONG_INT,
    TYPENAME_LONG_LONG_INT,
    TYPENAME_UNSIGNED_LONG_LONG_INT,
    TYPENAME_FLOAT,
    TYPENAME_DOUBLE,
    TYPENAME_LONG_DOUBLE,
    TYPENAME_POINTER_TO_CHAR,
    TYPENAME_POINTER_TO_VOID,
    TYPENAME_POINTER_TO_INT,
    TYPENAME_POINTER_TO_DOUBLE,
    TYPENAME_OTHER
};

#define typecheck(T)                        _Generic((T),       \
    bool: TYPENAME_BOOL,                                        \
    unsigned char: TYPENAME_UNSIGNED_CHAR,                      \
    char: TYPENAME_CHAR,                                        \
    short int: TYPENAME_SHORT_INT,                              \
    unsigned short int: TYPENAME_UNSIGNED_SHORT_INT,            \
    int: TYPENAME_INT,                                          \
    unsigned int: TYPENAME_UNSIGNED_INT,                        \
    long int: TYPENAME_LONG_INT,                                \
    unsigned long int: TYPENAME_UNSIGNED_LONG_INT,              \
    long long int: TYPENAME_LONG_LONG_INT,                      \
    unsigned long long int: TYPENAME_UNSIGNED_LONG_LONG_INT,    \
    float: TYPENAME_FLOAT,                                      \
    double: TYPENAME_DOUBLE,                                    \
    long double: TYPENAME_LONG_DOUBLE,                          \
    char *: TYPENAME_POINTER_TO_CHAR,                           \
    void *: TYPENAME_POINTER_TO_VOID,                           \
    int *: TYPENAME_POINTER_TO_INT,                             \
    double *: TYPENAME_POINTER_TO_DOUBLE,                       \
    default: TYPENAME_OTHER)

#endif
