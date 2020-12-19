#include"ch12.h"

int main()
{
	pid_t pid1,pid2;
	int fd1[2],i,fd2[2];
	int d1,d2;
	char buf[25];
	memset (buf,0,sizeof(buf));
	if((pipe(fd1))< 0 || (pipe(fd2)) < 0 )
	{
		perror("pipe failed!\n");
		exit(-1);
	}
	pid1 = fork();
	if(pid1 < 0)
	{
		perror("fork failed\n");
		exit(-1);
	}
	else if(pid1 == 0)
	{
		close(fd1[0]);
		close(fd2[1]);
		d1 = open("./out.dat",O_RDWR);
		dup(d1);
		sprintf(buf,"%d :  %dsay hello \n ",getppid(),getpid());
		write(fd1[1],buf,sizeof(buf));
		sleep(1);
		read(fd2[0],buf,sizeof(buf));
		printf("%d : %s\n",getppid(),buf);
		//execl("./12-5.c",NULL);
		exit(0);
	}
	else 
	{
		
	pid2 = fork();
	if(pid2 < 0)
	{
		perror("fork2 failed\n");
		exit(-1);
	}
	else if(pid2 == 0)
	{
		close(fd1[1]);
		close(fd2[0]);
		d2 = open("./out.dat",O_RDWR);
		//dup2(fd2[1],stdout);
		dup(d2);
		read(fd1[0],buf,sizeof(buf));
		sprintf(buf,"%d :  %d say ok \n ",getppid(),getpid());
		printf("%d : %s\n",getppid(),buf);
		write(fd2[1],buf,sizeof(buf));
		execl("./12-5.c",NULL);
		exit(0);
	}
	else
	{	
		close(fd1[0]);
		close(fd1[1]);
		close(fd2[0]);
		close(fd2[1]);
		wait(NULL);
		wait(NULL);
		return 0;
	}
	}
}
