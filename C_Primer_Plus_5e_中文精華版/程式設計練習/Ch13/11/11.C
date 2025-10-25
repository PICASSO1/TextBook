#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 256

int main(int argc, char *argv[], char *envp[])
{
	FILE *fp=NULL;
	char *ptr=NULL;
	char strTemp[MAX];

	memset(strTemp, 0, sizeof(strTemp));
	ptr=(char *)calloc(MAX, sizeof(char));

	if(argc==1)
	{
	    puts("請輸入要搜尋的字串和檔案名稱!! ");
		exit(1);
	}
	if(argc==2)
	{
	    puts("請輸入要搜尋的檔案名稱!! ");
		exit(1);
	}
	fp=fopen(argv[2], "rb");
	if(fp==NULL)
	{
	    printf("開啟檔案: %s失敗!! \n", argv[2]);
		fclose(fp);
		exit(1);
	}
	else
	{
	    while(fgets(strTemp, MAX, fp)!=NULL)
		{
		    ptr=strstr(strTemp, argv[1]);
			if(ptr!=NULL)
				printf("%s", strTemp);
		}
		fclose(fp);
	}
	free(ptr);

	return 0;
}
