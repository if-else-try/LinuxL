
#include<stdio.h>
#include "ch03.h"
int main(){
	int fd;
	char buf1[2]="ab";
	char buf2[5]="cdefg";
	char buf3[6]="123456";
	char buf4[9]="hijklmnop";
	if((fd = open("./test.txt",O_RDWR|O_CREAT,0644))==-1)
		err_exit("open!\n");
	write(fd,"4",1);
	lseek(fd,4,SEEK_SET);
	write(fd,"2",1);
	lseek(fd,8,SEEK_SET);
	write(fd,"5",1);
	lseek(fd,12,SEEK_SET);
	write(fd,"6",1);	
	lseek(fd,16,SEEK_SET);
	write(fd,"9",1);
	lseek(fd,20,SEEK_SET);
	
	write(fd,buf1,2);
	write(fd,buf2,5);
	write(fd,buf3,6);
	write(fd,buf4,9);
	
	return 0;
}
