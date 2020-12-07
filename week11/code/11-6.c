#include<stdio.h>
#include<time.h>
#include<stdint.h>
#include<stdlib.h>
 
int main()
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
 
    printf("现在时间是 %d 年 %d 月 %d 日 %d 时 %d 分 %d 秒.\n",\
            tblock->tm_year+1900, tblock->tm_mon+1, tblock->tm_mday,\
            tblock->tm_hour+8, tblock->tm_min, tblock->tm_sec);
 
    printf("a = %llu\n", a);
    printf("timeStr = %s\n", timeStr);
    return 0;
}
