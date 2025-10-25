#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int main(int argc, char *argv[], char *envp[])
int main(void)
{
    FILE *fpIn=NULL, *fpOut=NULL;
	int nCh=0, nCount=0;
//	char strName[40];
	char strTemp[16], strSource[16], strObject[16];

	memset(strTemp, 0, sizeof(strTemp));
	memset(strSource, 0, sizeof(strSource));
	memset(strObject, 0, sizeof(strObject));

/*	if(argc<2)
	{
	    fprintf(stderr, "Usage: %s filename \n", argv[0]);
		exit(1);
	}
*/	puts("請輸入原始檔名: ");
	scanf("%s", &strTemp);
	strcpy(strSource, "./");
	strcat(strSource, strTemp);
	fpIn=fopen(strSource, "r");
	if(fpIn==NULL)
	{
	    fprintf(stderr, "I couldn't open the file: \"%s\" \n", strSource);
		fclose(fpIn);
		exit(1);
	}
//  strcpy(strName, argv[1]);
//	strcat(strName, ".red");
	strcat(strTemp, ".red");
	fpOut=fopen(strTemp, "w");
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
	puts("Copy Successed!! ^^");

	return 0;
}