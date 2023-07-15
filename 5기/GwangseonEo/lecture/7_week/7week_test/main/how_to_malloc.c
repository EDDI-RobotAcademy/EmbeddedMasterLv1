#include "how_to_malloc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _test_data test_data;
struct _test_data
{
    int age;
    char *name;
    struct _test_data *link;
};

void print_malloced_data (test_data *data)
{
    printf("age = %d\n", data->age);
    printf("name = %s\n", data->name);
    printf("link = 0x%x\n", data->link);
}

void how_to_malloc_data (void)
{
    printf("malloc으로 구조체 할당하는 방법을 살펴보자!\n");
 
    char name[10] = "안녕";
    int name_length = strlen(name);

    test_data *malloced_data = (test_data *)malloc(sizeof(test_data));
    malloced_data->age = 10;
    malloced_data->name = (char *)malloc(name_length + 1);
    strncpy(malloced_data->name, name, name_length);
    malloced_data->link = NULL;

    print_malloced_data(malloced_data);
    free(malloced_data);
}