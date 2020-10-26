#include<stdio.h>

int main()
{

	FILE * fp;
	char buf[1];
	setvbuf(fp,buf,_IONBF,BUFSIZ);
	printf(" ");
	return 0;
}
