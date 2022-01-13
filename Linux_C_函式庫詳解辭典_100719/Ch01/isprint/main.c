#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char str[] = "a5  @;";
	int i = -1;

	for (i = 0; str[i] != 0; i++) {
		if (isprint(str[i]) != 0)
			printf("str[%d] is printable character: %d. \n", i, str[i]);
	}

	return 0;
}
