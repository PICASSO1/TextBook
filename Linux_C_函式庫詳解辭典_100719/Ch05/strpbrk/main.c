#include <stdio.h>
#include <string.h>

int main(void)
{
	char *s = "0123456789012345678901234567890", *p = NULL;

	p = strpbrk(s, "a1 839");
	printf("%s \n", p);
	p = strpbrk(s, "4398");
	printf("%s \n", p);

	return 0;
}
