#include"ch8.h"

static int x1 = 0,x2;
int y;
int main()
{
	int x3 = 0xffffffff,x4;
	static int x5 = 0x11111111;
	int a[10];
	int *pt= NULL;
	int i =1;
	printf("address of y: %x\n",&y);
	printf("address of x1:%x,x2:%x\n",(unsigned int)&x1,(unsigned int)&x2);
	printf("address of x3:%x,x4:%x\n",(unsigned int)&x3,(unsigned int)&x4);
	printf("address of x5:%x,a:%x\n",(unsigned int)&x5,(unsigned int)a);

	while(1)
	{
		int *pt = (int *)malloc(1024*i*sizeof(int));
		i++;
		if(pt!=NULL)
		{
			printf("%dKB",4*i);
		}
		else break;
	}
	//printf("address of pt : %x\n",i*1024);
	return 0;
}
