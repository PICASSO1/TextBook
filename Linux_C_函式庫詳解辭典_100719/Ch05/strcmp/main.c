#include <stdio.h>
#include <string.h>

int main(void)
{
	char strA[] = "0123456789";
	char strB[] = "1234567890";
	char strC[] = "0123456789";

	if (strcmp(strA, strB) == 0)
		printf("The strA and strB were SAME!! \n");
	else
		printf("The strA and strB were DIFFERENT!! \n");

	if (strcmp(strA, strC) == 0)
		printf("The strA and strC were SAME!! \n");
	else
		printf("The strA and strC were DIFFERENT!! \n");

	return 0;
}
