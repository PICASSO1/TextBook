#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Check(char *STR);
void ShowAll(char *FileName);
void Show(char *Filename, int RET);

int main(int argc, char *argv[], char *envp[])
{
	int nCheck=0;
	char strTemp[6];

	memset(strTemp, 0, sizeof(strTemp));

	if(argc<2)
	{
	    puts("請輸入檔名!! ");
		exit(1);
	}
	puts("請輸入要顯示的字元(數字1~9, 0/7除外, Q/q離開): ");
	while(fgets(strTemp, 6, stdin)!=NULL)
	{
		nCheck=Check(strTemp);
		if(nCheck==-1)
		    puts("輸入錯誤!! 只能輸入一碼數字喔!!");
		else if(nCheck==-2)
			break;
		else if(nCheck==-3)
			puts("就跟你說不能輸入0和7嘛!! 怎麼講都講不聽!! ");
		else if(nCheck==-4)
			ShowAll(argv[1]);
		else // if(isdigit(nCheck))
			Show(argv[1], nCheck);
		puts("請輸入要顯示的字元(數字0~9, 0/7除外, Q/q離開): ");
	}
	puts("好玩吧!! ");

	return 0;
}
//============================================================================
int Check(char *STR)
{
	size_t nLen=0;
	int n=0;

	nLen=strlen(STR);
	if(nLen>2)
		return -1;

	if(STR[0]=='Q' || STR[0]=='q')
		return -2;
	else if(STR[0]=='\n')
		return -4;

	n=atoi(STR);
	if(n==0 || n==7)
		return -3;

	return n;
}
//============================================================================
void ShowAll(char *FileName)
{
	FILE *fp=NULL;
	char cKey='\0';

	fp=fopen(FileName, "rb");
	if(fp==NULL)
	{
	    printf("開啟%s失敗!! \n", FileName);
		fclose(fp);
		exit(1);
	}
	else
	{
	    while((cKey=getc(fp))!=EOF)
		{
		    switch(cKey)
			{
			    case '0': putchar(' ');
					      break;
			    case '1': putchar('.');
					      break;
			    case '2': putchar('\'');
					      break;
			    case '3': putchar(':');
					      break;
			    case '4': putchar('~');
					      break;
			    case '5': putchar('*');
					      break;
			    case '6': putchar('=');
					      break;
//			    case '7': putchar('');      // 沒有'7'喔!!
//					      break;
			    case '8': putchar('%');
					      break;
			    case '9': putchar('#');
					      break;
				case ' ': break;
				default: putchar(cKey);
					     break;
			}
		}
		fclose(fp);
	}
	putchar('\n');

	return;
}
//============================================================================
void Show(char *FileName, int RET)
{
	FILE *fp=NULL;
	char cKey='\0';

	fp=fopen(FileName, "rb");
	if(fp==NULL)
	{
	    printf("開啟%s失敗!! \n", FileName);
		fclose(fp);
		exit(1);
	}
	if(RET==1)
	{
	    while((cKey=getc(fp))!=EOF)
		{
		    if(cKey=='1')
				putchar('.');
			else if(cKey=='\n')
				putchar('\n');
			else if(cKey==' ')
				;
			else // 不是1和空白的都輸出空白!!
				putchar(' ');
		}
	}
	else if(RET==2)
	{
	    while((cKey=getc(fp))!=EOF)
		{
		    if(cKey=='2')
				putchar('\'');
			else if(cKey=='\n')
				putchar('\n');
			else if(cKey==' ')
				;
			else // 不是2和空白的都輸出空白!!
				putchar(' ');
		}
	}
	else if(RET==3)
	{
	    while((cKey=getc(fp))!=EOF)
		{
		    if(cKey=='3')
				putchar(':');
			else if(cKey=='\n')
				putchar('\n');
			else if(cKey==' ')
				;
			else // 不是3和空白的都輸出空白!!
				putchar(' ');
		}
	}
	else if(RET==4)
	{
	    while((cKey=getc(fp))!=EOF)
		{
		    if(cKey=='4')
				putchar('~');
			else if(cKey=='\n')
				putchar('\n');
			else if(cKey==' ')
				;
			else // 不是4和空白的都輸出空白!!
				putchar(' ');
		}
	}
	else if(RET==5)
	{
	    while((cKey=getc(fp))!=EOF)
		{
		    if(cKey=='5')
				putchar('*');
			else if(cKey=='\n')
				putchar('\n');
			else if(cKey==' ')
				;
			else // 不是5和空白的都輸出空白!!
				putchar(' ');
		}
	}
	else if(RET==6)
	{
	    while((cKey=getc(fp))!=EOF)
		{
		    if(cKey=='6')
				putchar('=');
			else if(cKey=='\n')
				putchar('\n');
			else if(cKey==' ')
				;
			else // 不是6和空白的都輸出空白!!
				putchar(' ');
		}
	}
	else if(RET==8)
	{
	    while((cKey=getc(fp))!=EOF)
		{
		    if(cKey=='8')
				putchar('%');
			else if(cKey=='\n')
				putchar('\n');
			else if(cKey==' ')
				;
			else // 不是8和空白的都輸出空白!!
				putchar(' ');
		}
	}
	else if(RET==9)
	{
	    while((cKey=getc(fp))!=EOF)
		{
		    if(cKey=='9')
				putchar('#');
			else if(cKey=='\n')
				putchar('\n');
			else if(cKey==' ')
				;
			else // 不是9和空白的都輸出空白!!
				putchar(' ');
		}
	}
	fclose(fp);
	putchar('\n');

	return;
}
