#include "session.h"

#include "../data_structure/queue/queue.h"

#include <string.h>

struct _session session_object;

session *init_session (char *id)
{
    strncpy(session_object.session_id, id, strlen(id - 1));
}

int find_unique_id_from_session (void)
{
    member *member_object = find_queue_data(member_queue,
                                            session_object.session_id,
                                            MEMBER_FIND_BY_ID);
    return member_object->unique_value;
}