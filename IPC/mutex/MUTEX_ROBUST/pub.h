#ifndef _MUTEX_PUB_H
#define _MUTEX_PUB_H

#include <errno.h>

#define PERR(msg) do { perror(msg); exit(-1); } while(0)
#define PPERR(err, msg) do { errno = err; perror(msg); exit(-1); } while(0)

struct ticket {
	int remain;
	pthread_mutex_t lock;
};

#endif