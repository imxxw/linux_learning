#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <pthread.h>
#include "pub.h"

int main()
{
	int err;
	key_t key = 0x8888;
	int id = shmget(key, 0, 0);
	if (id < 0)
		PERR("shmget");

	struct ticket *t = (struct ticket *)shmat(id, NULL, 0);

	if ((long)t == -1)
		PERR("shmat");

	err = pthread_mutex_destroy(&t->lock);
	if (err != 0)
		PPERR(err, "pthread_mutex_destroy");

	err = shmdt((void *)t);
	if (err != 0)
		PERR("shmdt");

	err = shmctl(id, IPC_RMID, NULL);
	if (err != 0)
		PERR("shmctl");

	return 0;
}
