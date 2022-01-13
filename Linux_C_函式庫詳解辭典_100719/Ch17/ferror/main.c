#include <stdio.h>

#define	FILE_0	"./TEST.TXT"
#define	FILE_1	"./TEXT.INI"

int main(void)
{
	FILE *fp0 = NULL, *fp1 = NULL;

	fp0 = fopen(FILE_0, "r");
	printf("ferror(fp0): %d \n", ferror(fp0));
	fclose(fp0);

	fp1 = fopen(FILE_1, "r");
	printf("ferror(fp1): %d \n", ferror(fp1));
	fclose(fp1);

	return 0;
}
