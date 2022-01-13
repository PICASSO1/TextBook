#include <stdio.h>
#include <string.h>

int main(void)
{
	char strA[] = "Hello!! World!! ";
	char strB[] = "Pablo Picasso G.";
	char *p_strC = "0123456789";

	strcpy(strA, strB);
	printf("strA: %s \n", strA);
	strcpy(strB, p_strC);
	printf("strB: %s \n", strB);

	return 0;
}
