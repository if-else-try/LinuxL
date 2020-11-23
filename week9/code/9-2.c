#include"./ch9.h"

int g = 1;
int main()
{

	pid_t pid;
	int l  = 99;
	int *pt = (int *)malloc(sizeof(int));
	char *string  = "test strring";

	
	*pt = 9999;
	printf("%d----------------Before Fork ------------------",getpid());
	pid = fork();

	if(pid < 0)
	{
		sprintf(stderr,"failed",strerror(errno));

		exit(-1);
	}

	else if(pid == 0)
	{
	
		printf("child : pid = %d ,ppid = %d  eturn from fork() = %d\n",getpid(),getppid(),pid);
		printf("child : init g = %d,l = %d,*pt = %d\n",g,l,*pt);
		g++;
		l++;
		*pt++;
		printf("child : g =%d  %x,l = %d   %x,*pt = %d  %x\n",g,&g,l,&l,*pt,pt);
		printf("child : string = %s \n",string);
		exit(0);
	}
	else
	{
		sleep(2);
		printf("pareent : pid = %d, ppid = %d return from fork() = %d\n",getpid(),getppid(),pid);
		 printf("parent : init g = %d,l = %d,*pt = %d\n",g,l,*pt);
		 g++;
		 l++;
		 *pt++;
		 printf("parent : g = %d %x,l = %d   %x,*pt = %d  %x\n",g,&g,l,&l,*pt,pt);
		printf("parent : string = %s\n",string);
	}
	return 0;
}
