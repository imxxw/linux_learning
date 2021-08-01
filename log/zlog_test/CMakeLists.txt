cmake_minimum_required (VERSION 3.14)  # 版本不要太低，不然后续交叉编译时会失败
project (zlog)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -g")
# 添加zlog的头文件搜索路径
include_directories ("${PROJECT_SOURCE_DIR}/zlog")

add_executable(zlog test.c)
# 链接到zlog
target_link_libraries (zlog ${PROJECT_SOURCE_DIR}/zlog/libzlog.so)