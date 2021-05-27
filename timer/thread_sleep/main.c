/**
 * \file main.c
 * \author xiongxw (imxxw@outlook.com)
 * \brief 使用线程+sleep的方式实现定时器
 * \version 0.1
 * \date 2021-05-27
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int counter = 0;
int counter_exit = 10;

//读操作，其他线程允许读操作，却不允许写操作
void *timer_func(void *arg) {
  while (++counter < counter_exit + 1) {
    printf("[subthread] counter = %d\n", counter);
    sleep(1);
  }
}

int main() {
  pthread_t ptd1;

  //创建线程
  pthread_create(&ptd1, NULL, timer_func, NULL);

  int i = 0;
  while (++i < 11) {
    printf("[main] i = %d\n", i);
    sleep(2);
  }

  //等待线程结束，回收其资源
  pthread_join(ptd1, NULL);

  return 0;
}