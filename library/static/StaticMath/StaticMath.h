/*
首先，将代码文件编译成目标文件.o（StaticMath.o）
g++ -c StaticMath.cpp
注意带参数-c，否则直接编译为可执行文件
然后，通过ar工具将目标文件打包成.a静态库文件
ar -crv libstaticmath.a StaticMath.o
生成静态库libstaticmath.a。
*/

#pragma once

class StaticMath {
 public:
  StaticMath(void){};
  ~StaticMath(void){};

  static double add(double a, double b);  //加法
  static double sub(double a, double b);  //减法
  static double mul(double a, double b);  //乘法
  static double div(double a, double b);  //除法

  void print();
};