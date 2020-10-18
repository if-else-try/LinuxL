#include"ch2.h"

int main()
{
	FILE *fp;
	fp=fopen(1,"w+");
	fprintf(fp,"test data %s\n","hello world");
	fclose(fp);
	return 0;

}
