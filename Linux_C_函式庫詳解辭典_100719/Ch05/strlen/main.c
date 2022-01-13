#include <stdio.h>
#include <string.h>

int main(void)
{
	char strA[] = "Hello!! World!! ";
	char *p_strB = "0123456789";
	int nLen = -1;

	nLen = strlen(strA);
	printf("strlen(\"Hello!! World!! \"): %d \n", nLen);

	nLen = strlen(p_strB);
	printf("strlen(\"0123456789\"): %d \n", nLen);
	

	return 0;
}
