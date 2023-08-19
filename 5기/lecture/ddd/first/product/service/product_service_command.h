#ifndef __PRODUCT_SERVICE_COMMAND_H__
#define __PRODUCT_SERVICE_COMMAND_H__

enum product_service_command
{
    PRODUCT_REGISTER_SERVICE,
    PRODUCT_LIST_SERVICE,
    END
};

#define PRODUCT_SERVICE_CALL_BUFFER_COUNT          (END)
#define PRODUCT_SERVICE_CALL_BUFFER                ((END) - 1)

#endif
