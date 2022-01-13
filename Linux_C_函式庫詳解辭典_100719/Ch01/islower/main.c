#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char str[] = "123c@#FDsP[e?";
	int i = -1;

	for (i = 0; str[i] != 0; i++) {
		if (islower(str[i]) != 0)
			printf("%c is a lower-case character!! \n", str[i]);
	}

	return 0;
}
