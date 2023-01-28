#include "rf_receiver.h"

#include "../../utility/custom_random_int/custom_random_int.h"

void initialize_rf_receiver(rf_receiver *rf_receiver) { }

void listen_rf_receiver(rf_receiver *rf_receiver) { }

void register_current_rf_receiver(const rf_receiver *rf_receiver)
{
    rf_receiver_p = rf_receiver;
}

int get_data_from_rf_receiver(const rf_receiver rf_receiver)
{
    // 랜덤 값을 만들어서 데이터를 내어준다 - start
    initialize_random();
    int data = generate_random_int_within_specific_range(MIN_NUMBER_OF_RF_RECEIVER, MAX_NUMBER_OF_RF_RECEIVER);

    return data;
    // - end

    // return rf_receiver.data;
}