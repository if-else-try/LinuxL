#include"./ch9.h"

int main()
{

	pid_t i;
	i= vfork();
	if(i<0)
	{
		perror("Failed \n");
		exit(0);
	
	}
	else if(i==0)
	{
	
		printf("child : pid = %d,ppid = %d, i  = %d\n",getpid(),getppid(),i);
		_exit(0);
		//return 0;
	}
	else
	{
		wait(NULL);
		printf("parent : pid = %d,ppid = %d,\n",getpid(),getppid());
		return 0;
	}

}
