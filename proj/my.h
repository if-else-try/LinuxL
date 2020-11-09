#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
#include<stdlib.h>

typedef struct user{
int id;
char name[8];
char htel[12];
char tel[12];

} recorder;

recorder * pt;
recorder* input(void);
int save(recorder * ptr);
int mysort(recorder * ptr);
