#include <stdio.h>
#include <stdlib.h>
#define MAX 40
#define TEXT "Text.TXT"

int main(void)
{
    FILE *fp=NULL;
	char words[MAX];

	fp=fopen(TEXT, "a+");
	if(fp==NULL)
	{
	    fprintf(stdin, "Can't open \"Text.TXT\" file!! \n");
		fclose(fp);
		exit(1);
	}
	puts("Enter words to add to the file; press the enter");
	puts("key at the beginning of a line to terminate.");
	while(gets(words)!=NULL && words[0]!='\0')
		fprintf(fp, "%s\n", words);
	puts("File contents: ");
	rewind(fp);
	while(fscanf(fp, "%s", words)==1)
		puts(words);
	if(fclose(fp)!=0)
		fprintf(stderr, "Error closing file. \n");
	return 0;
}