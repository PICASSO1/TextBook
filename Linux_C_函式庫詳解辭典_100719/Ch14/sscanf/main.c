#include <stdio.h>
#include <string.h>

int 
main()
{
	int i = 0;
	unsigned int j = 0U;
	char input[] = "10 0x1B aaaaaaaa bbbbbbb";
	char s[5];

	memset(s, '\0', sizeof(char) * 5);
	sscanf(input, "%d %X %5[a-z] %*s %f", &i, &j, s, s);
	printf("%d %d %s \n", i, j, s);

	return 0;
}
