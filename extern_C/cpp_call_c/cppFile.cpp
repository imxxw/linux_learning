// c++实现文件，调用add：cppFile.cpp
extern "C" {
#include "cExample.h"
}

#include "stdio.h"
int main(int argc, char *argv[])
{
	int a = add(1, 2);
	printf("1+ 2 = %d\n", a);

	return 0;
}