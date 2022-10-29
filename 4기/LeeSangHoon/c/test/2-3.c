#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void malloc_type_call_string_handler (void *control_data);
void malloc_type_call_integer_handler (void *control_data);

enum malloc_type {
	STRING,
	INTEGER,
    END
};

#define MALLOC_TYPE_BUFFER_COUNT		(END)
#define MALLOC_TYPE_BUFFER				((END) - (1))

typedef void (* malloc_type_call_ptr_t) (void *);

void malloc_type_not_impl(void)
{
    printf("아직 구현되지 않은 스펙입니다!\n");
}

const malloc_type_call_ptr_t malloc_type_call_table[MALLOC_TYPE_BUFFER_COUNT] = {
	malloc_type_call_string_handler,
	malloc_type_call_integer_handler
};

#define ACCOUNT_REGISTER_SUCCESS		1
#define ACCOUNT_REGISTER_FAILURE		0

#define ACCOUNT_ALLOC_SUCCESS			1
#define ACCOUNT_ALLOC_FAILURE			0

#define SLAB_CACHE_SIZE					64

typedef struct _account account;

struct _account
{
	char *name;
	int age;
	char *phone_number;
	char *city;
};

typedef struct _malloc_type_data malloc_type_data;

struct _malloc_type_data
{
	int data_size;
	int type;
	void **control_object;
	char data[0];
};

void malloc_type_call_string_handler (void *control_data)
{
	malloc_type_data *data = (malloc_type_data *)control_data;
	int data_size = data->data_size;

	*data->control_object = (char *)malloc(sizeof(data_size) + 1);
	strncpy(*data->control_object, data->data, data_size);
}

void malloc_type_call_integer_handler (void *control_data)
{
	malloc_type_data *data = (malloc_type_data *)control_data;
	int data_size = data->data_size;

	*data->control_object = *data->data;
}

malloc_type_data *init_malloc_type_data (void **control_object, int type, void *data)
{
	int data_length;
	malloc_type_data *obj;

	if (type == STRING)
	{
		data_length = strlen(data);
		obj = (malloc_type_data *)malloc(sizeof(malloc_type_data) + data_length + 1);

		obj->type = STRING;
		obj->data_size = data_length;
		strncpy(obj->data, data, data_length);
	}
	else if (type == INTEGER)
	{
		int real_data = atoi(data);
		obj = (malloc_type_data *)malloc(sizeof(malloc_type_data) + sizeof(int) * 2);
		obj->type = INTEGER;
		obj->data_size = sizeof(int);
		*obj->data = real_data;
	}
	obj->control_object = control_object;

	return obj;
}

void insert_data(char *string, char **obj, int type)
{
	malloc_type_data *malloc_type;
	char message_buffer[SLAB_CACHE_SIZE] = { 0 };
	char user_buffer[SLAB_CACHE_SIZE] = { 0 };

	strcpy(message_buffer, string);
	write(1, message_buffer, strlen(message_buffer));
	read(0, user_buffer, SLAB_CACHE_SIZE);

	malloc_type = init_malloc_type_data(obj, type, user_buffer);

	malloc_type_call_table[type](malloc_type);
	free(malloc_type);
}

int init_account(account **account_obj)
{
	*account_obj = (account *)malloc(sizeof(account));

	insert_data("이름을 입력하세요: ", &(*account_obj)->name, STRING);
	printf("account_obj->name = %s", (*account_obj)->name);

	insert_data("나이를 입력하세요: ", &(*account_obj)->age, INTEGER);
	printf("accout_obj->age = %d\n", (*account_obj)->age);

	insert_data("전화 번호를 입력하세요: ", &(*account_obj)->phone_number, STRING);
	printf("account_obj->phone_number = %s", (*account_obj)->phone_number);

	insert_data("도시를 입력하세요: ", &(*account_obj)->city, STRING);
	printf("account_obj->phone_number = %s", (*account_obj)->city);

	return ACCOUNT_ALLOC_SUCCESS;
}

int register_account_info(account **account_obj)
{
	if (init_account(account_obj) == ACCOUNT_ALLOC_FAILURE)
	{
		printf("계정 정보 입력 실패\n");
		exit(-1);
	}

	return ACCOUNT_REGISTER_SUCCESS;
}

// 자료구조를 사용하면 더 좋으나 풀이가 길어지고 Lv1 교육 범주를 벗어남
void print_account_with_age_band(account *account_obj)
{
	int age = account_obj->age / 10;

	switch (age)
	{
		case 0:
			printf("0 ~ 9세\n");
			break;

		case 1:
			printf("10 ~ 19세\n");
			break;

		case 2:
			printf("20 ~ 29세\n");
			break;

		case 3:
			printf("30 ~ 39세\n");
			break;

		case 4:
			printf("40 ~ 49세\n");
			break;

		case 5:
			printf("50 ~ 59세\n");
			break;

		case 6:
			printf("60 ~ 69세\n");
			break;

		case 7:
			printf("70 ~ 79세\n");
			break;

		case 8:
			printf("80 ~ 89세\n");
			break;

		case 9:
			printf("90 ~ 99세\n");
			break;
	}
}

int main (void)
{
	account *account_obj;

	if (register_account_info(&account_obj) == ACCOUNT_REGISTER_FAILURE)
	{
		printf("계정 생성 실패\n");
		exit(-1);
	}

	print_account_with_age_band(account_obj);

	free(account_obj);

	return 0;
}
