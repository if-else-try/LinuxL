#include"ch12.h"

int main()
{
	int fd1[2],i,fd2[2];
	int j;
	pid_t k;
	char buf[25];
	memset (buf,0,sizeof(buf));
	
	if((pipe(fd1)) < 0)
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
		close(fd1[1]);
		close(fd2[0]);
		i = read(fd1[0],buf,sizeof(buf));
		if(i <= 0)
		{
			printf("chilld received failed!\n");
		}
		else
		{
			fprintf(stdout,"child %d receive %s from parent ! total = %ld\n",getpid(),buf,strlen(buf));
			
		}
		sprintf(buf,"%d say hello to %d\n",getpid(),k);
		write(fd2[1],buf,sizeof(buf));
		printf("%d : %s\n",getpid(),buf);
		close(fd1[0]);
		close(fd2[1]);
		
		
		exit(0);
		
		}
	else
		{
		close(fd2[1]);
		close(fd1[0]);
		sprintf(buf,"parent %d send to child %d",getpid(),k);
		i =write(fd1[1],buf,sizeof(buf));
		if(i> 0)
			printf("parent %d send success!\n",getpid());
		read(fd2[0],buf,sizeof(buf));
		printf("%d : %s\n",getpid(),buf);
			
		wait(NULL);
		close(fd1[1]);
		close(fd2[0]);
		
		return 0;
	}
	
	
	
}
