#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CNTL_Z '\032'
#define SLEN 50

int main(void)
{
	FILE *fp = NULL;
	long lnCount, lnLast = 0;
	char strFile[SLEN];
	char cCh = '\0';
	memset(strFile, 0, sizeof(strFile));

	puts("Enter the name of the file to be processed: ");
	gets(strFile);
	fp = fopen(strFile, "rb");
	if (fp == NULL) {
		fprintf(stdout, "reverse can't open %s \n", strFile);
		fclose(fp);
		exit(1);
	}
	fseek(fp, 0L, SEEK_END);
	lnLast = ftell(fp);
	for (lnCount = 1L; lnCount <= lnLast; lnCount++) {
		fseek(fp, -lnCount, SEEK_END);
		cCh = getc(fp);
		if (cCh != CNTL_Z && cCh != '\r')
			putchar(cCh);
	}
	putchar('\n');
	fclose(fp);

	return 0;
}