#include<stdio.h>      // 處理標準輸出入
#include<string.h>     // 處理字串
#include<ctype.h>      // 處理字串裡各別的字元
#define LIMIT 80

void ToUpper(const char *str,char *reString);
int PunctCount(const char *);

int main(void)
{
 char line[LIMIT],reLine[LIMIT];
 memset(line,0,sizeof(line));
 memset(reLine,0,sizeof(reLine));

 puts("Please enter a line:");
 gets(line);
 ToUpper(line,reLine);
 puts(reLine);
 printf("That line has %d punctuation characters. \n",PunctCount(line));

 return 0;
}
//=======================================================================
/*void ToUpper(char *str)      // 把傳進來的字串字母，轉成大寫!!
{
 while(*str)
 {
  *str=toupper(*str);
  str++;
 }
}
以上是課本的範例!! */
void ToUpper(const char *str,char *reString)      // 這一段是我自己寫的!!
{
 int i;
 char temp[1024];
 memset(temp,0,sizeof(temp));

 for(i=0;i<strlen(str);i++)
  temp[i]=toupper(str[i]);
 strcpy(reString,temp);
}
//=======================================================================
/*int PunctCount(const char *str)      // 計算此一字串中，標點符號數!!
{
 int ct=0;

 while(*str)
 {
  if(ispunct(*str))
   ct++;
  str++;
 }
 return ct;
}
以上是課本的範例 */
int PunctCount(const char *str)      // 以下是我自己寫的!!
{
 int i=0,ct=0;

 for(i=0;i<strlen(str);i++)
 {
  if(ispunct(str[i]))
   ct++;
 }
 return ct;
}