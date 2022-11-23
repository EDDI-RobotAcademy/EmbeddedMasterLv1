#define MENU_MIN    1
#define MENU_MAX    5

#define STRING_MAX_LENGH    20

#define COMMAND_PRINTF_10S  1
#define COMMAND_PRINTF_20S  2
#define COMMAND_PRINTF_30S  3
#define COMMAND_PRINTF_ALL  4
#define COMMAND_ADD_MEMBER  5



#define AGE_CONDITION_10S    ( (10 < mem_handler.mem_array[i].age) && (mem_handler.mem_array[i].age < 19) )
#define AGE_CONDITION_20S    ( (20 < mem_handler.mem_array[i].age) && (mem_handler.mem_array[i].age < 29) )
#define AGE_CONDITION_30S    ( (30 < mem_handler.mem_array[i].age) && (mem_handler.mem_array[i].age < 39) )


typedef struct _member  member;
typedef struct _member_handler_method_table     member_handler_method_table;
typedef struct _member_handler  member_handler;

struct _member
{
    char* name;
    int age;
    char* address;
    char* phone_number;
    int member_id;

    member_handler_method_table *tbl;
};

struct _member_handler_method_table
{
    void (* print_member)(member_handler *mem_handler, int command);
    member* (* add_member)(member_handler *mem_handler);
    void (* menu_select)(member_handler *mem_handler);
};

struct _member_handler
{
    member *mem_array[0];
    int max_member_number;
    int add_member_cnt;

    member_handler_method_table *tbl;
};