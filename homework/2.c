#include"ch03.h"
struct buffer
{
	char buf1[5];
	char buf2[5];
}buf;

int main()
{
	memset(buf.buf1,0,5);
	memset(buf.buf2,0,5);
	printf("%s\n",buf.buf2);
	gets(buf.buf1);	
	printf("%s\n",buf.buf2);

	return 0;
}
