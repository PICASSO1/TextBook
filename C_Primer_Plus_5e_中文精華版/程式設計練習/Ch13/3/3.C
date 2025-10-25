#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
	FILE *fp1=NULL, *fp2=NULL;
	int a=0;
	char cKey='\n';
	char strTemp[512], strOrignalFile[16], strObjectFile[16], strOrignal[16], strObject[16];

	memset(strTemp, 0, sizeof(strTemp));
	memset(strOrignal, 0, sizeof(strOrignal));
	memset(strObject, 0, sizeof(strObject));
	memset(strOrignalFile, 0, sizeof(strOrignalFile));
	memset(strObjectFile, 0, sizeof(strObjectFile));

	puts("請輸入原始檔案名稱: ");
	scanf("%s", strOrignal);
	puts("請輸入目的檔案名稱: ");
	scanf("%s", strObject);
	if(strcmp(strOrignal, strObject)==0)
	{
	    puts("來源檔及目的檔不可相同!!");
		exit(1);
	}
	strcpy(strOrignalFile, "./");
	strcpy(strObjectFile, "./");
	strcat(strOrignalFile, strOrignal);
	strcat(strObjectFile, strObject);
	fp1=fopen(strOrignalFile, "rb");
	fp2=fopen(strObjectFile, "ab");
	if(fp1==NULL)
	{
	    puts("開啟原始檔案失敗!! ");
		fclose(fp1);
		exit(1);
	}
	if(fp2==NULL)
	{
	    puts("開啟目的檔案失敗!! ");
		fclose(fp2);
		exit(1);
	}
	
	while((cKey=getc(fp1))!=EOF)
	    putc(toupper(cKey), fp2);

	fclose(fp1);
	fclose(fp2);
	puts("複製完成!! ");

	return 0;
}
