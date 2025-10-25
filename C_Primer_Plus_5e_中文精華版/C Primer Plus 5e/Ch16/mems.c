// mems.c -- using memcpy() and memmove()
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 10
void show_array(const int ar[], int n);
int main()
{
    int values[SIZE] = {1,2,3,4,5,6,7,8,9,10};
    int target[SIZE];
    double curious[SIZE / 2] = {1.0, 2.0, 3.0, 4.0, 5.0};
    int * pi;
    
    memcpy(target, values, SIZE * sizeof(int));
    puts("target:");
    show_array(target, SIZE);
    pi = (int *) malloc(SIZE * sizeof(int));
    memcpy(pi, values, SIZE  * sizeof(int));
    puts("pi:");
    show_array(pi, SIZE);
    memmove(values + 2, values, 5);  // overlapping ranges
    puts("values");
    show_array(values, SIZE);
    memcpy(target, curious, (SIZE / 2) * sizeof(double));
    puts("target:");
    show_array(target, SIZE);
    
    return 0;
}

void show_array(const int ar[], int n)
{
	int i;
	
	for (i = 0; i < n; i++)
		printf("%d ", ar[i]);
    putchar('\n');
}
