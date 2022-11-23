#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MEMBER_STRING_MAX_LENGTH   50

// 파일 분할 했더라면 static 키워드를 붙였을 것임
int allocated_member_structure_count = 0;
int allocated_member_handler_structure_count = 0;

typedef struct _member member;
typedef struct _member_method_table member_method_table;

struct _member
{
    char *name;
    int age;
    char *phone_number;
    char *residence;

    member_method_table *tbl;
};

struct _member_method_table
{
    // 첫 번째 매개변수는 파이썬 클래스를 설계할 때 붙는 self를 생각해서 정함
    void (* set_member)(member *, char *, int, char *, char *);
    void (* print_member)(member *);
    void (* free_member)(member *);
};

// 프로퍼티를 설정하는 set_member
void set_member(member *mem, char *_name, int _age, char *_phone_number, char *_residence)
{
    int str_len;

    // 깊은 복사
    str_len = strlen(_name);
    mem->name = (char *)malloc(sizeof(char) * (str_len + 1));
    
    if (mem->name == NULL)
    {
        printf("member 구조체의 set_member 함수에서 name 동적할당 실패!\n");
        exit(-1);
    }
    strncpy(mem->name, _name, str_len);
    mem->name[str_len] = '\0';

    // 깊은 복사
    str_len = strlen(_phone_number);
    mem->phone_number = (char *)malloc(sizeof(char) * (str_len + 1));

    if (mem->phone_number == NULL)
    {
        printf("member 구조체의 set_member 함수에서 phone_number 동적할당 실패!\n");
        exit(-1);
    }
    strncpy(mem->phone_number, _phone_number, str_len);
    mem->phone_number[str_len] = '\0';

    // 얕은 복사
    mem->age = _age;

    // 깊은 복사
    str_len = strlen(_residence);
    mem->residence = (char *)malloc(sizeof(char) * (str_len + 1));

    if (mem->residence == NULL)
    {
        printf("member 구조체의 set_member 함수에서 residence 동적할당 실패!\n");
        exit(-1);
    }
    strncpy(mem->residence, _residence, str_len);
    mem->residence[str_len] = '\0';
}

void print_member(member *mem)
{
    printf("회원 이름: %s\n", mem->name);
    printf("나이: %d\n", mem->age);
    printf("전화번호: %s\n", mem->phone_number);
    printf("거주지: %s\n", mem->residence);
}

void free_member(member *mem)
{
    if (allocated_member_structure_count == 1)
    {
        free(mem->tbl);
    }

    free(mem->residence);
    free(mem->phone_number);
    free(mem->name);
    free(mem);
    mem = NULL;

    allocated_member_structure_count--;
}

member *allocate_memeber(void)
{
    static member_method_table *tbl = NULL;
    member *mem = (member *)malloc(sizeof(member));

    if (mem == NULL)
    {
        printf("member 동적할당 실패!\n");
        exit(-1);
    }

    if (allocated_member_structure_count == 0)
    {
        tbl = (member_method_table *)malloc(sizeof(member_method_table));

        if (tbl == NULL)
        {
            printf("member_method_table 동적할당 실패!\n");
            exit(-1);
        }

        tbl->set_member = set_member;
        tbl->print_member = print_member;
        tbl->free_member = free_member;
    }
    mem->tbl = tbl;
    allocated_member_structure_count++;

    return mem;
}

// member의 구조체 변수를 저장 및 관리하기 위한 구조체
typedef struct _member_handler member_handler;
typedef struct _member_handler_method_table member_handler_method_table;

struct _member_handler
{
    member_handler_method_table *tbl;

    member *member_array[0];
};

struct _member_handler_method_table
{
    void (* set_members)(member_handler *, int);
    void (* print_members)(member_handler *, int, bool (* fp)(member *));
    void (* free_members)(member_handler *, int);
};

void set_members(member_handler *mem_handler, int len)
{
    int i;
    char str[3][MEMBER_STRING_MAX_LENGTH];
    int age;

    for (i = 0; i < len; i++)
    {
        mem_handler->member_array[i] = allocate_memeber();

        printf("\n회원 정보를 입력해주세요!\n");
        
        printf("회원 이름: ");
        scanf("%s", str[0]);

        printf("나이: ");
        scanf("%d", &age);

        printf("전화번호: ");
        scanf("%s", str[1]);

        printf("거주지: ");
        scanf("%s", str[2]);

        mem_handler->member_array[i]->tbl->set_member(mem_handler->member_array[i], str[0], age, str[1], str[2]);
    }
}

void print_members(member_handler *mem_handler, int len, bool (* fp)(member *))
{
    int i;
    
    for (i = 0; i < len; i++)
    {
        // 인자로 받은 fp 함수로 출력하고자 하는 member를 선별
        if (fp(mem_handler->member_array[i]))
        {
            mem_handler->member_array[i]->tbl->print_member(mem_handler->member_array[i]);
        }
    }
}

void free_members(member_handler *mem_handler, int len)
{
    int i;

    // 어차피 handler는 하나만 생성할 것이긴 하지만 유지보수성을 생각하며 작성했다
    if (allocated_member_handler_structure_count == 1)
    {
        free(mem_handler->tbl);
    }

    for (i = 0; i < len; i++)
    {
        mem_handler->member_array[i]->tbl->free_member(mem_handler->member_array[i]);
    }
    
    free(mem_handler);
    mem_handler = NULL;

    allocated_member_handler_structure_count--;
}

member_handler *allocate_member_handler(int len)
{
    static member_handler_method_table *tbl = NULL;
    member_handler *mem_handler = (member_handler *)malloc(sizeof(mem_handler) + sizeof(member *) * len);

    if (mem_handler == NULL)
    {
        printf("member_handler 동적할당 실패!\n");
        exit(-1);
    }

    if (allocated_member_handler_structure_count == 0)
    {
        tbl = (member_handler_method_table *)malloc(sizeof(member_handler_method_table));

        if (tbl == NULL)
        {
            printf("member_handler_method_table 동적할당 실패!\n");
            exit(-1);
        }

        tbl->set_members = set_members;
        tbl->print_members = print_members;
        tbl->free_members = free_members;
        
    }
    mem_handler->tbl = tbl;
    allocated_member_handler_structure_count++;

    return mem_handler;
}

bool teens(member *);
bool twenty(member *);
bool thirty(member *);

int main(void)
{
    int num;

    printf("몇 명의 회원을 관리하시겠습니까? ");
    scanf("%d", &num);

    member_handler *mem_handler = allocate_member_handler(num);

    mem_handler->tbl->set_members(mem_handler, num);

    printf("\n*10대 출력*\n");
    mem_handler->tbl->print_members(mem_handler, num, teens);

    printf("\n*20대 출력*\n");
    mem_handler->tbl->print_members(mem_handler, num, twenty);

    printf("\n*30대 출력*\n");
    mem_handler->tbl->print_members(mem_handler, num, thirty);

    // 만약 전부를 출력하고 싶다면, true 값을 반환하는 함수를 작성하면 됨

    mem_handler->tbl->free_members(mem_handler, num);

    return 0;
}

// 연령별로 bool 값을 반환하는 함수
// 10대
bool teens(member *mem)
{
    return ((mem->age / 10) == 1) ? true : false;
}

// 20대
bool twenty(member *mem)
{
    return ((mem->age / 10) == 2) ? true : false;
}

// 30대
bool thirty(member *mem)
{
    return ((mem->age / 10) == 3) ? true : false;
}