#include <stdio.h>
#include <string.h>

int main(void)
{
	int a;
	char cTemp[25];

	memset(cTemp, 0, sizeof(cTemp));

	puts("請任意輸入一些字元: ");
	for(a=0; a<25; a++)
		cTemp[a]=getchar();
	putchar('\n');
	puts("剛剛所輸入的字元是: ");
	for(a=0; a<25; a++)
		putchar(cTemp[a]);
	putchar('\n');

    return 0;
}
