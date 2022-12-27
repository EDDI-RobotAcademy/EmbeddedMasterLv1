#ifndef __RF_RECEIVER_SERVICE_H__
#define __RF_RECEIVER_SERVICE_H__

enum rf_scale_method {
    RF_SCALE_DC_MOTOR,
    RF_SCALE_SERVO_MOTOR,
    RF_SCALE_LED,
    RF_SCALE_END
};

int rf_signal_scale2dc_motor (void);
int rf_signal_scale2servo_motor (void);
int rf_signal_scale2led (void);

typedef int (* rf_receive_data_scale_call_ptr_t)(void);

const rf_receive_data_scale_call_ptr_t rf_receive_data_scale_call_table[RF_SCALE_END] = {
        (rf_receive_data_scale_call_ptr_t const) rf_signal_scale2dc_motor,
        (rf_receive_data_scale_call_ptr_t const) rf_signal_scale2servo_motor,
        (rf_receive_data_scale_call_ptr_t const) rf_signal_scale2led
};



#endif
