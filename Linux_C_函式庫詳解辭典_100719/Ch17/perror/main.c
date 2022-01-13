#include <stdio.h>
#define FILE_NAME	"./TEST.TXT"

int main(void)
{
	FILE *fp = NULL;

	fp = fopen(FILE_NAME, "r");
	if (fp == NULL)
		perror("fopen");
	fclose(fp);

	return 0;
}
