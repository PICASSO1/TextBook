#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>

/*
*	File Name: printdir.c
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
*	2. 
*/

void printdir(char *, int);

int main(argc, argv, envp)
int argc;
char *argv[], **envp;
{
	char *topdir = ".";

	if (argc >= 2)
		topdir = argv[1];

	printf("Directory scan of %s \n", topdir);
	printdir(topdir, 0);
	printf("Done. \n");

	return 0;
}

void 
printdir(dir, depth)
char *dir;
int depth;
{
	DIR *dp = (DIR *)NULL;
	struct dirent *entry = (struct dirent *)NULL;
	struct stat statbuf;

	dp = opendir(dir);
	if (dp == (DIR *)NULL) {
		perror("opendir");
		fprintf(stderr, "Can't open directory: %s \n", dir);
		exit(EXIT_FAILURE);
	}
	chdir(dir);
	while ((entry = readdir(dp)) != (struct dirent *)NULL) {
		bzero((void *)&statbuf, sizeof(struct stat));
		lstat(entry->d_name, &statbuf);
		if (S_ISDIR(statbuf.st_mode)) {
			// Found a directory, but ignore ./ and ../ 
			if ((strcmp(".", entry->d_name) == 0) || (strcmp("..", entry->d_name) == 0))
				continue;
			printf("%*s%s/\n", depth, "", entry->d_name);
			// Recurse at a new indent level
			printdir(entry->d_name, depth + 4);
		}
		else
			printf("%*s%s/\n", depth, "", entry->d_name);
	}
	chdir("..");
	closedir(dp);

	return;
}
