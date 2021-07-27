#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SHM_SIZE 0x100

int main()
{
	int fd = shm_open("xxw_shm", O_RDONLY, 0666);
	ftruncate(fd, SHM_SIZE);

	char *p = mmap(NULL, SHM_SIZE, PROT_READ, MAP_SHARED, fd, 0);

	printf("%c %c %c %c\n", p[0], p[1], p[2], p[3]);
	munmap(p, SHM_SIZE);

    // delete the shared memory
	// if(shm_unlink("posix_shm") == -1) return -1;

	return 0;
}