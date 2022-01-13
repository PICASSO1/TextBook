#define BASIC_DEBUG	1
#define EXTRA_DEBUG	2
#define SUPER_DEBUG	4

#ifdef DEBUG
#include <stdio.h>
#endif

typedef struct {
	char data[4096];
	int key;
} item;

item array[] = {
	{"bill", 3}, 
	{"neil", 4}, 
	{"john", 2}, 
	{"rick", 5}, 
	{"alex", 1}
};

void 
sort(a, n)
item *a;
int n;
{
	int i = 0, j = 0;
	int s = 1;

	for ( ; i < n && s != 0; i++) {
		s = 0;
	/*	for (j = 0; j < n; j++) { */
		for (j = 0; j < n - 1; j++) {
			if (a[j].key > a[j + 1].key) {
				item t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
				s++;
			}
		}
	/*	n--; */
	}
	return;
}

int 
main()
{
#ifdef DEBUG
	int i = 0;
#endif

	sort(array, 5);
#ifdef DEBUG
	for (i = 0; i < 5; i++)
		printf("array[%d] = {%s, %d} \n", i, array[i].data, array[i].key);
#endif
	return 0;
}