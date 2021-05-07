/**
 * \file main.c
 * \author xiongxw (imxxw@outlook.com)
 * \brief  这是一个简单的读写锁的例子，原文：https://blog.csdn.net/tennysonsky/article/details/46485735
 * \version 0.1
 * \date 2021-05-07
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_rwlock_t rwlock; //读写锁
int num = 1;

//读操作，其他线程允许读操作，却不允许写操作
void *read1(void *arg)
{
	pthread_t thread_id = 1;
	while (1) {
		pthread_rwlock_rdlock(&rwlock);
		printf("[thread %lu] read %d lock\n", thread_id, num);
		sleep(1);
		printf("[thread %lu] read %d unlock\n", thread_id, num);
		pthread_rwlock_unlock(&rwlock);
		sleep(1);
	}
}

//读操作，其他线程允许读操作，却不允许写操作
void *read2(void *arg)
{
	pthread_t thread_id = 2;
	while (1) {
		pthread_rwlock_rdlock(&rwlock);
		printf("[thread %lu] read %d lock\n", thread_id, num);
		sleep(2);
		printf("[thread %lu] read %d unlock\n", thread_id, num);
		pthread_rwlock_unlock(&rwlock);
		sleep(1);
	}
}

//写操作，其它线程都不允许读或写操作
void *write1(void *arg)
{
	pthread_t thread_id = 3;
	while (1) {
		pthread_rwlock_wrlock(&rwlock);
		num++;
		printf("[thread %lu] write %d lock\n", thread_id, num);
		sleep(1);
		printf("[thread %lu] write %d unlock\n", thread_id, num);
		pthread_rwlock_unlock(&rwlock);
		sleep(1);
	}
}

//写操作，其它线程都不允许读或写操作
void *write2(void *arg)
{
	pthread_t thread_id = 4;
	while (1) {
		pthread_rwlock_wrlock(&rwlock);
		num++;
		printf("[thread %lu] write %d lock\n", thread_id, num);
		sleep(2);
		printf("[thread %lu] write %d unlock\n", thread_id, num);
		pthread_rwlock_unlock(&rwlock);
		sleep(1);
	}
}

int main()
{
	pthread_t ptd1, ptd2, ptd3, ptd4;

	pthread_rwlock_init(&rwlock, NULL); //初始化一个读写锁

	//创建线程
	pthread_create(&ptd1, NULL, read1, NULL);
	pthread_create(&ptd2, NULL, read2, NULL);
	pthread_create(&ptd3, NULL, write1, NULL);
	pthread_create(&ptd4, NULL, write2, NULL);

	//等待线程结束，回收其资源
	pthread_join(ptd1, NULL);
	pthread_join(ptd2, NULL);
	pthread_join(ptd3, NULL);
	pthread_join(ptd4, NULL);

	pthread_rwlock_destroy(&rwlock); //销毁读写锁

	return 0;
}