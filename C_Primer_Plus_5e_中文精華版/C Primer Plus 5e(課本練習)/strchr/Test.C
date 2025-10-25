//char *strchr(const char *string,int c);
#include<stdio.h>
#include<string.h>

int main(void)
{
 char CHARA='i';
 char STR[30]="This is strchr() function!!";
 char *CHR;

 printf("%s \n",STR);
 printf("%c \n",CHARA);
 printf("This is STR start Address: %p. \n",STR);
 // 秀出STR這個字串起始的記憶體位置
 printf("This is the first \'i\' Address: %p. \n",strchr(STR,CHARA));
 // 秀出字元i在字串STR中第一次出現的記憶體位置
 printf("The first \'s\' is in %d code. \n",strchr(STR,CHARA)-STR+1);
 // 計算出i在字串中是第幾個字母
 CHR=strchr(STR,CHARA);
 printf("%s \n",CHR);
 // 從第一次出現i的地方開始列印
 return 0;
/*
這個小程式是在測試char *strchr(const char *string,int c)這個function。
它會找出在字串string中，第一次出現字元c的記憶體位置!!
*/
}