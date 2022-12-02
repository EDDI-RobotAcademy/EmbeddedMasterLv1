#include <malloc.h>
#include <stdio.h>
#include "free_memory_table.h"

void init_free_memory_table (void)
{
    int i, j;

    for (i = 0; i < PREALLOC_COUNT; i++)
    {
        for (j = 0; j < MEMORY_SIZE_LIMIT; j++)
        {
            free_memory[i].free_idx[j] = (free_memory_idx *) malloc(sizeof(free_memory_idx));
            free_memory[i].free_idx[j]->idx = NOT_YET;

            if (j > 0)
            {
                free_memory[i].free_idx[j - 1]->next = free_memory[i].free_idx[j];
            }
        }
    }
}

void print_free_memory_table (void)
{
    int i, j;

    for (i = 0; i < PREALLOC_COUNT; i++)
    {
        for (j = 0; j < MEMORY_SIZE_LIMIT; j++)
        {
            printf("idx = %d, ", free_memory[i].free_idx[j]->idx);

            if (free_memory[i].free_idx[j]->next != NULL)
            {
                printf("next = %d\n", free_memory[i].free_idx[j]->next->idx);
            }
            else
            {
                printf("next = NULL\n");
            }
        }
    }
}
