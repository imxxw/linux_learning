#include <stdio.h>
#include <sys/select.h>
#include <sys/time.h>
#include <time.h>

int counter = 0;
int counter_exit = 10;

void timer_func(int seconds, int mseconds) {
  struct timeval temp;
  temp.tv_sec = seconds;
  temp.tv_usec = mseconds * 1000;
  select(0, NULL, NULL, NULL, &temp);
  printf("counter = %d\n", counter);
  return;
}

int main() {
  int i;

  while (++counter < counter_exit + 1) {
    timer_func(1, 0);
  }

  return 0;
}