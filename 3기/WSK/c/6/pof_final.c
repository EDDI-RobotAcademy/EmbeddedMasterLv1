#include <stdio.h>

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

int main (void)
{
	int test = CAMERA, test2 = ECAP;

	printf("test = %d\n", test);
	printf("test2 = %d\n", test2);

	return 0;
}
