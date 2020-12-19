#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<dlfcn.h>
#include<setjmp.h>
#include"errno.h"
#include<time.h>
#include<ctype.h>

#define SERVER_FIFO_NAME  "./server_fifo"
#define  CLIENT_FIFO_NAME  "./client_%d_fifo"
#define  BUFFER_SIZE  132

#define PIPE_BUF  100
#define FIFO_FILE  "./testfifo"
#define TEN_MSG 1000
#define INFILE "./in.txt"
#define OUTFILE "./out.txt"
#define MODE S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH

struct data_to_pass
{
	pid_t  client_pid;
	char  data[BUFFER_SIZE];
};

void err_exit( char *s)
{
	printf("USAGE : *s is failed!\n");
	exit(1);
}
