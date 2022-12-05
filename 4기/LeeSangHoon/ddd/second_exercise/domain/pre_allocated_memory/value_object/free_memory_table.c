#include <stdlib.h>
#include <stdio.h>

#include "free_memory_table.h"

void init_free_memory_table (void)
{
    int i, j;

    for (i = 0; i < PREALLOC_COUNT; i++)
    {
        for (j = 0; j < MEMORY_SIZE_LIMIT; j++)
        {
            free_memory[i].free_idx[j] = (free_memory_idx *)malloc(sizeof(free_memory_idx));
            free_memory[i].free_idx[j]->idx = j;
            free_memory[i].free_idx[j]->state = NOT_YET;

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

void adjust_free_memory_table(int memory_idx, int will_be_set_idx)
{
    free_memory_idx current_set_idx = *free_memory[memory_idx].free_idx[will_be_set_idx];
    current_set_idx.idx = current_set_idx.next->idx;
    current_set_idx.next = current_set_idx.next->next;
    current_set_idx.state = USAGE;
}
