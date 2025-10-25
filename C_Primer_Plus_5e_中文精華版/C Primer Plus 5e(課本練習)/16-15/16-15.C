#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 懶得想....="=
void show_array(const int ar[], int n);

int main(void)
{
    int values[10]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int target[10];
	double curious[10/2]={1.0, 2.0, 3.0, 4.0, 5.0};
	int *pi=NULL;

	memset(&target, 0, sizeof(&target));

	memcpy(target, values, sizeof(int)*10);      // 記憶體拷貝─後面的拷貝到前面!!
	puts("Target: ");
	show_array(target, 10);
	pi=(int *)calloc(10, sizeof(int));
	memcpy(pi, values, sizeof(int)*10);
	puts("Pi: ");
    show_array(pi, 10);
	memmove(values+2, values, 5);      // 記憶體移動??
	puts("Values");
	show_array(values, 10);
	memcpy(target, curious, sizeof(double)*(10/2));
	puts("Target: ");
	show_array(target, 10);
    free(pi);

	return 0;
}
//=====================================================================================
void show_array(const int ar[], int n)
{
    int i;

	for(i=0; i<n; i++)
		printf("%d ", ar[i]);
	putchar('\n');

	return;
}
