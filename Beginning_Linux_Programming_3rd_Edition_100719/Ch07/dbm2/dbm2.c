#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
//#include <ndbm.h>
#include <gdbm/ndbm.h>

/*
*	File Name: dbm2.c
*
*	CopyLeft (C) 2016; All rights reserved.
*
*	Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
*
*	Version: 0.0.1.build031516
*
*	Date: 2016 / 03 / 15
*
*	Description: 
*	1. rpm -ivh gdbm-1.11-7.fc24.i686.rpm
*	2. 
*/

#define	TEST_DB_FILE	"/tmp/dbm2_test"
#define	ITEMS_USED	3

struct test_data {
	char misc_chars[15];
	int any_integer;
	char more_chars[21];
};

int 
main()
{
	struct test_data items_to_store[ITEMS_USED], item_retrieved;
	char key_to_use[20];
	int i = -1, result = -1;
	datum key_atum, data_atum;
	DBM *dbm_ptr = (DBM *)NULL;

	dbm_ptr = dbm_open(TEST_DB_FILE, O_RDWR | O_CREAT, 0666);
	if (dbm_ptr == (DBM *)NULL) {
		fprintf(stderr, "Failed to open DataBase!! \n");
		exit(EXIT_FAILURE);
	}

	bzero((void *)&items_to_store, sizeof(struct test_data) * ITEMS_USED);
	strcpy(items_to_store[0].misc_chars, "First!! ");
	items_to_store[0].any_integer = 47;
	strcpy(items_to_store[0].more_chars, "foo");

	strcpy(items_to_store[1].misc_chars, "bar!! ");
	items_to_store[1].any_integer = 13;
	strcpy(items_to_store[1].more_chars, "unlucky? ");

	strcpy(items_to_store[2].misc_chars, "Third!! ");
	items_to_store[2].any_integer = 3;
	strcpy(items_to_store[2].more_chars, "baz");

	for (i = 0; i < ITEMS_USED; i++) {
		memset(key_to_use, '\0', sizeof(char) * 20);
		sprintf(key_to_use, "%c%c%d", items_to_store[i].misc_chars[0], items_to_store[i].more_chars[0], items_to_store[i].any_integer);
		// Ff47, bu13, Tb3
		// 把這一筆資料的KEY值，儲存在key_atum中 ...
		bzero((void *)&key_atum, sizeof(datum));
		key_atum.dptr = (void *)&key_to_use;
		key_atum.dsize = strlen(key_to_use);
		// 把這一筆實體資料，儲存在data_atum中 ...
		bzero((void *)&data_atum, sizeof(datum));
		data_atum.dptr = (void *)&items_to_store[i];
		data_atum.dsize = sizeof(struct test_data);
	
		result = dbm_store(dbm_ptr, key_atum, data_atum, DBM_REPLACE);
		if (result != 0) {
			fprintf(stderr, "dbm_store failed on key: %s \n", key_to_use);
			exit(2);
		}
	}

	memset(key_to_use, '\0', sizeof(char) * 20);
	sprintf(key_to_use, "bu%d", 13);
	key_atum.dptr = (void *)&key_to_use;
//	strcpy(key_atum.dptr, key_to_use);
	key_atum.dsize = strlen(key_to_use);

	if (dbm_delete(dbm_ptr, key_atum) == 0)
		printf("Data with key %s deleted!! \n", key_to_use);
	else
		printf("Nothing delete for key %s \n", key_to_use);

	for (key_atum = dbm_firstkey(dbm_ptr); key_atum.dptr; key_atum = dbm_nextkey(dbm_ptr)) {
		bzero((void *)&data_atum, sizeof(datum));
		data_atum = dbm_fetch(dbm_ptr, key_atum);
		if (data_atum.dptr) {
			printf("Data retrieved: \n");
			bzero((void *)&item_retrieved, sizeof(struct test_data));
			memcpy(&item_retrieved, data_atum.dptr, data_atum.dsize);
			printf("Retrieved item - %s %d %s \n", item_retrieved.misc_chars, item_retrieved.any_integer, item_retrieved.more_chars);
		}
		else
			printf("No data found for key %s \n", key_to_use);
	}

	dbm_close(dbm_ptr);

	return 0;
}
