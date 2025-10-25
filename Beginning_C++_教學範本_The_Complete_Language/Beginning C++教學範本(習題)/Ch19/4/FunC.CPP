#include <iostream>
#include "FunC.H"
#include <cstring>
#include <cstdlib>
#include <conio.h>

using namespace std;

void UnSpace(char *TEMP)
{
	size_t nLen = strlen(TEMP), i = 0, j = 0, nSpace = 0;
	char *strTemp = 0;
	strTemp = new char[nLen + 1];

	memset(strTemp, '\0', sizeof(char)*(nLen+1));

	while(i < nLen)      // 先計算前置空白有幾個
	{
		if(TEMP[i++] == ' ')
		{
			nSpace++;
			continue;
		}
		else
			break;
	}
	strncpy(strTemp, TEMP + nSpace, nLen - nSpace + 1);      // 移除前置空白
	strcpy(TEMP, strTemp);
	nLen = strlen(TEMP);
	memset(strTemp, '\0', sizeof(char)*(nLen+1));
	i = 0;
	while(TEMP[i] != '\0')      // 移除字串中多餘的空白
	{
		if(TEMP[i] == ' ')
		{
			if(TEMP[i - 1] != ' ')
				strTemp[j++] = TEMP[i];
			i++;
		}
		else
			strTemp[j++] = TEMP[i++];
	}
	strcpy(TEMP, strTemp);
	delete []strTemp;
	strTemp = 0;
	for(i = 0; i<strlen(TEMP); i++)      // 將小寫字母轉大寫
		TEMP[i] = toupper(TEMP[i]);

	return;
}
//==============================================================================================
int Show(void)
{
	int nRet = 0;

	cout << "1. 從鍵盤輸入 2. 從檔案讀取 3. 離開程式: ";
	nRet = getch();

	return nRet;
}
