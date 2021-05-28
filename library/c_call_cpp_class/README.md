# 一 编译（静态链接）和使用过程如下：

## 1 c++编译 person.cpp，生成 person.o
```g++ -c person.cpp```

## 2 c++编译 person_wrapper.cpp，生成 person_wrapper.o
```g++ -c person_wrapper.cpp```

## 3 将 person.o、person_wrapper.o一起打包到静态库 libPersonWrapper.a
```ar -r libPersonWrapper.a person.o person_wrapper.o```

## 4 c编译 main.c，生成可执行文件main
```gcc main.c -o main -L. -lPersonWrapper -lstdc++```

## 5 运行可执行文件 main
```./main```


# 二 编译（动态链接）和使用过程如下：

## 1 c++编译 person.cpp，生成 person.o
```g++ -fPIC -c person.cpp```

## 2 c++编译 person_wrapper.cpp，生成 person_wrapper.o
```g++ -fPIC -c person_wrapper.cpp```

## 3 将 person.o、person_wrapper.o一起打包到动态链接库 libPersonWrapper.so
```g++ -shared -o libPersonWrapper.so person.o person_wrapper.o```

## 4 c编译 main.c，生成可执行文件main
```gcc main.c -o main -L. -lPersonWrapper -lstdc++```

## 5 运行可执行文件 main
```./main```