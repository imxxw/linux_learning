/* C实现文件 cFile.c*/
#include <stdio.h>
extern int add(int x, int y);
int main(int argc, char *argv[])
{
	int a = add(1, 2);
	printf("1+ 2 = %d\n", a);
	return 0;
}