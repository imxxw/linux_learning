// init.c
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <pthread.h>
#include "pub.h"

// 打印共享属性
void printshared(pthread_mutexattr_t *attr)
{
	int err, shared;
	err = pthread_mutexattr_getpshared(attr, &shared);
	if (err != 0)
		PPERR(err, "pthread_mutexattr_getshared");
	if (shared == PTHREAD_PROCESS_PRIVATE)
		puts("shared = PTHREAD_PROCESS_PRIVATE");
	else if (shared == PTHREAD_PROCESS_SHARED)
		puts("shared = PTHREAD_PROCESS_SHARED");
	else
		puts("shared = ???");
}

// 打印鲁棒属性
void printrobust(pthread_mutexattr_t *attr)
{
	int err, robust;
	err = pthread_mutexattr_getrobust(attr, &robust);
	if (err != 0)
		PPERR(err, "pthread_mutexattr_getrobust");
	if (robust == PTHREAD_MUTEX_STALLED)
		puts("robust = PTHREAD_MUTEX_STALLED");
	else if (robust == PTHREAD_MUTEX_ROBUST)
		puts("robust = PTHREAD_MUTEX_ROBUST");
	else
		puts("robust = ???");
}

int main(int argc, char *argv[])
{
	int err, shared, robust = 0, flag = 1;
	if (argc >= 2)
		robust = 1;
	key_t key = 0x8888;
	// 创建共享内存
	int id = shmget(key, getpagesize(), IPC_CREAT | IPC_EXCL | 0666);
	if (id < 0)
		PERR("shmget");

	// 挂接共享内存
	struct ticket *t = (struct ticket *)shmat(id, NULL, 0);

	if ((long)t == -1)
		PERR("shmat");

	// 设置余票数量
	t->remain = 5;

	pthread_mutexattr_t mutexattr;
	err = pthread_mutexattr_init(&mutexattr);
	if (err != 0)
		PPERR(err, "pthread_mutexattr_init");

	printshared(&mutexattr);
	printrobust(&mutexattr);

	// 将互斥量的共享属性设置为可以进程间共享使用。
	shared = PTHREAD_PROCESS_SHARED;
	err = pthread_mutexattr_setpshared(&mutexattr, shared);
	if (err != 0)
		PPERR(err, "pthread_mutexattr_setshared");

	// 如果有命令行参数，就将鲁棒性设置为 PTHREAD_MUTEX_ROBUST
	// 本文暂时不设置此值
	if (robust) {
		err = pthread_mutexattr_setrobust(&mutexattr,
						  PTHREAD_MUTEX_ROBUST);
		if (err != 0)
			PPERR(err, "pthread_mutexattr_setshared");
	}

	puts("modify attribute ------------------>");
	printshared(&mutexattr);
	printrobust(&mutexattr);

	pthread_mutex_init(&t->lock, &mutexattr);

	err = pthread_mutexattr_destroy(&mutexattr);
	if (err != 0)
		PPERR(err, "pthread_mutexattr_destroy");

	err = shmdt((void *)t);

	if (err != 0)
		PERR("shmdt");

	return 0;
}
