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
	int fd = shm_open("xxw_shm", O_CREAT | O_RDWR, 0666);
	ftruncate(fd, SHM_SIZE);

	char *p =
		mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

	memset(p, 'A', SHM_SIZE);
	munmap(p, SHM_SIZE);

	return 0;
}