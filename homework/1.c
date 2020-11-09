#include<stdio.h>
#include<limits.h>

int main()
{

	int x = 0x7fffffff;
	printf("最大int型：%d\n",x);

	int y = 0x80000000;
	printf("最小int型：%d\n",y);

	unsigned int z = 0xffffffff;
	printf("最大unsigned型：%u\n",z);

	float f1 ;
	char * p = (char *)&f1;

	*p=0xff;
	*(p+1)=0xff;
	*(p+2)=0x7f;
	*(p+3)=0x7f;

	printf("最大float:%f\n",f1);


	float f2;
	char *q = (char *)&f2;

	*q = 0xff;
	*(q+1) = 0xff;
	*(q+2) = 0x7f;
	*(q+3) = 0xff;

	printf("最小float:%f\n",f2);


	double d1;
	char *m = (char *)&d1;

	*m = 0xff;
	*(m+1) = 0xff;
	*(m+2) = 0xff;
        *(m+3) = 0xff;
        *(m+4) = 0xff;	
	*(m+5) = 0xff;
	*(m+6) = 0xef;
	*(m+7) = 0x7f;

	printf("最大double:%lf\n",d1);

	double d2;
        char *n = (char *)&d2;

        *n = 0xff;
        *(n+1) = 0xff;
        *(n+2) = 0xff;
        *(n+3) = 0xff;
        *(n+4) = 0xff;
        *(n+5) = 0xff;
        *(n+6) = 0xef;
        *(n+7) = 0xff;

        printf("最大double:%lf\n",d2);
}
