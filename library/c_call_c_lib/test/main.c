/*
gcc main.c -L../lib -ltest -lpthread
生成a.out文件，
运行该文件时会提示：
./a.out: error while loading shared libraries: libtest.so: cannot open shared object file: No such file or directory
将创建的动态库复制到/usr/lib下面，然后运行测试程序就没有问题
sudo cp ../lib/libtest.so /usr/lib/
*/

#include "../lib/test.h"

int main(int argc, char *argv[])
{
    test_func();
	return 0;
}