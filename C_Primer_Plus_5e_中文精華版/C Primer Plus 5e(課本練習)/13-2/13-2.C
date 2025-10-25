#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[], char *envp[])
{
    FILE *fpIn=NULL, *fpOut=NULL;
	int nCh=0, nCount=0;
	char strName[40];

	if(argc<2)
	{
	    fprintf(stderr, "Usage: %s filename \n", argv[0]);
		exit(1);
	}
	fpIn=fopen(argv[1], "r");
	if(fpIn==NULL)
	{
	    fprintf(stderr, "I couldn't open the file: \"%s\" \n", argv[1]);
		fclose(fpIn);
		exit(1);
	}
    strcpy(strName, argv[1]);
	strcat(strName, ".red");
	fpOut=fopen(strName, "w");
	if(fpOut==NULL)
	{
	    fprintf(stderr, "Can't create output file. \n");
        fclose(fpOut);
		exit(1);
	}
    while((nCh=getc(fpIn))!=EOF)
	{
	    // if(nCount++%3==0)
			putc(nCh, fpOut);
	}
	if(fclose(fpIn)!=0 || fclose(fpOut)!=0)
	    fprintf(stderr, "Error in closing files. \n");
	return 0;
}