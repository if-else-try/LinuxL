#include"../ch8.h"

void dynamic_lib_fun_call(void)
{
	printf("Dynamic Lib Fun Called\n");
}

void mysort(void)
{
	int n,i,j,t,a[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i = 0 ;i<n-1;i++)
	{
		for(j = i+2;j<n;j++)
		{
			if(a[i]>a[j])
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}

	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
}
