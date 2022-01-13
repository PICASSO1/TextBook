#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#define FILENAME_1 "./TEXT.TXT"
#define FILENAME_2 "./TEXT.lnk"
#include <time.h>

int main(void) {

	struct stat stStatBuf_1, stStatBuf_2;

	bzero((void *)&stStatBuf_1, sizeof(struct stat));
	lstat(FILENAME_1, &stStatBuf_1);
	printf("st_dev = %c \n", stStatBuf_1.st_dev);
	printf("st_ino = %d \n", stStatBuf_1.st_ino);
	printf("st_mode = %d \n", stStatBuf_1.st_mode);
	printf("st_nlink = %d \n", stStatBuf_1.st_nlink);
	printf("st_uid = %d \n", stStatBuf_1.st_uid);
	printf("st_gid = %d \n", stStatBuf_1.st_gid);
	printf("st_rdev = %d \n", stStatBuf_1.st_rdev);
	printf("st_size = %d \n", stStatBuf_1.st_size);
	printf("st_blksize = %ld \n", (unsigned long)stStatBuf_1.st_blksize);
	printf("st_blocks = %ld \n", (unsigned long)stStatBuf_1.st_blocks);
	printf("st_atime= %s", ctime(&stStatBuf_1.st_atime));
	printf("st_mtime = %s", ctime(&stStatBuf_1.st_mtime));
	printf("st_ctime = %s", ctime(&stStatBuf_1.st_ctime));
	printf("\n");
	bzero((void *)&stStatBuf_2, sizeof(struct stat));
	lstat(FILENAME_2, &stStatBuf_2);
	printf("st_dev = %c \n", stStatBuf_2.st_dev);
	printf("st_ino = %d \n", stStatBuf_2.st_ino);
	printf("st_mode = %d \n", stStatBuf_2.st_mode);
	printf("st_nlink = %d \n", stStatBuf_2.st_nlink);
	printf("st_uid = %d \n", stStatBuf_2.st_uid);
	printf("st_gid = %d \n", stStatBuf_2.st_gid);
	printf("st_rdev = %d \n", stStatBuf_2.st_rdev);
	printf("st_size = %d \n", stStatBuf_2.st_size);
	printf("st_blksize = %ld \n", (unsigned long)stStatBuf_2.st_blksize);
	printf("st_blocks = %ld \n", (unsigned long)stStatBuf_2.st_blocks);
	printf("st_atime= %s", ctime(&stStatBuf_2.st_atime));
	printf("st_mtime = %s", ctime(&stStatBuf_2.st_mtime));
	printf("st_ctime = %s", ctime(&stStatBuf_2.st_ctime));

	return 0;
}

/*
struct stat {
	dev_t st_dev; // ID of device containing file
	ino_t st_ino; // inode ??
	mode_t st_mode; // ??
	nlink_t st_nlink; // hard links ??
	uid_t st_uid; // user ID ???
	gid_t st_gid; // group ID ???
	dev_t st_rdev; // device ID
	off_t st_size; // ?byte???,????
	unsigned long st_blksize; // ??I/O ????
	unsigned long st_blocks; // ??????
	time_t st_atime; // ????????
	time_t st_mtime; // ????????
	time_t st_ctime; // ??????
};
*/
