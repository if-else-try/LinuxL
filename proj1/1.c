#include"ch8.h"

int main()
{

int i,*pt = NULL;
for(i = 1;i<1024*1024;i++ )
{
	pt = (int*)malloc (i*1024*sizeof(int));
	if(pt!=NULL)
	{
		printf("System allocate %dkB\n",i);
	}
	else
	{
		printf("allocate finished!\n");
		exit(1);
	}
}
return 0;
}
