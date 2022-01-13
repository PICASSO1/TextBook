#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#define FILENAME "./TEXT.TXT"
#include <time.h>

int main(int argc, char *argv[])
{
	struct stat stStatBuf;
	int fd = 0;

	memset(&stStatBuf, 0, sizeof(struct stat));

	fd = open(FILENAME, O_RDONLY);
	if ( fd != -1 ) {
		fstat(fd, &stStatBuf);
		printf("st_dev = %c \n", stStatBuf.st_dev);
		printf("st_ino = %d \n", stStatBuf.st_ino);
		printf("st_mode = %d \n", stStatBuf.st_mode);
		printf("st_nlink = %d \n", stStatBuf.st_nlink);
		printf("st_uid = %d \n", stStatBuf.st_uid);
		printf("st_gid = %d \n", stStatBuf.st_gid);
		printf("st_rdev = %d \n", stStatBuf.st_rdev);
		printf("st_size = %d \n", stStatBuf.st_size);
		printf("st_blksize = %d \n", stStatBuf.st_blksize);
		printf("st_blocks = %d \n", stStatBuf.st_blocks);
		printf("st_atime= %s", ctime(&stStatBuf.st_atime));
		printf("st_mtime = %s", ctime(&stStatBuf.st_mtime));
		printf("st_ctime = %s", ctime(&stStatBuf.st_ctime));
	}
	close(fd);

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
	blksize_t st_blksize; // ??I/O ????
	blkcnt_t st_blocks; // ??????
	time_t st_atime; // ????????
	time_t st_mtime; // ????????
	time_t st_ctime; // ??????
};
*/
