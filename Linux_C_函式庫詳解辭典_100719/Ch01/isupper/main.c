#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char str[] = "123c@#FDsP[e?";
	int i = -1;

	for (i = 0; str[i] != 0; i++) {
		if (isupper(str[i]) != 0)
			printf("%c is an uppercase character. \n", str[i]);
	}

	return 0;
}
