#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char str[] = "123c  @#  FD	sP[e?";
	int i = -1;

	for (i = 0; str[i] != 0; i++) {
		if (isblank(str[i]) != 0)
			printf("str[%d] is BLANK character: %d \n", i, str[i]);
	}

	return 0;
}
