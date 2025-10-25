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
/*	for(a=0; a<10; a++)
		putchar(cTemp[a]);
*/  // 輸出10個字元就停止
	for(a=0; a<25; a++)
	{
	    if(cTemp[a]==' ')      // 遇到空白字元就停止
			break;
		else
			putchar(cTemp[a]);
	}
	putchar('\n');

    return 0;
}
