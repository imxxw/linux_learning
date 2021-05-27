/*
首先，生成目标文件，此时要加编译器选项-fpic
g++ -fPIC -c DynamicMath.cpp
-fPIC 创建与地址无关的编译程序（pic，position independent code），是为了能够在多个应用程序间共享。
然后，生成动态库，此时要加链接器选项-shared
g++ -shared -o libdynmath.so DynamicMath.o
-shared指定生成动态链接库。

其实上面两个步骤可以合并为一个命令：
g++ -fPIC -shared -o libdynmath.so DynamicMath.cpp
*/

#pragma once
class DynamicMath {
 public:
  DynamicMath(void){};
  ~DynamicMath(void){};

  static double add(double a, double b);
  static double sub(double a, double b);
  static double mul(double a, double b);
  static double div(double a, double b);

  void print();
};