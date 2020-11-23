#include"./ch9.h"

int g = 1;
int main()
{

	pid_t pid ,pid2;
	
	pid = fork();
	pid2 = fork();
	if(pid < 0)
	{
		sprintf(stderr,"failed",strerror(errno));

		exit(-1);
	}

	else if(pid == 0)
	{
	
		printf("child1 : pid = %d ,ppid = %d  return from fork() = %d\n",getpid(),getppid(),pid);
		exit(0);
		
	}
	else if(pid2 < 0)
	{
		sprintf(stderr,"failed",strerror(errno));

		exit(-1);
	}

	else if(pid2 == 0)
	{
	
		//printf("child2 : pid = %d ,ppid = %d  return from fork() = %d\n",getpid(),getppid(),pid);
		//exit(0);
		printf("child1 : pid = %d ,ppid = %d  return from fork() = %d\n",getpid(),getppid(),pid);
	}
	else
	{
		
		printf("parent : pid = %d, ppid = %d return from fork() = %d\n",getpid(),getppid(),pid);
		
	}
	return 0;
}
