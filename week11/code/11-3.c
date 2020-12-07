#include"ch11.h"

int main()
{
 pid_t pid1;
 pid_t pid2;
 pid1 = fork();
 if(pid1<0)
 {
 	perror("fork pid error!\n");
 	exit(-1);
 }
 else if(pid1 == 0)
 {
 	printf("child :pid = %d,ppid = %d\n",getpid(),getppid());
 	exit(88);
 }
 else {
 
 	int s1,r1,s2,r2;

 	r1 = wait(&s1);
 	r2 = wait(&s2);
 	if(r1 == pid1)
 	{
 		printf(" parent wait for child %d : exit  code %d\n",r1,WEXITSTATUS(s1));
 		
 	}
 	else
 	{
 		printf(" parent wait for child %d : exit  code %d\n",r1,WEXITSTATUS(s1));
 	}
 	if(r2 == pid2)
 	{
 		printf(" parent wait for child %d : exit  code %d\n",r2,WEXITSTATUS(s1));
 	}
 	else
 	{
 		printf(" parent wait for child %d : exit  code %d\n",r2,WEXITSTATUS(s2));
 	}
 	
 	return 0;
 }
}
