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
*	1. getpwent()直接讀取/etc/passwd檔，用法如下；
*	2. setpwent()會在getpwent()之后，再把Pointer (指標)指回到檔案的最前端；
*	3. getpwent()和endpwent()要成對使用....
*	4. ***pwent, /etc/passwd "entry (進入)" ....
*/

int 
main()
{
	struct passwd *pPasswd = (struct passwd *)NULL;

	while ((pPasswd = getpwent()) != NULL)
		printf("%s:%s:%u:%u:%s:%s:%s \n", pPasswd->pw_name, pPasswd->pw_passwd, pPasswd->pw_uid, pPasswd->pw_gid, pPasswd \
			->pw_gecos, pPasswd->pw_dir, pPasswd->pw_shell);
	
	puts("");
	setpwent();
	while ((pPasswd = getpwent()) != NULL)
		printf("%s:%s:%u:%u:%s:%s:%s \n", pPasswd->pw_name, pPasswd->pw_passwd, pPasswd->pw_uid, pPasswd->pw_gid, pPasswd \
			->pw_gecos, pPasswd->pw_dir, pPasswd->pw_shell);

	endpwent();
	
	return 0;
}
