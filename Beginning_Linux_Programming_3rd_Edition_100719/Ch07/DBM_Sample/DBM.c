#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <gdbm/ndbm.h>

/*
*	File Name: DBM.c
*
*	CopyLeft (C) 2017; All rights reserved.
*
*	Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
*
*	Version: 0.0.1.build030217
*
*	Date: 2017 / 03 / 02
*
*	Description: 
*	1. rpm -ivh gdbm-1.11-7.fc24.i686.rpm
*	2. 
*/

#define	DBM_FILE		"/tmp/DBM"
#define	SIZE			5
#define	__FUNC__		__func__

typedef struct {
	int nIndex;
	char *strSubject;
	float fScore;
	char cResult;
} DataDef;

int Index[SIZE] = {1, 2, 3, 4, 5};
char *Subject[SIZE] = {"Chinese", "Mathematics", "Art", "Spanish", "English"};
float Score[SIZE] = {99.99, 90.04, 85, 66.6, 59.00};
char Result[SIZE] = {'A', 'B', 'C', 'D', 'E'};

int 
main()
{
	DBM *pDBM = (DBM *)NULL;
	DataDef MyData[SIZE], Data;
	int i = -1, nRet = -1;
	datum keyDatum, dataDatum;
	char strKey[2], *pStr = (char *)NULL;

	// 先把我們要儲存的資料，存在我們所建立的結構中
	bzero((void *)&MyData, sizeof(DataDef) * SIZE);
	for (i = 0; i < SIZE; i++) {
		MyData[i].nIndex = Index[i];
		MyData[i].strSubject = Subject[i];
		MyData[i].fScore = Score[i];
		MyData[i].cResult = Result[i];
	}

/*	for (i = 0; i < SIZE; i++) {	// Just for testing!!
		printf("MyData[%d].nIndex = %d \n", i, MyData[i].nIndex);
		printf("MyData[%d].strSubject = %s \n", i, MyData[i].strSubject);
		printf("MyData[%d].fScore = %4.2f \n", i, MyData[i].fScore);
		printf("MyData[%d].cResult = %c \n", i, MyData[i].cResult);
		puts("");
	}
*/
	pDBM = dbm_open(DBM_FILE, O_RDWR | O_CREAT, 0666);
	if (pDBM == (DBM *)NULL) {
		fprintf(stderr, "%s %s %s (%d): %s failed to open DataBase (%s). \r\n", __DATE__, __TIME__, __FILE__, __LINE__, "dbm_open()", DBM_FILE);
		dbm_clearerr(pDBM);
		dbm_close(pDBM);
		exit(EXIT_FAILURE);
	}

	// 把結構中的資料，儲存到DBM....
	for (i = 0; i < SIZE; i++) {
		memset(strKey, '\0', sizeof(char) * 2);
		sprintf(strKey, "%d", MyData[i].nIndex);
		// 把該筆資料的Key值存在keyDatum之中
		bzero((void *)&keyDatum, sizeof(datum));
		keyDatum.dptr = (void *)&strKey;
		keyDatum.dsize = strlen(strKey);
		// 把整筆資料儲存在DataDatum之中
		bzero((void *)&dataDatum, sizeof(datum));
		dataDatum.dptr = (void *)&MyData[i];
		dataDatum.dsize = sizeof(MyData);
		// 把我們建立好的Key值和Data儲存在我們的DBM
		nRet = dbm_store(pDBM, keyDatum, dataDatum, DBM_REPLACE);
		if (nRet < 0) {
			fprintf(stderr, "%s %s %s (%d): %s failed on KEY: %s. \r\n", __DATE__, __TIME__, __FILE__, __LINE__, "dbm_store()", strKey);
			dbm_clearerr(pDBM);
			dbm_close(pDBM);
			exit(2);
		}
	}

	// 把DBM中的資料再帶出來驗證一下，
	bzero((void *)&keyDatum, sizeof(datum));
	printf("Original Data: \n");
	for (keyDatum = dbm_firstkey(pDBM); keyDatum.dptr != (char *)NULL; keyDatum = dbm_nextkey(pDBM)) {
		bzero((void *)&dataDatum, sizeof(datum));
		dataDatum = dbm_fetch(pDBM, keyDatum);
		if (dataDatum.dptr != (char *)NULL) {
			bzero((void *)&Data, sizeof(DataDef));
			memcpy(&Data, dataDatum.dptr, dataDatum.dsize);
			printf("%d: %-11s, %4.2f, %c \n", Data.nIndex, Data.strSubject, Data.fScore, Data.cResult);
		}
		else {
			fprintf(stderr, "%s %s %s (%d): %s failed on KEY: %s. \r\n", __DATE__, __TIME__, __FILE__, __LINE__, "dbm_fetch()", keyDatum.dptr);
			dbm_clearerr(pDBM);
			dbm_close(pDBM);
			exit(EXIT_FAILURE);
		}
	}

	dbm_close(pDBM);

	return 0;
}
