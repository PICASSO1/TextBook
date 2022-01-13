#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/time.h>

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
*	1. int getrusage(int who, struct rusage *r_usage) ---- 取得系統的執行時間
*	a). int who; RUSAGE_SELF (傳回目前行程的使用資訊) | RUSAGE_CHILDREN (回傳的使用資訊，還必須包括子行程)
*	b). 
*	struct rusage {
*		struct timeval ru_utime;
*		struct timeval ru_stime;
*	};
*	struct timeval {
*		long tv_sec;
*		long tv_usec;
*	};
*	2. int getrlimit(int resource, struct rlimit r_limit); 
*	    int setrlimit(int resource, const struct rlimit r_limit);
*		取的和設定系統的資源限制 (Resource Limit)，
*	a). int resource; ---- 要設定哪一種資源 .... 
*		defined in /usr/include/bits/resource.h, enum __rlimit_resource { RLIMIT_CPU | RLIMIT_FSIZE | RLIMIT_DATA .... };
*	b). struct rlimit {
*		unsigned long rlim_cur;	// The current (soft) limit.
*		unsigned long rlim_max;	// The hard limit.
*	};
*/

int 
main()
{
	int nRet = 0;
	struct rusage stUsage;
	struct rlimit stLimit;
	unsigned long ulCur = 0UL, ulMax = 0UL;

	// Get Usage ....
	bzero((void *)&stUsage, sizeof(struct rusage));
	nRet = getrusage(RUSAGE_SELF, &stUsage);
	if (nRet == -1) {
		perror("getrusage");
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "CPU Usage: \n");
	fprintf(stdout, "User Time: %ld.%03ld \n", stUsage.ru_utime.tv_sec, stUsage.ru_utime.tv_usec);
	fprintf(stdout, "System Time: %ld.%03ld \n", stUsage.ru_stime.tv_sec, stUsage.ru_stime.tv_usec);

	// Get resource limit
	puts("");
	bzero((void *)&stLimit, sizeof(struct rlimit));
	nRet = getrlimit(RLIMIT_FSIZE, &stLimit);
	if (nRet == -1) {
		perror("getrlimit");
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "File Size Limit: \n");
	ulCur = stLimit.rlim_cur;
	ulMax = stLimit.rlim_max;
	fprintf(stdout, "Soft Limit: %ld \n", ulCur);
	fprintf(stdout, "Hard Limit: %ld \n", ulMax);

	// Set new resource limit ....
	stLimit.rlim_cur = 2048UL;
	stLimit.rlim_max = 4096UL;
	nRet = setrlimit(RLIMIT_FSIZE, &stLimit);
	if (nRet == -1) {
		perror("setrlimit");
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "\nSet new resource limit .... \n");

	bzero((void *)&stLimit, sizeof(struct rlimit));
	nRet = getrlimit(RLIMIT_FSIZE, &stLimit);
	if (nRet == -1) {
		perror("getrlimit");
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "New File Size Limit: \n");
	fprintf(stdout, "Soft Limit: %ld \n", stLimit.rlim_cur);
	fprintf(stdout, "Hard Limit: %ld \n", stLimit.rlim_max);

	// Revert to original configure ....
	puts("");
	bzero((void *)&stLimit, sizeof(struct rlimit));
	stLimit.rlim_cur = ulCur;
	stLimit.rlim_max = ulMax;
	setrlimit(RLIMIT_FSIZE, &stLimit);
	printf("Revert to original configure .... \n");

	return 0;
}
