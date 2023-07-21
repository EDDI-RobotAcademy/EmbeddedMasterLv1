#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "member.h"

int unique_member_value_count = 0;

member *init_member (char *id, char *password)
{
    int id_length = strlen(id) + 1;
    int password_length = strlen(password);
    member *member_object = (member *)malloc(sizeof(member));

    member_object->id = (char *)malloc(sizeof(char) * id_length);
    strncpy(member_object->id, id, id_length);
    memset(member_object->password, 0x0, MAX_USER_INPUT);
    strncpy(member_object->password, password, password_length);
    member_object->unique_value = unique_member_value_count++;

    return member_object;
}

void print_member (member *member_object)
{
    printf("member unique value: %d\n", member_object->unique_value);
    printf("member id: %s\n", member_object->id);
    printf("member password: %s\n", member_object->password);
}

void free_member (member *member_object)
{
    printf("free member memory\n");
    printf("member_object: 0x%x\n", member_object);
    printf("member_object->id: %s\n", member_object->id);

    free(member_object->id);
    free(member_object);
}