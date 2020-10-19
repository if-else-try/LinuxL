#include"ch2.h"


int main(int argc ,char * argv[])
{
	
	int i;
	FILE *fp;

	if((fp = fopen("./test.txt","w"))==NULL)
		perror("open failed\n");

	for( i=1;i<argc;i++)
	{
		fprintf(fp,"%s",argv[i]);
		printf(" [%d] %s",i,argv[i]);
	}
	fclose(fp);
	return 0;
}
