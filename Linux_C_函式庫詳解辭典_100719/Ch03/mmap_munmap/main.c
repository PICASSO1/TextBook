#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
*	File Name: main.c
*
*	CopyLeft (C) 2016; All rights reserved.
*
*	Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
*
*	Version: 0.0.1.build030316
*
*	Date: 2016 / 03 / 03
*
*	Description: 
*	1. We read /etc/passwd contexts by mmap()-munmap() function .... \n
*	2. void *mmap(void *start, size_t length, int prot, int flags, int fd,off_t offset);
*	3. int munmap(void *start, size_t length);
*/

int 
main()
{
	int fd = 0;
	void *start = (void *)NULL;
	struct stat stStat;

	fd = open("/etc/passwd", O_RDONLY);
	bzero((void *)&stStat, sizeof(struct stat));
	fstat(fd, &stStat);
	start = mmap((void *)NULL, stStat.st_size, PROT_READ, MAP_PRIVATE, fd, (off_t)0);
	if (start == MAP_FAILED) {
		perror("mmap");
		exit(EXIT_FAILURE);
	}
	printf("%s\n", (char *)start);
	munmap(start, stStat.st_size);
	close(fd);
	
	return 0;
}
