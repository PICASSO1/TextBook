#include <stdio.h>
#include <string.h>

int main(void)
{
	char strA[] = "Hello!! World!! ";
	char strB[] = "Pablo Picasso G.";
	char *p_strC = "0123456789";

	strncpy(strA + 6, strB, 8);
	printf("strA: %s \n", strA);
	strncpy(strB, p_strC + 4, 3);
	printf("strB: %s \n", strB);

	return 0;
}
