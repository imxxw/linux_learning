/**
 * \file main.c
 * \author xiongxw (imxxw@outlook.com)
 * \brief use SIGALRM + alarm to realize a timer
 * \version 0.1
 * \date 2021-05-27
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <signal.h>
#include <stdio.h>

int counter = 0;
int counter_exit = 10;

void timer_func(int sig) {
  if (SIGALRM == sig) {
    printf("counter=%d\n", ++counter);
    if(counter_exit == counter) exit(0);
    alarm(1);  // 继续设置闹钟
  }
}

int main() {
  signal(SIGALRM, timer_func);
  alarm(1);
  getchar();
  return 0;
}