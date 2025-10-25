#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[])
{
	FILE *fp=NULL;
	int a;
	char cKey='\0';

	if(argc==1)
	{
		puts("請輸入檔名!! ");
		exit(0);
	}
	for(a=1; a<argc; a++)
	{
	    fp=fopen(argv[a], "rb");
		if(fp==NULL)
		{
		    printf("開啟第%d個檔案失敗!! \n", a);
			fclose(fp);
			exit(1);
		}
		else
		{
		    printf("這是第%d個檔案的內容: \n", a);
			while((cKey=getc(fp))!=EOF)
				putchar(cKey);
			putc('\n', stdout);
			fclose(fp);
		}
	}

	return 0;
}
