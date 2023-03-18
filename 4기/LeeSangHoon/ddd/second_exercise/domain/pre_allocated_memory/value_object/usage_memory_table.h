#ifndef __USAGE_MEMORY_TABLE_H__
#define __USAGE_MEMORY_TABLE_H__

#include "../entity/pre_allocated_memory.h"

typedef struct _usage_memory_idx usage_memory_idx;

struct _usage_memory_idx
{
    int idx;
    int state;
    struct _usage_memory_idx *next;
};

typedef struct _usage_memory_table usage_memory_table;

struct _usage_memory_table
{
    usage_memory_idx *usage_idx[MEMORY_SIZE_LIMIT];
};

usage_memory_table usage_memory[PREALLOC_COUNT];

#define NOT_YET                 -1
#define USAGE                   1

void init_usage_memory_table (void);
void print_usage_memory_table (void);
void set_usage_memory_table(int, int);

#endif
