#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE *fp=NULL;
	int ch=0;
	long count=0;
	char strFileName[20], strTemp[16];

	memset(strFileName, 0, sizeof(strFileName));
	memset(strTemp, 0, sizeof(strTemp));

	puts("請輸入檔案名稱: ");
	scanf("%s", &strTemp);
	strcpy(strFileName, "./");
	strcat(strFileName, strTemp);
	fp=fopen(strFileName, "r");
	if(fp==NULL)
	{
	    printf("Can't open %s!! \n", strTemp);
		fclose(fp);
		exit(1);
	}
	while((ch=getc(fp))!=EOF)
	{
	    putc(ch, stdout);
		count++;
	}
	fclose(fp);
	printf("File %s has %ld characters. \n", strTemp, count);

	return 0;
}
