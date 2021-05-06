#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <pthread.h>
#include "pub.h"

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("Usage: %s <name>\n", argv[0]);
		exit(-1);
	}

	char *name = argv[1];
	int err, shared, flag = 1;
	key_t key = 0x8888;
	int id = shmget(key, 0, 0);
	if (id < 0)
		PERR("shmget");

	struct ticket *t = (struct ticket *)shmat(id, NULL, 0);

	if ((long)t == -1)
		PERR("shmat");

	while (flag) {
		if (EOWNERDEAD == (err = pthread_mutex_lock(&t->lock))) {
			puts("EOWNERDEAD");
			pthread_mutex_consistent(&t->lock);
		} else if (ENOTRECOVERABLE == err) {
			puts("ENOTRECOVERABLE");
		}
		int remain = t->remain;
		if (remain > 0) {
			sleep(1);
			printf("%s buy a ticket\n", name);
			--remain;
			sleep(3);
			t->remain = remain;
		} else
			flag = 0;
		pthread_mutex_unlock(&t->lock);
		sleep(2);
	}

	return 0;
}
