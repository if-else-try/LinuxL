#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<dlfcn.h>
void err_exit( char *s)
{
	printf("USAGE : *s is faile!\n");
	exit(1);
}
