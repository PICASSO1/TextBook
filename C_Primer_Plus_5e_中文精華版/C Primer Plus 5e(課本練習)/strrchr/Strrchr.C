// char *strrchr(const char *string,int c);
#include<stdio.h>
#include<string.h>

int main(void)
{
 char CHARA='t';
 char STR[30]="This is strrchr() function!!";
 char *CHR;

 printf("%s \n",STR);
 printf("%c \n",CHARA);
 printf("This is STR start Address: %p. \n",STR);
 // 秀出STR這個字串起始的記憶體位置
 printf("This is the last \'t\' Address: %p. \n",strrchr(STR,CHARA));
 // 秀出字元t在字串STR中最後一次出現的記憶體位置
 printf("The first \'t\' is in %d code. \n",strrchr(STR,CHARA)-STR+1);
 // 計算出t在字串中是第幾個字母
 CHR=strrchr(STR,CHARA);
 printf("%s \n",CHR);
 // 從最後一次出現t的地方開始列印
 return 0;
/*
這個小程式是在測試char *strrchr(const char *string,int c)這個function。
它會找出在字串string中，最後一次出現字元c的記憶體位置!!
*/
}