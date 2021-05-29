/*
首先，生成目标文件，此时要加编译器选项-fpic
gcc -fPIC -c test.c
-fPIC 创建与地址无关的编译程序（pic，position independent code），是为了能够在多个应用程序间共享。
然后，生成动态库，此时要加链接器选项-shared
gcc -shared -o libtest.so test.o
-shared指定生成动态链接库。

其实上面两个步骤可以合并为一个命令：
gcc -fPIC -shared -o libtest.so test.c
*/

#ifndef _TEST_H_
#define _TEST_H_

#ifdef __cplusplus
extern "C" {
#endif

void test_func();

#ifdef __cplusplus
}
#endif /* end of __cplusplus */

#endif // _TEST_H_