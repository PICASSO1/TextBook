/**
 * File Name: main.c
 *
 * CopyLeft (C) 2022, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build100322
 *
 * Date: 2022 / 10 / 03
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
void display();

int main(void)
{
	size_t size = 10U, idx = 0U;
	// Initialize the global array .... 
	memset(a, 0x00, sizeof(struct node) * 10);

	for (idx = 0; idx < 10; idx++) {
		strncpy(a[idx].info, data[idx], strlen(data[idx]));
		in(data[idx]);
	}

	// display the content of the Link List *b;
	display();

	for (idx = 0; idx < 10; idx++)
		out(data[idx]);

    return 0;
}

void in(const char *NAME)
{
	struct node *current = (struct node *)NULL;
	struct node *last = b;
	// Initialize a structure first
	current = (struct node *)malloc(sizeof(struct node));
	memset(current->info, '\0', sizeof(char) * 10);
	strncpy(current->info, NAME, strlen(NAME));
	current->next = (struct node *)NULL;

	if (b == (struct node *)NULL) {
		b = current;

		return;
	}

	while (last->next != (struct node *)NULL)
		last = last->next;

	last->next = current;

	return;
}

void display(void)
{
	struct node *current = b;

	while (current != (struct node *)NULL) {
		fprintf(stdout, "%s (%d): current->info: %s (%zu) \n", __FUNCTION__, __LINE__, current->info, strlen(current->info));
		current = current->next;
	}

	return;
}

void out(const char *NAME)
{
	struct node *current = b;
	struct node *head = (struct node *)NULL;
	
	while (current != (struct node *)NULL && strncmp(current->info, NAME, strlen(NAME)) == 0) {
		head = current->next;
		fprintf(stdout, "%s (%d): release -- %s -- \n", __FUNCTION__, __LINE__, current->info);
		free((void *)current);

		return;
	}

	while (current != (struct node *)NULL && strncmp(current->info, NAME, strlen(NAME)) != 0) {
		head = current;
		current = current->next;
	}

	if (current == (struct node *)NULL)
		return;

	head->next = current->next;
	fprintf(stdout, "%s (%d): release -- %s -- \n", __FUNCTION__, __LINE__, current->info);
	free((void *)current);

	return;
}
