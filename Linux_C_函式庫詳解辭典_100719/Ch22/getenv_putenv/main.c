#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
*	1. 這一支程式展現了getenv()和putenv()函式的用法；
*	2. 每一支程式 (程序)的環境變數 (environments)都是獨立的；在這一支程式中雖然修改了環境變數USERNAME；但回到原本的Shell執行
*		echo $USERNAME卻會得到root並沒有被改變....
*	3. 把程式中的while迴圈註解拿掉，可以確認在這一支程式中環境變數USERNAME確實有被改變。
*/

int 
main(argc, argv, envp)
int argc;
char *argv[], **envp;
{
	char *ptr = (char *)NULL;
	char szTemp[32];

	// Get the old USERNAME
	ptr = getenv("USERNAME");
	if (ptr == NULL) {
		perror("getenv");
		exit(EXIT_FAILURE);
	}
	printf("The OLD $USERNAME: %s \n", ptr);

	// Set the new USERNAME
	memset(szTemp, '\0', sizeof(char) * 32);
	strncpy(szTemp, "USERNAME=", 9);
	strncat(szTemp, "picasso", 7);
	if (putenv(szTemp) == -1) {
		perror("putenv");
		exit(EXIT_FAILURE);
	}
	// 
/*	while (*envp) {
		printf("%s\n", *envp);
		envp++;
	}
*/	
	// Get the new USERNAME
	ptr = getenv("USERNAME");
	if (ptr == NULL) {
		perror("getenv");
		exit(EXIT_FAILURE);
	}
	printf("The NEW $USERNAME: %s \n", ptr);

	return 0;
}
