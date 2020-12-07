#include"./ch10.h"

int main()
{
	pid_t pid;
	pid = fork();

	if(pid<0)
	{
		printf("error!\n");
		exit(-1);
	}
	else if(pid == 0)
	{
		printf("child is running\n");
	}
	else 
	{
		sleep(300);
		wait(NULL);
	}
	return 0;


}
