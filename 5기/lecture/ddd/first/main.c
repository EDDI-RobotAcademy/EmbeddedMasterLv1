#include <stdio.h>

#include "command/command.h"
#include "command/command_handler.h"
#include "command/command_call_table.h"

#include "data_structure/queue/queue.h"
#include "product/entity/product.h"

#include "product/service/request/product_request.h"
#include "product/repository/product_repository_handler.h"

struct _custom_queue *product_queue;

void main_command_controller (void);
void init_product_items (void);
void test_product_selection(void);

int main (void) {

    main_command_controller();
    return 0;
}

void main_command_controller (void)
{
    // 사업자 회원, 일반 회원 구분 안하므로 초기 product 값들은 하드코딩해서 고정시키도록 함
    // 구분하게 되면 훨씬 복잡해지고 우선은 Domain 개념과 Domain 협력 개념을 파악하는 것이 중요함
    init_product_items();
    //test_product_selection();

    while (!check_user_input_close())
    {
        print_basic_command();
        int command = input_user_command();
        command_call_table[command]();
    }
}

void init_product_items (void)
{
    product *registered_product[] = {
            init_product("상품1", 1000, "상품1 설명"),
            init_product("상품2", 10000, "상품2 설명"),
            init_product("상품3", 500, "상품3 설명"),
            init_product("상품4", 7777, "상품4 설명"),
            init_product("상품5", 100000, "상품5 설명"),
    };

    for (int i = 0; i < 5; i++) {
        product_queue = enqueue_data(product_queue, registered_product[i], PRODUCT_REQUEST);
    }
}

void test_product_selection(void)
{
    int find_product_request = 3;
    product_response *product_response_object = product_find_by_id_repository (&find_product_request);

    printf("product_response_object = 0x%x\n", product_response_object);
}