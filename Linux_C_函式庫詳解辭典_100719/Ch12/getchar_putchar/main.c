#include <stdio.h>

int main(void)
{
	int x = -1;
	char cKey = '\0';

	for (x = 0; x < 5; x++) {
		cKey = getchar();
		putchar(cKey);
	}

	return 0;
}
