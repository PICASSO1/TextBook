#include <stdio.h>
#include <string.h>

int main(void)
{
	char *s = "0123456789012345678901234567890", *p = NULL;

	p = strstr(s, "901");
	printf("%s \n", p);

	return 0;
}
