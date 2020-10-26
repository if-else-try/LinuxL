#include"ch2.h"


int main()
{
	int n,i,fd;
	char buf;
	fd = open("./test.data",O_CREAT|O_WRONLY,0644);

	for(int i=0;i<2;i++)
	{
		srand(time(0));
		n= rand()%26;
		buf = (char)('a'+n);
		printf("write1:%c\n",buf);
		write(fd,&buf,1);
		lseek(fd,10,SEEK_SET);
		sleep(70);
	}
	close(fd);
	return 0;
}
