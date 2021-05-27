/*
g++ TestDynamicLibrary.cpp -L../DynamicLibrary -ldynmath
生成a.out文件，
运行该文件时会提示：
./a.out: error while loading shared libraries: libdynmath.so: cannot open shared object file: No such file or directory
将创建的动态库复制到/usr/lib下面，然后运行测试程序就没有问题
sudo cp ../DynamicMath/libdynmath.so /usr/lib/
*/

// #include "./DynamicMath/DynamicMath.h"
#include <iostream>

#include "../DynamicMath/DynamicMath.h"
using namespace std;

int main(int argc, char* argv[]) {
  double a = 10;
  double b = 2;

  cout << "a + b = " << DynamicMath::add(a, b) << endl;
  cout << "a - b = " << DynamicMath::sub(a, b) << endl;
  cout << "a * b = " << DynamicMath::mul(a, b) << endl;
  cout << "a / b = " << DynamicMath::div(a, b) << endl;

  DynamicMath dyn;
  dyn.print();
  return 0;
}