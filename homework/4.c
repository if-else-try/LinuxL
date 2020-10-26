

#include<stdio.h>
#include "ch03.h"

int main(int argc,char**argv){
	int fd;
	int count;
	char buf[5];
	char*data;
	int i,length,n_length;
	length=0;
	n_length=0;
	if(argc!=2)
		err_exit("参数错误\n");

	if((fd = open("./test.txt",O_RDONLY,0644))<0)
		err_exit("open error!\n");
	int n = atoi(argv[1]);
	read(fd,&buf,4);
	count = atoi(buf);
	if(count<n||n<=0)
		err_exit("越界！\n");
	for(i=0;i<n-1;i++){
		lseek(fd,4*(i+1),SEEK_SET);
		read(fd,&buf,4);
		length+=atoi(buf);
	}
	printf("count = %d\t length = %d\n",count,length);
	lseek(fd,n*4,SEEK_SET);
	read(fd,&buf,4);
	//第n条记录长度
	n_length = atoi(buf);
	printf("n_length = %d\n",n_length);
	data = (char*)malloc(sizeof(char)*n_length);	
	lseek(fd,(count+1)*4+length,SEEK_SET);

	read(fd,data,n_length);
	printf("%s\n",data);	
	return 0;
}
