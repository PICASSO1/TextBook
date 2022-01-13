#include <stdio.h>
#include <unistd.h>

/*
*	File Name: memory5a.c
*
*	CopyLeft (C) 2016; All rights reserved.
*
*	Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
*
*	Version: 0.0.1.build030816
*
*	Date: 2016 / 03 / 08
*
*	Description: 
*	1. 
*/

int 
main()
{
	char *some_money = (char *)NULL;

	printf("A read from null %s \n", some_money);
	sprintf(some_money, "A write to null. \n");

	return 0;
}
