#ifndef __FREE_MEMORY_TABLE_H__
#define __FREE_MEMORY_TABLE_H__

#include "../entity/pre_allocated_memory.h"

typedef struct _free_memory_idx free_memory_idx;

struct _free_memory_idx
{
    int idx;
    int state;
    struct _free_memory_idx *next;
};

typedef struct _free_memory_table free_memory_table;

struct _free_memory_table
{
    free_memory_idx *free_idx[MEMORY_SIZE_LIMIT];
};

free_memory_table free_memory[PREALLOC_COUNT];

#define NOT_YET                 -1
#define USAGE                   1

void init_free_memory_table (void);
void print_free_memory_table (void);
void adjust_free_memory_table(int, int);

#endif
