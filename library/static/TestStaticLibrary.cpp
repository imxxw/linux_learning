/*
Linux下使用静态库，只需要在编译的时候，指定静态库的搜索路径（-L选项）、指定静态库名（不需要lib前缀和.a后缀，-l选项）。
# g++ TestStaticLibrary.cpp -L../StaticLibrary -lstaticmath
*/

#include <iostream>

#include "./StaticMath/StaticMath.h"
using namespace std;

int main(int argc, char* argv[]) {
  double a = 10;
  double b = 2;

  cout << "a + b = " << StaticMath::add(a, b) << endl;
  cout << "a - b = " << StaticMath::sub(a, b) << endl;
  cout << "a * b = " << StaticMath::mul(a, b) << endl;
  cout << "a / b = " << StaticMath::div(a, b) << endl;

  StaticMath sm;
  sm.print();

  system("pause");
  return 0;
}