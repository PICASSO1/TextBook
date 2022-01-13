#include <stdio.h>
#include <string.h>

int main(void)
{
	char strA[] = "Hello!! ", strB[] = "World!! ";

	strcat(strA, strB);
	printf("%s \n", strA);

	return 0;
}
