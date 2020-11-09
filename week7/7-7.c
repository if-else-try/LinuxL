#include"ch7.h"

const char * a = "test_env1";
static void set_env_string(void)
{
	char test_env[] = "test_env=test";
	if(putenv(test_env)!= 0)
	{
		printf("Putenv is failed\n");

	}
	printf("1.The test_env = %s\n",getenv("test_env"));
	setenv(a,"test",1);

}	
static void show_env_string()
{

	printf("2.The test_env = %s\n",getenv("test_env1"));
}
int main()
{
	set_env_string();
	show_env_string();
	return 0;
}
