#include "rf_receiver.h"

#include "../../utility/custom_random_int/custom_random_int.h"

void initialize_rf_receiver(rf_receiver *rf_receiver)
{
    initialize_random();
}

void listen_rf_receiver(rf_receiver *rf_receiver) { }

void register_current_rf_receiver(const rf_receiver *rf_receiver)
{
    rf_receiver_p = rf_receiver;
}

void fill_randomdata_on_rf_receiver(rf_receiver *rf_receiver)
{
    // 랜덤 값을 만들어서 데이터를 채운다
    int data = generate_random_int_within_specific_range(MIN_NUMBER_OF_RF_RECEIVER, MAX_NUMBER_OF_RF_RECEIVER);

    rf_receiver->data = data;
}

int get_data_from_rf_receiver(const rf_receiver rf_receiver)
{
   return rf_receiver.data;
}