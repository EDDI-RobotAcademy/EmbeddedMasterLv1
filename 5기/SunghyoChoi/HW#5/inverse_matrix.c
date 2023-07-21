
#include <stdio.h>
#define size 2
unsigned int arr[size][size]={{4,1},{11,3}};

void conv_inv_matrix(void);
void print_matrix(unsigned int arr[][size]);


int main(void)
{
    print_matrix(arr);
    conv_inv_matrix();
    print_matrix(arr);
    return 0;
    printf("%p",arr);
}


void print_matrix(unsigned int arr[][size])
{
	for (int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}

void conv_inv_matrix(void)
{
	register unsigned int *r1 asm("r1")=NULL;
	register int r2 asm("r2")=0;
	register int r3 asm("r3")=0;
	register int r4 asm("r4")=0;
	register int r5 asm("r5")=0;
	register int r6 asm("r6")=0;
	register int r7 asm("r7")=0;
	int arr_1,arr_2,arr_3,arr_4,n=0;
	
	r1=&arr[0][0];
	
	asm volatile("ldr r2,[r1]");
	asm volatile("ldr r3,[r1,#0x8]");
	asm volatile("ldr r4,[r1,#0x4]");
	asm volatile("ldr r5,[r1,#0xc]");

	arr_1=r2;
	arr_2=r3;
	arr_3=r4;
	arr_4=r5;
	
	n=arr_1;
	arr_1=arr_4;
	arr_4=n;
	arr_2=-arr_2;
	arr_3=-arr_3;
	
	r2=arr_1;
   	r3=arr_2;
   	r4=arr_3;
   	r5=arr_4;
   	
    asm volatile("str r2,[r1]");
    asm volatile("str r3,[r1,#0x8]");
    asm volatile("str r4,[r1,#0x4]");
    asm volatile("str r5,[r1,#0xc]");
}

/*
#include <stdio.h>
#define size 2
unsigned int arr[size][size]={{4,1},{11,3}};

void conv_inv_matrix(void);
void print_matrix(unsigned int arr[][size]);


int main(void)
{
    //print_matrix(arr);
    conv_inv_matrix();
   // print_matrix(arr);
    return 0;
}


void print_matrix(unsigned int arr[][size])
{
	for (int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}

void conv_inv_matrix(void)
{
	register unsigned int (*r8)[2] asm("r8")=NULL;
	register int r2 asm("r2")=0;
	register int r3 asm("r3")=0;
	register int r4 asm("r4")=0;
	register int r5 asm("r5")=0;
	register int r6 asm("r6")=0;
	register int r7 asm("r7")=0;
	int arr_1,arr_2,arr_3,arr_4,n=0;	
	r8 = arr;
	
	asm volatile("ldr r2,[r8]");
	asm volatile("ldr r3,[r8, #0x8]");
	asm volatile("ldr r4,[r8, #0x4]");
	asm volatile("ldr r5,[r8, #0xc]");
	arr_1=r2;
	arr_2=r3;
	arr_3=r4;
	arr_4=r5;
	
	n=arr_1;
	arr_1=arr_4;
	arr_4=n;
	arr_2=-arr_2;
	arr_3=-arr_3;
	
	r2=arr_1;
   	r3=arr_2;
   	r4=arr_3;
   	r5=arr_4;
   	
    asm volatile("str r2,[r8]");
    asm volatile("str r3,[r8, #0x8]");
    asm volatile("str r4,[r8, #0x4]");
    asm volatile("str r5,[r8,#0xc]");
}
*/

