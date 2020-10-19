#include"ch2.h"


int main()
{

	FILE * fp;
	int  fd;
	fd = open("./test.txt",O_RDWR);
	fp = fdopen(fd,"w");
	fprintf(fp,"test data hello world\n");
	fclose(fp);

	return 0;

}
