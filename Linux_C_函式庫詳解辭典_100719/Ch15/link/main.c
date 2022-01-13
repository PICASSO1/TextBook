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
*	1. symlink() function will be created "Symbol Linl";
*	2. link() feature create "Hard Link"!!
*/

int 
main()
{
	symlink("./TEXT.TXT", "./TEST.INI");

	link("./main", "./hello.info");

	return 0;
}
