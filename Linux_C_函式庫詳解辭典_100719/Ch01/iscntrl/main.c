#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int i = -1;

	for (i = 0; i < 35; i++) {
		if (iscntrl(i) == 0)
			printf("%d: \"%c\" is NOT ASCII CnTRL character!! \n", i, i);
	}

	return 0;
}
