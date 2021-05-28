/* c语言头文件：cExample.h */
#ifndef C_EXAMPLE_H
#define C_EXAMPLE_H
//注:写成extern "C" int add(int , int ); 也可以，但是需要g++来编译，gcc编译就会出错。
extern int add(int x, int y);
#endif
