#include<stdio.h>
#include<string.h>
#define SIZE 81
#define LIM 20
#define HALF ""

void stsrt(char *strings[],int num);

int main(void)
{
 int k,ct=0;
 char input[LIM][SIZE];      // char input[20][81];
 char *ptstr[LIM];           // char *ptstr[20];

 printf("Input up to %d lines, and I will sort them. \n",LIM);
 printf("To stop, press the Enter key at a line's start. \n");
// 當：所輸入的字串數小於20；且所輸入的字串不是空字串；且所輸入的字串的第一個字元不是空字元
 while(ct<LIM && gets(input[ct])!=NULL && input[ct][0]!='\0')
 {
  ptstr[ct]=input[ct];      // 把所輸入的字串儲存到ptstr[];
  ct++;
 }
 stsrt(ptstr,ct);
 puts("\nHere's the sorted list: \n");
 for(k=0;k<ct;k++)
  puts(ptstr[k]);
 return 0;
}
//================================================================
void stsrt(char *strings[],int num)
{      // 把所輸入的字串，做字串比較!!
 int top,seek;
 char *temp;

 for(top=0;top<num-1;top++)      // 第一個字串；
 {
  for(seek=top+1;seek<num;seek++)      // 第二個字串；
  {
   if(strcmp(strings[top],strings[seek])>0)      // 第一、二個字串做比較!!
   {      // 把字串重新排序!
    temp=strings[top];
	strings[top]=strings[seek];
	strings[seek]=temp;
   }
  }
 }
}