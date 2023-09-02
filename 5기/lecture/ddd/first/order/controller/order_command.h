#ifndef __ORDER_COMMAND_H__
#define __ORDER_COMMAND_H__

enum order_command
{
    ORDER_REGISTER,
    ORDER_LIST,
    ORDER_END
};

#define ORDER_CALL_BUFFER_COUNT          (ORDER_END)
#define ORDER_CALL_BUFFER                ((ORDER_END) - 1)

void print_order_command (void);
int input_user_order_command (void);

#endif
