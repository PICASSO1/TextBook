#include <sys/types.h>
#include <unistd.h>

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
*	1. cat -n /etc/passwd
*		root:x:0:0:root:/root:/bin/bash
*		picasso:x:500:500:Pablo Picasso G.:/home/picasso:/bin/bash
*/

int 
main()
{
	chown("./TEXT.TXT", (uid_t)500, (gid_t)500);

	return 0;
}
