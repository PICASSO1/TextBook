
/**
 * File Name: main.c
 *
 * CopyLeft (C) 2020, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build022020
 *
 * Date: 2020 / 02 / 20
 *
 * Description: 
 * 1. 這是一個簡單地單向連結串列 (Singly Link List)的範例。
 * 2. 這個連結串列可以儲存5筆資料；設定完之後會依序地 (FIFO; First In, First Out)列印出來；
 * 3. 儲存的方式是每一個新的節點 (Node)都是新增在最後面 (append_back)。
 * 4. 最後，再把每一個Node所儲存的記憶體空間給釋放掉！
 *
 * x. (To do something....)
 *
(*)?*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ptr代表的是整個Link List的開頭！
struct data {
	int val;
	char text[64];
	struct data *next;
} *ptr = (struct data *)NULL;

unsigned int gun_Count = 0;

inline static void append_back(struct data **, int, char *); 
inline static void delete_node(struct data **, int); 
inline static void search_and_delete_node(struct data **, int); 
inline static void display(struct data *); 
inline static void freeLinkList(struct data *); 

int main(void)
{
	int nVal = -1;
	char temp[64];

	while (gun_Count < 5) {
		printf("INPUT: \n");

		printf("NO: ");
		scanf("%d", &nVal);
		if (nVal == 0)
			break;

		printf("TEXT: ");
		memset(temp, '\0', sizeof(char) * 64);
		scanf("%s", temp);
		printf("\n");

		append_back(&ptr, nVal, temp);

		gun_Count++;
	}

	display(ptr);

	printf("Which Node would you want to DELETE?? ");
	nVal = 0;
	scanf("%d", &nVal);

	search_and_delete_node(&ptr, nVal);
	
	display(ptr);

	freeLinkList(ptr);

	return 0;
}

inline static void append_back(head, value, string)
struct data **head;
int value;
char *string; 
{
	struct data *new_node = (struct data *)NULL;
	struct data *last = *head;

	new_node = (struct data *)malloc(sizeof(struct data));
	new_node->val = value;
	strncpy(new_node->text, string, strlen(string));
	new_node->next = (struct data *)NULL;

	if (*head == (struct data *)NULL) {
		*head = new_node;
		return;
	}

	while (last->next != (struct data *)NULL)
		last = last->next;

	last->next = new_node;

	return;
}

inline static void 
delete_node(head, value)
struct data **head;
int value;
{
	struct data *current = *head;
	struct data *prev = (struct data *)NULL;
	
	// 假如傳進來的Link list不是空指標，並且要刪除的節點就是第一筆
	if (current != (struct data *)NULL && current->val == value) {
		// 把第2個節點的記憶體位置設定給head，變成Link list的頭！
		*head = current->next;
		free((void *)current);

		return;
	}
	// 假如傳進來的Link list不是空指標；並且此一節點的值，並非是要刪除的值 (找到就會跳離迴圈)
	while (current != (struct data *)NULL && current->val != value) {
		// 把現在這一個節點，設定給前一個節點
		prev = current;
		// 把下一個節點設定給現在的節點；換句話說就是往下乙筆找
		current = current->next;
	}
	// 假如找到最後一筆了，表示沒找到就離開！
	if (current == (struct data *)NULL)
		return;
	// 把下一筆的節點設給前一筆；然後釋放現在這一個節點。
	prev->next = current->next;
	free((void *)current);

	return;
}

inline static void 
search_and_delete_node(head, value)
struct data **head;
int value;
{
	struct data *current = *head;

	while (current != (struct data *)NULL) {
		if (current->val == value)
			delete_node(head, value);

		current = current->next;
	}

	return;
}

inline static void display(head)
struct data *head; 
{
	printf("\nOutput: \n");

	while (head != (struct data *)NULL) {
		printf("%d: %s \n", head->val, head->text);
		head = head->next;
	}
	printf("\n");

	return;
}

inline static void freeLinkList(head)
struct data *head;
{
	struct data *current = (struct data *)NULL;
	struct data *temp = (struct data *)NULL;

	current = head;
	while (current != (struct data *)NULL) {
		temp = current;
		current = current->next;
		free((void *)temp);
	}

	return;
}
