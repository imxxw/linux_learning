/**
 * \file simple_demo.c
 * \author xiongxw (imxxw@outlook.com)
 * \brief 一个简单的互斥量的例子, 设置了PTHREAD_MUTEX_ROBUST属性，可以避免线程退出没有解锁导致的死锁。
 * 原文：http://manpages.ubuntu.com/manpages/bionic/man3/pthread_mutexattr_setrobust.3.html
 * \version 0.1
 * \date 2021-05-07
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

#define handle_error_en(en, msg) \
do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)

static pthread_mutex_t mtx;

static void *original_owner_thread(void *ptr)
{
	printf("[original owner] Setting lock...\n");
	pthread_mutex_lock(&mtx);
	printf("[original owner] Locked. Now exiting without unlocking.\n");
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	pthread_t thr;
	pthread_mutexattr_t attr;
	int s;

	pthread_mutexattr_init(&attr);
	/* initialize the attributes object */
	pthread_mutexattr_setrobust(&attr, PTHREAD_MUTEX_ROBUST);
	/* set robustness */

	pthread_mutex_init(&mtx, &attr); /* initialize the mutex */

	pthread_create(&thr, NULL, original_owner_thread, NULL);

	sleep(2);

	/* "original_owner_thread" should have exited by now */

	printf("[main thread] Attempting to lock the robust mutex.\n");
	s = pthread_mutex_lock(&mtx);
	if (s == EOWNERDEAD) {
		printf("[main thread] pthread_mutex_lock() returned EOWNERDEAD\n");
		printf("[main thread] Now make the mutex consistent\n");
		s = pthread_mutex_consistent(&mtx);
		if (s != 0)
			handle_error_en(s, "pthread_mutex_consistent");
		printf("[main thread] Mutex is now consistent; unlocking\n");
		s = pthread_mutex_unlock(&mtx);
		if (s != 0)
			handle_error_en(s, "pthread_mutex_unlock");

		exit(EXIT_SUCCESS);
	} else if (s == 0) {
		printf("[main thread] pthread_mutex_lock() unexpectedly succeeded\n");
		exit(EXIT_FAILURE);
	} else {
		printf("[main thread] pthread_mutex_lock() unexpectedly failed\n");
		handle_error_en(s, "pthread_mutex_lock");
	}
}