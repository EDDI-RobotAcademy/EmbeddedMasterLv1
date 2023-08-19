#include "session.h"

#include <string.h>

struct _session session_object = { };

session *init_session (char *id)
{
    strncpy(session_object.session_id, id, strlen(id));
}