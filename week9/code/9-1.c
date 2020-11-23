#include"./ch9.h"


int main()
{

	pid_t pid;
	pid = fork();

	if(pid < 0)
	{
		sprintf(stderr,"failed",strerror(errno));

		exit(-1);
	}

	else if(pid == 0)
	{
	printf("child : pid = %d ,ppid = %d  eturn from fork() = %d\n",getpid(),getppid(),pid);
	exit(0);
	}
	else
	{
		printf("pareent : pid = %d, ppid = %d return from fork() = %d\n",getpid(),getppid(),pid);
	}
	return 0;
}
