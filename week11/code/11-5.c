#include"my.h"
int main()
{
	pid_t pid1;
	pid1=fork();
	if(pid1<0)
	{
		perror("fork pid error!\n");
		exit(-1);
	}else if(pid1==0)
	{

		printf("child1 pid=%d,ppid=%d\n",getpid(),getppid());
		
		int pid11;
		pid11 = fork();
		if(pid11 < 0 )
		{
			perror("fork pid error!\n");
			exit(-1);
		}
		else if(pid11 == 0)
		{
			printf("child11 pid=%d,ppid=%d\n",getpid(),getppid());
			
		}
		else
		{
			int s11,r11;
			r11=wait(&s11);
			if(WIFEXITED(s11))
			{
				printf("child1 wait for child11 %d : exit code %d\n",r11,WEXITSTATUS(s11));	
				gettime();	
			}
			else
			{
				if(WIFSIGNALED(s11))
				{
					printf("pid %d exit with signal %d\n",r11,WTERMSIG(s11));
				}
			}
		}
		exit(0);
	}else
	{
		int pid2;
		pid2=fork();
		if(pid2<0)
		{
			perror("pid2 fork failed!\n");
			exit(-1);
		}else if (pid2==0)
		{
			printf("child2 pid=%d,ppid=%d\n",getpid(),getppid());
			int pid21;
			pid21 = fork();
			if(pid21 < 0)
			{
				perror("pid21 fork failed!\n");
				exit(-1);
			}
			else if(pid21 == 0)
			{
				printf("child21 pid=%d,ppid=%d\n",getpid(),getppid());
				gettime();
			}
			else
			{
				int s21,r21;
				r21=wait(&s21);
				if(WIFEXITED(s21))
			{
				printf("child2 wait for child21 %d : exit code %d\n",r21,WEXITSTATUS(s21));	
				gettime();	
			}
			else
			{
				if(WIFSIGNALED(s21))
				{
					printf("pid %d exit with signal %d\n",r21,WTERMSIG(s21));
				}
			}
			}
			exit(0);

		}else
		{

			int s1,r1,s2,r2;
			r1=wait(&s1);
			r2=wait(&s2);
			//r1 = waitpid(pid2,&s1,0);
			//r2 = waitpid(pid1,&s2,0);
			if(WIFEXITED(s1))
			{
				printf("parent wait for child1 %d : exit code %d\n",r1,WEXITSTATUS(s1));	
				gettime();	
			}
			else
			{
				if(WIFSIGNALED(s1))
				{
					printf("pid %d exit with signal %d\n",r1,WTERMSIG(s1));
				}
			}

			if(WIFEXITED(s2))
			{
				printf("parent wait for child1 %d : exit code %d\n",r2,WEXITSTATUS(s2));	
				gettime();	
			}
			else
			{
				if(WIFSIGNALED(s2))
				{
					printf("pid %d exit with signal %d\n",r2,WTERMSIG(s2));
				}
			}
			printf("parent finished!\n");
			gettime();
			//return 0;
		}
	}
	/*int fd;
	if((fd = open("./log.dat",O_CREAT|O_WRONLY,0644)) == -1)
	{
		printf("Error to create file!\n");
		exit(1);
	}*/
	
	return 0;
}
