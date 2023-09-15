#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "queue_request.h"
#include "../../member/entity/member.h"

typedef struct _custom_queue custom_queue;
struct _custom_queue
{
    void *data;
    struct _custom_queue *link;
};

extern struct _custom_queue *member_queue;
extern struct _custom_queue *product_queue;

custom_queue *enqueue_data (custom_queue *head, void *data, enum queue_request request);
//member *find_queue_data (custom_queue *head, void *finding_data, enum queue_request request);
void *find_queue_data (custom_queue *head, void *finding_data, enum queue_request request);
void print_queue_data(custom_queue *head, enum queue_request request);
void print_queue_conditional_data(custom_queue *head, void *condition_data, enum queue_request request);

#endif
