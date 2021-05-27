/**
 * \file main.c
 * \author xiongxw (imxxw@outlook.com)
 * \brief RTC机制利用系统硬件提供的Real Time Clock机制，通过读取RTC硬件/dev/rtc，通过ioctl()设置RTC频率
 * \version 0.1
 * \date 2021-05-27
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <errno.h>
#include <fcntl.h>
#include <linux/rtc.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
  unsigned long i = 0;
  unsigned long data = 0;
  int retval = 0;
  int fd = open("/dev/rtc", O_RDONLY);

  if (fd < 0) {
    perror("open");
    exit(errno);
  }

  /*Set the freq as 4Hz*/
  if (ioctl(fd, RTC_IRQP_SET, 1) < 0) {
    perror("ioctl(RTC_IRQP_SET)");
    close(fd);
    exit(errno);
  }

  /* Enable periodic interrupts */
  if (ioctl(fd, RTC_PIE_ON, 0) < 0) {
    perror("ioctl(RTC_PIE_ON)");
    close(fd);
    exit(errno);
  }

  for (i = 0; i < 100; i++) {
    if (read(fd, &data, sizeof(unsigned long)) < 0) {
      perror("read");
      close(fd);
      exit(errno);
    }
    printf("timer\n");
  }
  
  /* Disable periodic interrupts */
  ioctl(fd, RTC_PIE_OFF, 0);
  close(fd);

  return 0;
}