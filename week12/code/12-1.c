#include"ch12.h"

int main()
{
	int fd[2],i;
	int j;
	pid_t k;
	char buf[25];
	memset (buf,0,sizeof(buf));
	if((pipe(fd)) < 0)
	{
		perror("pipe failed!\n");
		exit(-1);
	}
	
	k = fork();
	
	if(k<0)
	{
		perror("pipe failed!\n");
		exit(-1);
	
	}
	else if(k == 0)
	{
		close(fd[1]);
		i = read(fd[0],buf,sizeof(buf));
		if(i <= 0)
		{
			printf("chilld received failed!\n");
		}
		else
		{
			fprintf(stdout,"child %d receive %s from parent ! total = %ld\n",getpid(),buf,strlen(buf));
			
		}
		close(fd[0]);
		exit(0);
		
		}
	else
		{
		close(fd[0]);
		sprintf(buf,"parent %d send to child %d",getpid(),k);
		i =write(fd[1],buf,sizeof(buf));
		if(i> 0)
			printf("parent %d send success!\n",getpid());
			
		wait(NULL);
		close(fd[1]);
		return 0;
	}
	
	
	
}
