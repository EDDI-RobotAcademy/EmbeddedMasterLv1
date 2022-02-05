#include <time.h>
#include <stdio.h>
#include <stdlib.h>

enum protocol
{
	CAMERA,
	DCMOTOR,
	BLDC,
	PMSM,
	ACIM,
	LED,
	I2C,
	SPI,
	CAN,
	ECAP
};

// void * 배열을 만들겠다는 의미
void **syscall_arr;

void proc_camera (void)
{
	printf("Camera Processing\n");
}

int proc_dc_motor (void)
{
	printf("DC Motor Processing\n");

	return 3;
}

void init_syscall_arr (void)
{
	// 실제로는 enum에서 길이값을 가져올 수 있게 설계해야
	// 어떤 상황에서든지 유연한 대처가 가능함
	// 우선은 그냥 진행
	syscall_arr = (void **)malloc(sizeof(void *) * 10);

	syscall_arr[CAMERA] = proc_camera;
	syscall_arr[DCMOTOR] = proc_dc_motor;
	syscall_arr[BLDC] = proc_camera;
	syscall_arr[PMSM] = proc_camera;
	syscall_arr[ACIM] = proc_camera;
	syscall_arr[LED] = proc_camera;
	syscall_arr[I2C] = proc_camera;
	syscall_arr[SPI] = proc_camera;
	syscall_arr[CAN] = proc_camera;
	syscall_arr[ECAP] = proc_camera;
}

void recv_command_from_pc (void)
{
	int command;
	int (*p2)(void);
	void (*p)(void);

	printf("명령이 들어온다 가정하고 진행(랜덤으로 만들기)!\n");

	command = rand() % 10;
	printf("수신된 명령: %d(가정 - 랜덤)\n", command);

	// 실제로는 위임자를 써야하며
	// 현재는 편의를 위해 상수를 박자!
	command = CAMERA;
	p = syscall_arr[command];
	p();

	command = DCMOTOR;
	p2 = syscall_arr[command];
	printf("모터 gain값: %d\n", p2());

#if 0
	// command가 수백개인 경우엔 ??? 지옥
	switch (command)
	{
		case ~~~
		~~~~
	}
#endif
}

int main (void)
{
	srand(time(NULL));

	init_syscall_arr();
	recv_command_from_pc();

	return 0;
}
