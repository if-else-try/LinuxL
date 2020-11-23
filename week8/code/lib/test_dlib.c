#include"../ch8.h"
extern void dynamic_lib_fun_call(void);
extern void mysort(void);
int main()
{
	dynamic_lib_fun_call();
	mysort();
}
