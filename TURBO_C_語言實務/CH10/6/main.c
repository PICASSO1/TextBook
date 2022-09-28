/**
 * File Name: main.c
 *
 * CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build092722
 *
 * Date: 2022 / 09 / 27
 *
 * Description: 寫一程式要求 user 鍵入月份 (英文名前３個字母簡寫)及日期 (數目)，然後印出該日是一年中的第幾天，請利用底下 struct：
 *              struct {
 *                  char name[10];
 *                  int days;
 *              } moth[12] = {{"Jan", 31}, {"Feb", 28}, .... {"Dec", 31}};
 *
(*)?*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define	SIZE		4

static const struct {
	char name[10];
	int days;
} moth[12] = {
	{"Jan", 31}, {"Feb", 28}, {"Mar", 31}, {"Apr", 30}, {"May", 31}, {"Jun", 30}, 
	{"Jul", 31}, {"Aug", 31}, {"Sep", 30}, {"Oct", 31}, {"Nov", 30}, {"Dec", 31}
};

int chkMonth(char *);
size_t chkDay(size_t, char *);

int main(void)
{
	char temp[SIZE];
	size_t retval_mon = 0U, retval_day = 0U, idx = 0U, total = 0U;

	memset(temp, '\0', sizeof(char) * SIZE);
	fprintf(stdout, "Please input a month, format like: Jan, Feb, Mar, etc.. : ");
	while (fscanf(stdin, "%s", temp) == 1) {
		retval_mon = chkMonth(temp);
		if (retval_mon == -1) {
			fprintf(stderr, "Input ERROR!! Please enter the correct month (like: Jan, Feb, Mar, ... etc..)!! \n");
			while (getchar() != '\n');
			fprintf(stdout, "Please input a month, format like: Jan, Feb, Mar, etc.. : ");
		}
		else
			break;
	}

	fprintf(stdout, "Please input a day for this month (%s): ", moth[retval_mon].name);
	while (fscanf(stdin, "%s", temp) == 1) {
		retval_day = chkDay(retval_mon, temp);
		if (retval_day == 0) {
			fprintf(stderr, "MDFK!! Please enter the correct day!! \n");
			while (getchar() != '\n');
			fprintf(stdout, "Please input a day for this month (%s): ", moth[retval_mon].name);
		}
		else
			break;
	}

	for (idx = 0; idx < retval_mon; idx++)
		total += moth[idx].days;
	total += retval_day;

	fprintf(stdout, "%zu, %s of the year is the %zu day!! \n", retval_day, moth[retval_mon].name, total);

    return 0;
}

int 
chkMonth(STR)
char *STR;
{
	size_t idx = 0U;

	for (idx = 0; idx < 12; idx++) {
		if (strncmp(STR, moth[idx].name, 3) == 0)
			return idx;
	}

	return -1;
}

size_t 
chkDay(IDX, STR)
size_t IDX;
char *STR;
{
	size_t idx = 0U, len = strlen(STR), n = 0U;
	
	for (idx = 0; idx < len; idx++) {
		if (*(STR + idx) < '0' || *(STR + idx) > '9')
			return 0U;
	}

	n = atoi(STR);
	if (n < 1 || n > moth[IDX].days)
		return 0U;

	return n;
}
