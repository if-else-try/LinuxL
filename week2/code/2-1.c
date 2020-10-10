#include"ch2.h"
int main()
{
	int ret;
	printf("%d:2-1 is running",getpid());
	ret=write(1,"Hello World\n",13);
	sleep(100);
	exit(0);
}
