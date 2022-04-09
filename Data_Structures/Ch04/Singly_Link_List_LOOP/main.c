
/**
 * File Name: main.c
 *
 * CopyLeft (C) 2020, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build022420
 *
 * Date: 2020 / 02 / 24
 *
 * Description: 
 * 1. 這一個範例是從./Singly_Link_List_LIFO/拷貝過來的；
 * 2. 這一個範例是用來呈現在Link List中產生Loop (迴圈)時該如何處理？
 * 3. Link List會產生Loop的原因，不外乎是原本最後一個節點的next成員應該為NULL值，
 *     結果卻不小小心指到前面已經設定過的節點的記憶體位置，進而產生迴圈。
 * 4. 程序中刻意用create_loop(); 函式來產生迴圈；detect_and_remove_loop(); 函式用來偵測是否有迴圈；
 *     最後再用remove_loop(); 函式把有問題的節點給刪除！
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

static struct data *ptr = (struct data *)NULL;

unsigned int gun_Count = 0;

inline static void append_front(struct data **, int, char *);
inline static void display(struct data *); 
inline static void freeLinkList(struct data *); 

inline static void create_loop(struct data *); 
inline static void remove_loop(struct data *, struct data *); 
inline static void detect_and_remove_loop(struct data *); 

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

		append_front(&ptr, nVal, temp);

		gun_Count++;
	}

	create_loop(ptr);
	
	display(ptr);

	detect_and_remove_loop(ptr);

	display(ptr);

	freeLinkList(ptr);

	return 0;
}

inline static void append_front(head, value, string)
struct data **head;
int value;
char *string; 
{
	struct data *new_node = (struct data *)NULL;

	new_node = (struct data *)malloc(sizeof(struct data));
	new_node->val = value;
	strncpy(new_node->text, string, strlen(string));
	new_node->next = *head;
	*head = new_node;

	return;
}

inline static void create_loop(head)
struct data *head;
{
	struct data *temp = head;

	// 假如Link List的結構成員next不為空指標，表示它並不是最後一個節點 (所以要繼續往下找)；找到最後1個節點才會跳出迴圈。
	while (temp->next != (struct data *)NULL)
		temp = temp->next;

	// 把最後一個節點的next成員的記憶體位置，指回到Link List起頭的第3個成員。若資料為5, 4, 3, 2, 1，就會變成5, 4, 3, 2, 1, 3, 2, 1, 3, 2, 1, 3, 2, 1, 3, 2, 1, ....
	temp->next = head->next->next;

	return;
}

inline static void remove_loop(head, loop_node)
struct data *head; 
struct data *loop_node; 
{
//	int nCnt = 0;
	struct data *near = head;
	struct data *far = head;
	struct data *ptr = loop_node;
	struct data *prev = (struct data *)NULL;

/*	以此一案例而言：5, 4, 3, 2, 1, 3, 2, 1, 3, 2, 1, 3, 2, 1, 3, 2, 1, .... 3是開始重複的節點，這個while loop跑2次時，就會跳出：
	ptr->next為3 (此時ptr應為1)；而far也是3。這個while loop的目的是為了找出那一個節點開始一直重複！
*/	while (ptr->next != loop_node) {
		ptr = ptr->next;
		far = far->next;

	//	printf("%d: ptr->next->val = %d; loop_node->val = %d; far->val = %d \n", nCnt++, ptr->next->val, loop_node->val, far->val);
	}

//	把找到的那一個重複的點節 (far)，先暫時設為前一個節點 (prev)；即5, 4, 3, 2, 1, 3, 2, 1, .... 變成2, 1, 3, 2, 1, ....  (prev = 3)
	prev = far;
	far = far->next;

//	nCnt = 0;
/*	這一個while loop的目的是為了找出那一個節點指回到前面重複的節點 (3)？
	當迴圈只跑2次的時候，far->val = 3; near->val = 3; 此時的prev->val = 1，1就是那個指回到前面重複節點 (3)的問題節點。
*/	while (near != far) {
		prev = far;
		far = far->next;
		near = near->next;

	//	printf("nCnt = %d; prev->val = %d; far->val = %d; near->val = %d \n", nCnt++, prev->val, far->val, near->val);
	}

	// 把那個問題節點的next成員設定成空指標，不要再指回去了！
	prev->next = (struct data *)NULL;

	return;
}

inline static void detect_and_remove_loop(head)
struct data *head;
{
//	int nCnt = 0;
	struct data *slow = head;
	struct data *fast = head;

/*	Slow和Fast的用意為：假設資料為5, 4, 3, 2, 1，Slow跑得是：5, 4, 3, 2, 1；而Fast跑得是：5, 3, 1。正常地情況下Slow跑1次，Fast跑2次，Slow是永遠追不上Fast的；
	但若有產生Loop的情況之下，是一定會追到！while loop的起始條件是：當Link List的前3個成員均不為空指標時，就進入while loop
*/	while (slow != (struct data *)NULL && fast->next != (struct data *)NULL && fast->next->next != (struct data *)NULL) {
	/*	以此一案例而言：5, 4, 3, 2, 1, 3, 2, 1, 3, 2, 1, 3, 2, 1, 3, 2, 1, .... 當while loop跑到第2次時，slow為3，fast->next也為3 (此時fast為1)；
		亦或者跑到第4次時，slow為1，fast->next->next也為1 (此時fast為3)。即5, 4, 3, 2, 1, 3, 2, 1, .... 3是開始被重複的節點。要把它移除！
	*/	if ((slow == fast->next) || (slow == fast->next->next)) {
		/*	printf("nCnt = %d; slow->val = %d; fast->next->val = %d; fast->next->next->val = %d \n", \
				nCnt, slow->val, fast->next->val, fast->next->next->val);
		*/	remove_loop(head, slow);
			return;
		}

	/*	把下一個成員設給Slow；即5, 4, 3, 2, 1變成4, 3, 2, 1, 3, 2, 1, 3, 2, 1, .... 
		把下下一個成員設給Fast；即5, 4, 3, 2, 1變成3, 1, 2, 3, 1, 2, .... 
	*/	slow = slow->next;
		fast = fast->next->next;
		
	//	nCnt++;
	}

	return;
}

inline static void display(head)
struct data *head; 
{
	int nCnt = 0;

	printf("\nOutput: \n");
	while (head != (struct data *)NULL) {
		printf("%d: %s \n", head->val, head->text);
		head = head->next;
		// 因為Link List已經產生Loop了，所以要建立次數，要不然會列印不完！
		if (nCnt++ > 25)
			break;
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
