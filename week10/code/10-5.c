#include"./ch10.h"

int main()
{
 	int r;
	printf("10-5 : pid = %d, ppid = %d\n",getpid(),getppid());
	system("./test hello world 11 23 \n");
		if(r == -1)
		{
			perror("execl failed!\n");
			exit(-1);
		}
	printf("After calling\n");
	return 0;
}
