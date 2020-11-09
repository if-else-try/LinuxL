#include"../ch7.h"

extern void dynamic_lib_call(void);
int main()
{
	void *dlib = dlopen("./libdlib.so",RTLD_NOW);
	if(!dlib)
	{
		printf("dlopen failed!\n");
		exit(-1);
	}
	void (*dfunc) (void) = dlsym(dlib,"dynamic_lib_call");
	if(!dfunc)
	{
		printf("dfunc is failed\n");
		exit(-1);
	}
	dfunc();
	void (*dsum) (int) = dlsym(dlib,"dsum");
        if(!dsum)
        {
                printf("dsum is failed\n");
                exit(-1);
        }

	dsum(10);
	dlclose(dlib);
	return 0;
}
