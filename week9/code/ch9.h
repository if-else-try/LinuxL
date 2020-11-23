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


#define INFILE "./in.txt"
#define OUTFILE "./out.txt"
#define MODE S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH
void err_exit( char *s)
{
	printf("USAGE : *s is failed!\n");
	exit(1);
}
