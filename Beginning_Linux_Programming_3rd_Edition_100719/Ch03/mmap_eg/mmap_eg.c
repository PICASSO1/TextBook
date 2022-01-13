#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

/*
*	File Name: mmap_eg.c
*
*	CopyLeft (C) 2016; All rights reserved.
*
*	Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
*
*	Version: 0.0.1.build030216
*
*	Date: 2016 / 03 / 02
*
*	Description: 
*	1. 
*/

typedef struct {
	int integer;
	char string[24];
} RECORD;

#define	NRECORDS	(100)

int 
main()
{
	RECORD record, *mapped = (RECORD *)NULL;
	int i = -1, fd = 0;
	FILE *fp = (FILE *)fp;

	fp = fopen("records.dat", "w+");
	bzero((void *)&record, sizeof(RECORD));
	for (i = 0; i < NRECORDS; i++) {
		record.integer = i;
		sprintf(record.string, "RECORD-%d", i);
		fwrite((void *)&record, sizeof(RECORD), 1, fp);
	}
	fclose(fp);
	// ========================================
	fp = fopen("records.dat", "r+");
	fseek(fp, sizeof(RECORD) * 43, SEEK_SET);
	bzero((void *)&record, sizeof(RECORD));
	fread((void *)&record, sizeof(RECORD), 1, fp);

	record.integer = 143;
	sprintf(record.string, "RECORD-%d", record.integer);

	fseek(fp, sizeof(RECORD) * 43, SEEK_SET);
	fwrite((void *)&record, sizeof(RECORD), 1, fp);
	fclose(fp);
	// ========================================
	fd = open("record.dat", O_RDWR);
	mapped = (RECORD *)mmap(0, sizeof(RECORD) * NRECORDS, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	mapped[43].integer = 243;
	sprintf(mapped[43].string, "RECORD-%d", mapped[43].integer);
	msync((void *)mapped, sizeof(RECORD) * NRECORDS, MS_ASYNC);
	munmap((void *)mapped, sizeof(RECORD) * NRECORDS);
	close(fd);

	return 0;
}


