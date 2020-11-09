#include"stdio.h"
#include"stdlib.h"

static void __attribute__ ((constructor)) before_main()
{
	printf("Before\n");
}
static void __attribute__ ((destructor)) after_main()
{
        printf("after\n");
}

static void callback1(void)
{

printf("----CalllBack1\n");
}
static void callback2(void)
{
printf("----CallBack2\n");
}
static void callback3(void)
{
printf("----CallBack3\n");
}

int main()
{
	printf("Main");
	atexit(callback1);
	atexit(callback2);
	atexit(callback3);
	while(1)
	{
		sleep(10);
	}
//printf("buffer");
exit(0);

}
