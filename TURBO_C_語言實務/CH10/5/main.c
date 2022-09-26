/**
 * File Name: main.c
 *
 * CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build092522
 *
 * Date: 2022 / 09 / 25
 *
 * Description: 寫一程式讓 user 輸入月、日、年，並以月/日/年的格式印出。
 *
(*)?*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define	SIZE		8

struct {
	int year, month, day;
} data; 

const struct {
	size_t no;
	char *month;
} MONTH[12] = {
	{1, "Jan"}, {2, "Feb"}, {3, "Mar"}, {4, "Apr"}, {5, "May"}, {6, "Jun"}, 
	{7, "Jul"}, {8, "Aug"}, {9, "Sep"}, {10, "Oct"}, {11, "Nov"}, {12, "Dec"}, 
};

size_t chkYear(char *);
size_t chkMonth(char *);
size_t chkDay(char *);

int main(void)
{
	char temp[SIZE];
	size_t ret = 0U;

	memset(temp, '\0', sizeof(char) * SIZE);
	fprintf(stdout, "Please input a year: ");
	while (fscanf(stdin, "%s", temp) == 1) {
		if (chkYear(temp) != 0) {
			fprintf(stderr, "Input ERROR!! Please enter the correct years (0 ~ 9999)!! \n");
			while (getchar() != '\n');
			fprintf(stdout, "Please input a year: ");
		}
		else
			break;
	}
	data.year = atoi(temp);

	memset(temp, '\0', sizeof(char) * SIZE);
	fprintf(stdout, "Please input a month: ");
	while (fscanf(stdin, "%s", temp) == 1) {
		ret = chkMonth(temp);
		if (ret == 0) {
			fprintf(stderr, "Input ERROR!! Please enter the correct month (like: Jun, Feb, Mar, ... etc..)!! \n");
			while (getchar() != '\n');
			fprintf(stdout, "Please input a month: ");
		}
		else
			break;
	}
	data.month = ret;

	memset(temp, '\0', sizeof(char) * SIZE);
	fprintf(stdout, "Please input a day: ");
	while (fscanf(stdin, "%s", temp) == 1) {
		ret = chkDay(temp);
		if (ret == 0) {
			fprintf(stderr, "MDFK!! Please enter the correct day!! \n");
			while (getchar() != '\n');
			fprintf(stdout, "Please input a day: ");
		}
		else
			break;
	}
	data.day = ret;

	fprintf(stdout, "Your input: %s %d, %d \n",MONTH[data.month - 1].month ,data.day, data.year);

    return 0;
}

size_t 
chkYear(YEAR)
char *YEAR;
{
	size_t len = strlen(YEAR), i = 0U, retval = 0U;

	if (len > 4)
		return 1;
	
	for (i = 0; i < len; i++) {
		if (YEAR[i] < '0' || YEAR[i] > '9')
			return 1;
	}

	return retval;
}

size_t 
chkMonth(Month)
char *Month;
{
	size_t j = 0U;

	if (strlen(Month) > 3)
		return 0;
	
	for (j = 0; j < 12; j++) {
		if (strncmp(Month, MONTH[j].month, 3) == 0)
			return MONTH[j].no;
	}

	return 0;
}

size_t 
chkDay(DAY)
char *DAY;
{
	size_t retval = 0U, date = atoi(DAY);
	
	switch (data.month) {
		case 1:	// 31
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			retval = (date < 1 || date > 31)? 0: date;
			break;
		case 2:
			retval = (date < 1 || date > 29)? 0: date;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			retval = (date < 1 || date > 30)? 0: date;
			break;
		default:
			break;
	}

	return retval;
}
