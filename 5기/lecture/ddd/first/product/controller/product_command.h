#ifndef __PRODUCT_COMMAND_H__
#define __PRODUCT_COMMAND_H__

enum product_command
{
    PRODUCT_REGISTER,
    PRODUCT_LIST,
    PRODUCT_END
};

#define PRODUCT_CALL_BUFFER_COUNT          (PRODUCT_END)
#define PRODUCT_CALL_BUFFER                ((PRODUCT_END) - 1)

void print_product_command (void);
int input_user_product_command (void);

#endif
