#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char str[] = "a5  @;";
	int i = -1;

	for (i = 0; str[i] != 0; i++) {
		if (isgraph(str[i]) != 0)
			printf("str[%d] is PRINTable character: %d \n", i, str[i]);
	}

	return 0;
}
