#include <stdio.h>
#include <string.h>

int main(void)
{
	int a, b;
    int nArray[7]={1, 2, 3, 4, 5, 6, 7};
	int nCopy[3];

	memset(nCopy, 0, sizeof(nCopy));

	puts("原本的陣列內容: ");
	for(a=0; a<7; a++)
		printf("%d ", nArray[a]);
	putchar('\n');
	for(a=2, b=0; a<5, b<3; a++, b++)
		nCopy[b]=nArray[a];
	puts("複製過的陣列內容: ");
	for(a=0; a<3; a++)
		printf("%d ", nCopy[a]);
	putc('\n', stdout);

	return 0;
}