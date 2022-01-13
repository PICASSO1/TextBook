#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	TEXT	"./Text.TXT"

int main(void)
{
	FILE *fp = NULL;
	char str[128];

	fp = fopen(TEXT, "r");
	if (fp == NULL) {
		fprintf(stderr, "Can't open file!! \n");
		exit(1);
	} 

	while (feof(fp) == 0) {
		memset(str, '\0', sizeof(char) * 128);
		if (fgets(str, 128, fp) != NULL)
			printf("%s", str);
	}
	fclose(fp);

	return 0;
}
