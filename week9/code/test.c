#include"./ch9.h"

int main( int argc,char **argv)
{

	extern char ** environ;
	char **env = environ;

	int i;
	for(i = 1;i < argc; i++)
	{
		printf("%s",argv[i]);
	}
	while(*env)
	{
		printf("%s\n",*env);
		env++;
	}
	exit(EXIT_SUCCESS);
}
