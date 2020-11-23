#include"ch8.h"

static int g = 0,k;
int fun(int g)
{
	int *p = (int *)malloc(1);
	printf("fun :address p = %x\n",p);
	g++;
	printf("g = %d\n",g*4);
	if( !p)
	{
		printf("Failed\n");
                exit(-1);
		
	}
	else
	{
		printf("g = %d\n",g);
                return fun(g);
	}

}
int main()
{
	/*
	int i =0 ,j=0,a[10]={1};
	static int w =100;
	int *pt = (int *)malloc(sizeof(int)*10);
	printf("address of g = %x,k=%x\n",&g,&k);
	printf("address of i = %x,j = %x,a = %x\n",&i,&j,a);
	printf("address of w = %x\n",&w);
	printf("address of pt = %x\n",pt);
	fun();
	return 0;
	*/
	fun(g);
	return 0;
}	
