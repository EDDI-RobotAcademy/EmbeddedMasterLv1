#include "member_repository_handler.h"
#include "../../data_structure/queue/queue.h"

#include "../../session/session.h"

#include <stdio.h>

struct _custom_queue *member_queue;

void member_save_repository (member *member_object)
{
    printf("member repository: save()\n");

    member_queue = enqueue_data(member_queue, member_object, MEMBER_REQUEST);
}

// TODO: 리팩토링이 필요한 영역
void member_find_by_id_repository (member *member_object)
{
    printf("member repository: find_by_id()\n");

    member *found_member = find_queue_data(member_queue, member_object, MEMBER_REQUEST);

    if (found_member) { init_session(found_member->id); }
}

void member_find_all_repository (member *member_object)
{
    printf("member repository: find_all()\n");
}