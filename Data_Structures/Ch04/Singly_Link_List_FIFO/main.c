
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

struct data {
	int val;
	char text[64];
	struct data *next;
};

// ptr代表的是整個Link List的開頭！
static struct data *ptr = (struct data *)NULL;

unsigned int gun_Count = 0;

inline static void append_back(struct data **, int, char *); 
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

	freeLinkList(ptr);

	return 0;
}

inline static void append_back(head, value, string)
struct data **head;
int value;
char *string; 
{
	struct data *new_node = (struct data *)NULL;
	// 宣告這一行的用意是為了要找Link List最後一個節點 (Node)
	struct data *last = *head;

	// 先配置一塊記憶體空間，把傳進來的資料都設定好
	new_node = (struct data *)malloc(sizeof(struct data));
	new_node->val = value;
	strncpy(new_node->text, string, strlen(string));
	// 因為傳進來的是最後乙筆資料，所以要把結構的next成員設為NULL
	new_node->next = (struct data *)NULL;

	// 假如傳進來的Link List是一個空指標，表示現在的資料是第一筆，就把這乙筆資料的記憶體位置設定給Link List
	if (*head == (struct data *)NULL) {
		*head = new_node;
		return;
	}

	// 假如Link List的結構成員next不為空指標，表示它並不是最後一個節點 (所以要繼續往下找)
	while (last->next != (struct data *)NULL)
		last = last->next;

	// 找到空指標之後就會跳離while loop，表示以找到最後一個節點；再把現在這乙筆資料的記憶體位置設定給next
	last->next = new_node;

	return;
}

inline static void display(head)
struct data *head; 
{
	printf("\nOutput: \n");
	// 假如傳進函式的Link List不是空指標，代表裡面有資料，就把裡面的資料列印出來！
	while (head != (struct data *)NULL) {
		printf("%d: %s \n", head->val, head->text);
		// 把該筆資料指到下一個Node的記憶體位置，設定給head就可以繼續列印出下一筆資料！
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

	// 把傳進來的Link List設定給current (現在)，表示現在要釋放Node的記憶體空間
	current = head;
	while (current != (struct data *)NULL) {
		// 把現在的Node的記憶體位置，儲存到一個暫存變數 (temp)
		temp = current;
		// 把現在的Node，指到下一個Node的記憶體位置設定回給current
		current = current->next;
		// 把儲存在temp的記憶體位置空間給釋放掉，等同於釋放此一Node的記憶體空間。
		free((void *)temp);
	}

	return;
}
