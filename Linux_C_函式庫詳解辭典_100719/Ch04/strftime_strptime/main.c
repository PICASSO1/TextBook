#include <stdio.h>
#include <time.h>
#include <string.h>

/*
*	File Name: main.c
*
*	CopyLeft (C) 2016; All rights reserved.
*
*	Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
*
*	Version: 0.0.1.build022616
*
*	Date: 2016 / 02 / 26
*
*	Description: 
*	1. 
*/

int 
main()
{
	char *format0[]  = {
		"%I:%M:%S %p %m/%d %a ",
		"%x %X %Y ",
		"%A %d %B, %I:%S %p",
		"\0"
	}, *format1[] = {
		"Sat 26 July 2003, 17:53:32 will do fine. ",
		"Mon 15 Feb 2016, 07:15:26",
		"\0"
	}, szTemp[32];
	int i = -1;
	time_t myTime;
	struct tm *pTm = (struct tm *)NULL, stTm;

	// strftime()
	bzero((void *)&myTime, sizeof(time_t));
	time(&myTime);
	pTm = localtime(&myTime);
	printf("strftime(): \n");
	for (i = 0; strcmp(format0[i], "\0"); i++) {
		memset(szTemp, '\0', sizeof(char) * 32);
		strftime(szTemp, sizeof(char) * 30, format0[i], pTm);
		printf("%s => %s \n", format0[i], szTemp);
	}

	// strptime
	puts("");
	printf("strptime(): \n");
	for (i = 0; strcmp(format1[i], "\0"); i++) {
		bzero((void *)&stTm, sizeof(struct tm));
		pTm = &stTm;
		strptime(format1[i], "%a %d %b %Y, %H:%M:%S", pTm);
		printf("%02d/%02d/%02d %02d:%02d:%02d \n", pTm->tm_year % 100, pTm->tm_mon + 1, pTm->tm_mday, pTm->tm_hour, \
			pTm->tm_min, pTm->tm_sec);
	}

	return 0;
}
