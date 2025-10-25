#include <stdio.h>
#include <string.h>
#include <ctype.h>
// #include <conio.h>
#define SIZE1 10
#define SIZE2 81

void ShowMenu(void);
void print(char STR[][SIZE2], size_t n);
void ASCII(char STR[][SIZE2], size_t n);
void Increase(char STR[][SIZE2], size_t n);
void FirstLen(char STR[][SIZE2], size_t n);
size_t CountFirstWord(char *STR);

int main(void)
{
	int a=0;
	char cKey='\0';
	char strMemory[SIZE2], strTemp[SIZE1][SIZE2];

	memset(strTemp, 0, sizeof(strTemp));
	memset(strMemory, 0, sizeof(strMemory));

	puts("請輸入10個字串: ");
	while((fgets(strMemory, SIZE2, stdin)!= NULL) && (strMemory[0]!='\n'))
	{
	    strcpy(strTemp[a], strMemory);
		if(++a>(SIZE1-1))
			break;
	}
	putchar('\n');
    ShowMenu();
	while(scanf("%d", &cKey)==1)
	{
		putchar('\n');
		if(cKey==5)
			break;
	    switch(cKey)
		{
		    case 1: print(strTemp, SIZE1);
				    break;
			case 2: ASCII(strTemp, SIZE1);
				    print(strTemp, SIZE1);
					break;
			case 3: Increase(strTemp, SIZE1);
				    print(strTemp, SIZE1);
					break;
			case 4: FirstLen(strTemp, SIZE1);
				    print(strTemp, SIZE1);
					break;
			case 5: break;
		}
		ShowMenu();
	}
	puts("程式結束!! ");
	return 0;
}
//===================================================================
void ShowMenu(void)
{
    puts("請選擇一個功能: ");
	puts("1. 列印原來的字串表 ");
	puts("2. 列印字串在ASCII的對照順序 ");
	puts("3. 列印字串長度 ");
	puts("4. 列印在字串的第一個字的長度順序 ");
	puts("5. 結束 ");

    return;
}
//===================================================================
void print(char STR[][81], size_t n)      // 1. 列印原本的字串!!
{
    size_t a, nLen=0;

	for(a=0; a<n; a++)
		fputs(STR[a], stdout);

	return;
}
//===================================================================
void ASCII(char STR[][81], size_t n)      // 2. 列印每一字串第一個字母在ASCII中的順序
{
	size_t a, x=0, nPre=0, nPost=0;
	char strTemp[SIZE2];

	memset(strTemp, 0, sizeof(strTemp));

	for(a=0; a<55; a++)
	{
	    nPre=STR[x][0];
		nPost=STR[x+1][0];
		if(nPre>nPost)
		{
		    strcpy(strTemp, STR[x+1]);
			strcpy(STR[x+1], STR[x]);
			strcpy(STR[x], strTemp);
		}
		if(x==(n-2))
			x=0;
		else
			x++;
	}

	return;
}
//===================================================================
void Increase(char STR[][81], size_t n)      // 3. 列印字串長度遞增的順序!!
{
	size_t a, x=0, nPreLen=0, nPostLen=0;
	char strTemp[SIZE2];

	memset(strTemp, 0, sizeof(strTemp));

	for(a=0; a<55; a++)
	{
	    nPreLen=strlen(STR[x]);
		nPostLen=strlen(STR[x+1]);
		if(nPreLen>nPostLen)
		{
		    strcpy(strTemp, STR[x+1]);
			strcpy(STR[x+1], STR[x]);
			strcpy(STR[x], strTemp);
		}
		if(x==(n-2))
			x=0;
		else
			x++;
	}

    return;
}
//=====================================================================
void FirstLen(char STR[][81], size_t n)      // 4. 列印字串第一個字的長度順序
{
	size_t a, x=0, nPreLen=0, nPostLen=0;
	char strTemp[SIZE2];

	memset(strTemp, 0, sizeof(strTemp));

	for(a=0; a<55; a++)
	{
	    nPreLen=CountFirstWord(STR[x]);
		nPostLen=CountFirstWord(STR[x+1]);
		if(nPreLen>nPostLen)
		{
		    strcpy(strTemp, STR[x+1]);
			strcpy(STR[x+1], STR[x]);
			strcpy(STR[x], strTemp);
		}
		if(x==(n-2))
			x=0;
		else
			x++;
	}

	return;
}
//=========================================================================
size_t CountFirstWord(char *STR)      // 計算每個字串第一個字的長度
{
	size_t a, nLen=0, nCount=0;

	nLen=strlen(STR);
	for(a=0; a<nLen; a++)
	{
	    if(!isspace(STR[a]))
			nCount++;
		else // if(isspace(STR[a]))
			break;
	}

	return nCount;
}

/*
測試資料(Test Data):
Hello!!
I'm Pablo Picasso.
And I'm 27 years old.
There are three people in my family.
I always believe I am excellant!!
I study hard.
I want to make a friends with a pretty girl,
Although I never pick up.
Oh......
That's all right!!
*/
