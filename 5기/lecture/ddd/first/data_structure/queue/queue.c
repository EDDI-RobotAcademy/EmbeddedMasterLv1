#include "queue.h"
#include "../../member/entity/member.h"
#include "../../product/entity/product.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define POINTER_SIZE            8

custom_queue *alloc_new_queue_node ()
{
    custom_queue *tmp;
    tmp = (custom_queue *) malloc (sizeof(custom_queue));
    tmp->link = NULL;

    return tmp;
}

void alloc_request_type_data (custom_queue *head, void *data, enum queue_request request)
{
    switch (request)
    {
        case MEMBER_REQUEST:
            head->data = (member *) malloc (sizeof(member));
            memmove(head->data, data, sizeof(member));
            break;

        case PRODUCT_REQUEST:
            head->data = (product *) malloc (sizeof(product));
            memmove(head->data, data, sizeof(product));
            break;
        
        default:
            head->data = NULL;
            break;
    }
}

custom_queue *enqueue_data (custom_queue *head, void *data, enum queue_request request)
{
    custom_queue *new_queue_node = alloc_new_queue_node();
    custom_queue *tmp = head;

    alloc_request_type_data(new_queue_node, data, request);

    if (!head) { return new_queue_node; }

    while (tmp->link)
    {
        tmp = tmp->link;
    }

    tmp->link = new_queue_node;

    return head;
}

//member *find_queue_data (custom_queue *head, void *finding_data, enum queue_request request)
void *find_queue_data (custom_queue *head, void *finding_data, enum queue_request request)
{
    custom_queue *tmp = head;
    member *finding_member;
    char *finding_member_id;
    int finding_product_unique_id;
    int finding_member_id_length;

    if (!head) { return NULL; }

    switch (request)
    {
        case MEMBER_REQUEST:
            finding_member = (member *)finding_data;
            finding_member_id_length = strlen(finding_member->id);
            int finding_member_password_length = strlen(finding_member->password);

            while (tmp)
            {
                member *current_node_member = (member *)tmp->data;

                if (!strncmp(finding_member->id, current_node_member->id, finding_member_id_length))
                {
                    if (!strncmp(finding_member->password, current_node_member->password, finding_member_password_length))
                    {
                        return finding_member;
                    }
                }

                tmp = tmp->link;
            }

            printf("일치하는 회원이 존재하지 않습니다\n");
            return NULL;

        case MEMBER_FIND_BY_ID:
            finding_member_id = (char *)finding_data;
            finding_member_id_length = strlen(finding_member_id);

            while (tmp)
            {
                member *current_node_member = (member *)tmp->data;

                if (!strncmp(finding_member_id, current_node_member->id, finding_member_id_length))
                {
                    return current_node_member;
                }

                tmp = tmp->link;
            }

            printf("일치하는 회원이 존재하지 않습니다\n");
            return NULL;

        case PRODUCT_REQUEST:
            finding_product_unique_id = *((int *)finding_data);

            while (tmp)
            {
                product *current_node_product = (product *)tmp->data;

                if (finding_product_unique_id == current_node_product->unique_value)
                {
                    return current_node_product;
                }

                tmp = tmp->link;
            }

            printf("일치하는 상품이 존재하지 않습니다\n");
            return NULL;

        case PRODUCT_FINDING_REQUEST:
            //int finding_product_idx = *((int *) finding_data);
            break;
        
        default:
            break;
    }

    
}

void print_queue_data(custom_queue *head, enum queue_request request)
{
    custom_queue *tmp = head;
    product *finding_product;

    while (tmp) {
        switch (request) {
            case PRODUCT_REQUEST:
                finding_product = (product *) tmp->data;
                print_product(finding_product);
                break;

            default:
                break;
        }

        tmp = tmp->link;
    }
}
