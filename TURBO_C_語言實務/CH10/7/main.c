/**
 * File Name: main.c
 *
 * CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build100222
 *
 * Date: 2022 / 10 / 02
 *
 * Description: 利用１０－２節的串列結構：
 *              struct {
 *                  char info[10];
 *                  struct node *next;
 *              } node;
 *              並定義一個陣列 struct node a[50], *b; 寫一對函式 in(char i); 與 out(char i); 。
 *              in(i) 會由 ａ[] 找一個空ｎｏｄｅ，把字串ｉ存入ｎｏｄｅ，然後把該ｎｏｄｅ有序地加入到一個串列ｂ裡 (最初為空串列)，
 *              out(i) 會把字串ｉ由串列中取出，且由串列中刪去該ｎｏｄｅ，把ｎｏｄｅ清空交還給 ａ[]。
 *
(*)?*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
	char info[10];
	struct node *next;
} a[50], *b = (struct node *)NULL;

const static char *data[10] = {"Peter", "Mary", "John", "May", "Picasso", "Eric", "Sam", "Apple", "Lucia", "Rose"};

void in(const char *);
void out(const char *);

int main(void)
{
	size_t size = 10U, idx = 0U;
	// Initialize the global array .... 
	memset(a, 0x00, sizeof(struct node) * 10);
	for (idx = 0; idx < 2; idx++) {
		strncpy(a[idx].info, data[idx], strlen(data[idx]));
		in(data[idx]);
	}

	// display the content of a[];
/*	for (idx = 0; idx < 10; idx++)
		fprintf(stdout, "a[%zu].info: %s (%zu) \n", idx, a[idx].info, strlen(a[idx].info));
*/
	out(data[0]);
	out(data[1]);

    return 0;
}

void in(const char *NAME)
{
	struct node *current = (struct node *)NULL;
	struct node *last = (struct node *)NULL;

	current = (struct node *)malloc(sizeof(struct node));
	memset(current->info, '\0', sizeof(char) * 10);
	strncpy(current->info, NAME, strlen(NAME));
	current->next = (struct node *)NULL;
	// for testing!!
	fprintf(stdout, "%s: current->info: %s \n", __FUNCTION__, current->info);
	if (b == (struct node *)NULL) {
		b = current;
		return;
	}
	fprintf(stdout, "@@@@\n");
	last = b;
	while (last != (struct node *)NULL) {
		fprintf(stdout, "while: %s \n", last->info);
		last = last->next;
	}
	fprintf(stdout, "QQQQ\n");
	last = current;
	fprintf(stdout, "1234\n");
	return;
}

void out(const char *NAME)
{
	struct node *current = b;
	struct node *head = (struct node *)NULL;
	
	while (current != (struct node *)NULL) {
		printf("%s: current->info: %s \n", __FUNCTION__, current->info);
		current = current->next;
		head = current;
//		printf("%s: current->next->info: %s \n", __FUNCTION__, current->next->info);
		free((void *)head);
	//	strncpy(current->info, NAME, strlen(NAME));
	}

	

	return;
}
