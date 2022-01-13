#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int i = -1;

	for (i = 125; i < 130; i++) {
		if (isascii(i) != 0)
			printf("%d is an ASCII character: %c \n", i, i);
		else
			printf("%d is not an ASCII character. \n", i);
	}

	return 0;
}
