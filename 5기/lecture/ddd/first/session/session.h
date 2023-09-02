#ifndef __SESSION_H__
#define __SESSION_H__

typedef struct _session session;
struct _session
{
    // 원래는 UUID 토큰이 더 좋음
    char session_id[32];
};

extern struct _session session_object;

session *init_session (char *id);
// TODO: 야매라 없애야함 (급조)
int find_unique_id_from_session (void);

#endif
