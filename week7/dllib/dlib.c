#include"../ch7.h"

void dynamic_lib_call(void)
{
printf("Dynamic lib is called!\n");

}
void dsum(int m)
{
	int i;
	int k = 0;
	for(i = 1;i<=m;i++)
	{
		k+=i;
	}
	printf("和为:%d",k);
	
}
