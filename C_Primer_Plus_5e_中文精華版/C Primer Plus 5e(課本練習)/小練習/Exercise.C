#include <stdio.h>
#include <string.h>
#include "Exercise.h"

int CheckDot(char *string)
{
    int i, nLen, nResult=0;

    nLen=strlen(string);          // 計算所輸入數字的長度
    if(nLen!=3 || string[0]!='.') // 假如字串長度不等於3,
        return 0;                 // 且第一碼不為小數點，
                                  // 就回傳FALSE
    for(i=1;i<nLen;i++)           // 因為只能第一碼為小數點
    {                             // ，其它不能有，所以從第
        if(string[i]=='.')        // 二碼開始檢查，一檢查到
            return 0;             // 有小數點，就回傳FALSE
    }

    return 1;                     // 以上都不成立就回傳TRUE
}