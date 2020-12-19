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
void err_exit( char *s)
{
	printf("USAGE : *s is failed!\n");
	exit(1);
}

int gettime()
{
	unsigned long long a = 0;
    char timeStr[14];
 
 
    time_t timer;
    struct tm *tblock;
    time(&timer);
    tblock = gmtime(&timer);
 
 
    a = (tblock->tm_year+1900)*100;
    a = (a+tblock->tm_mon+1)*100;
    a = (a+tblock->tm_mday)*100;
    a = (a+tblock->tm_hour+8)*100;
    a = (a+tblock->tm_min)*100;
    a = (a+tblock->tm_sec);
    sprintf(timeStr, "%llu", a);
    
    printf("时间是a = %llu\n", a);
    //printf("timeStr = %s\n", timeStr);
    return 0;
}
