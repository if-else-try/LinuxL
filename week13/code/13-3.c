#include"ch13.h"

int main()
{
	int fifo_fd,i,n,total_bytes = 0;
	char sendbuf[PIPE_BUF];
	if( (fifo_fd = open(FIFO_FILE,O_WRONLY))  < 0)
	{
		printf("Could  not  open  fifo  %s\n",FIFO_FILE);
		exit(EXIT_FAILURE);
	}
	printf("Process  %d opened :  %s\n",getpid(),FIFO_FILE);
	do{
		if((n  =  write(fifo_fd,sendbuf,PIPE_BUF)) == -1)
			err_exit("FIFO broken\n");
		printf("%d  write  %d  bytes\n",getpid(),n);
		total_bytes += n;
	}while(total_bytes < TEN_MSG);
	close(fifo_fd);
	printf("Process  %d  finished\n",getpid());
	return 0;
}
