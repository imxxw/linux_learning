# 编译和使用过程如下：

## 1 c++编译CppAdd.cpp，生成CppAdd.o
```g++ -c CppAdd.cpp```

## 2 c++编译CppAddWrapper.cpp，生成CppAddWrapper.o
```g++ -c CppAddWrapper.cpp```

## 3 将CppAdd.o、CppAddWrapper.o一起打包到静态库libCppAddWrapper.a
```ar -r libCppAddWrapper.a CppAdd.o CppAddWrapper.o```

## 4 c编译main.c，生成可执行文件main
```gcc main.c -o main -L. -lCppAddWrapper```

## 5 运行可执行文件main
```./main```
