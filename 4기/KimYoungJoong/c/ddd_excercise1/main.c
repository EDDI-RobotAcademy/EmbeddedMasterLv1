/*1. RF 송수신기가 존재한다.

2. 송신기가 날리는 정보는 600 ~ 1400이라는 숫자값을 가지고 수신됩니다.

3. 수신기에는 총 8개의 채널이 존재합니다.

4. 실제로는 조종기측에서 무언가를 제어할 때 위의 수치값들이 바뀌지만

   이 부분은 고려하지 않고 랜덤 값으로 처리하겠습니다.

5. 각 채널들은 LED를 제어하기 위한 용도로 활용될 수도 있으며

   서보 모터나 DC 모터를 제어하는데 활용할 수도 있습니다.

6. 서보 모터는 500 ~ 2500의 범주를 가지고 있습니다.

7. DC 모터는 0 ~ 255의 범주를 가지고 있습니다.

8. 수신기가 각 채널별로 수신한 정보를 바탕으로 LED, 서보, DC 모터를 제어할 수 있도록

    Domain Driven Development 설계 원칙에 따라 백로그를 작성하고 프로그래밍을 합니다.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "rf_receiver/rf_receiver.h"


int main (void)
{
    int rf_transmit_signal;

    //custom_random generator
    while(1)
    {
        init_random_generator();
        rf_transmit_signal = random_generator_data();
        printf("rf_transmit_signal : %d\n", rf_transmit_signal);
    }

    return 0;
}