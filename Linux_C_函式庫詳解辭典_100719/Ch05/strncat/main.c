#include <stdio.h>
#include <string.h>

int main(void)
{
	char strA[] = "Hello!! ", strB[] = "World!! ";

	strncat(strA, strB, 3);
	printf("%s \n", strA);

	strncat(strB, "Pablo Picasso G.", 8);
	printf("%s \n", strB);

	return 0;
}
