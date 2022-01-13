#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char **envp)
{
	FILE *fp = NULL;
	int ch = 0;
	long count = 0;

	if (argc != 2) {
		printf("Usage: %s filename. \n", argv[0]);
		exit(1);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		printf("Can't open %s", argv[1]);
		fclose(fp);
		exit(1);
	}
	while ((ch = getc(fp)) != EOF) {
		putc(ch, stdout);
		count++;
	}
	fclose(fp);
	printf("File %s has %ld characters. \n", argv[1], count);

	return 0;
}