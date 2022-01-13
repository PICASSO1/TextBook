#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char str[] = "123c  @#  FD\tsP[e?\n";
	int i = -1;

	for (i = 0; str[i] != 0; i++) {
		if (isspace(str[i]) != 0)
			printf("str[%d] is white-space character: %d. \n", i, str[i]);
	}

	return 0;
}
