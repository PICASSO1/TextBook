#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pwd.h>
#include <sys/types.h>

/*
*	File Name: main.c
*
*	CopyLeft (C) 2016; All rights reserved.
*
*	Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
*
*	Version: 0.0.1.build022516
*
*	Date: 2016 / 02 / 25
*
*	Description: 
*	1. getpw(), getpwnam(), getpwuid() 都是取得/etc/passwd檔的資料；
*	2. getpw((uid_t), string)是透過UID來取得整筆資料 (以字串的形式)；
*	3. getpwnam()則是用login username, getpwuid()是用UID來取得；
*	4. struct passwd定義在/usr/include/pwd.h中，裡面的成員也依序剛好是/etc/passwd中的各個欄位!!
*/

int 
main()
{
	char szTemp[128];
	struct passwd *stPasswd = (struct passwd *)NULL;

	// Try to use getpw() function ....
	memset(szTemp, '\0', sizeof(char) * 128);
	if (getpw((unsigned int)500, szTemp) == -1) {	// 500, is picasso's UID
		perror("getpw");
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "500 (picasso) of getpw(): \n%s \n\n", szTemp);

	// Try to use getpwnam(), get /etc/passwd infos by name ....
	stPasswd = getpwnam("root");
	if (stPasswd == NULL) {
		perror("getpwnam");
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "getpwnam(\"root\"): \n");
	printf("Name: %s \n", stPasswd->pw_name);
	printf("Password: %s \n", stPasswd->pw_passwd);
	printf("UID: %u \n", stPasswd->pw_uid);
	printf("GID: %u \n", stPasswd->pw_gid);
	printf("Full Name: %s \n", stPasswd->pw_gecos);
	printf("Home Directory: %s \n", stPasswd->pw_dir);
	printf("Shell: %s \n\n", stPasswd->pw_shell);

	// Try to use getpwuid(), get /etc/passwd INFOs by UID ....
	stPasswd = getpwuid((uid_t)500);
	if (stPasswd == NULL) {
		perror("getpwuid");
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "getpwuid((uid_t)500): \n");
	printf("Name: %s \n", stPasswd->pw_name);
	printf("Password: %s \n", stPasswd->pw_passwd);
	printf("UID: %u \n", stPasswd->pw_uid);
	printf("GID: %u \n", stPasswd->pw_gid);
	printf("Full Name: %s \n", stPasswd->pw_gecos);
	printf("Home Directory: %s \n", stPasswd->pw_dir);
	printf("Shell: %s \n\n", stPasswd->pw_shell);
	
	return 0;
}
