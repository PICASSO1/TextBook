#include<stdio.h>
#include<string.h>

int main(void)
{
 char *ps,*orig="beast";
 char copy[40]="Be the best that you can be.";

 puts(orig);      //beast
 puts(copy);      //Be the best that you can be.
 //ps=strcpy(copy+7,orig);      //把"beast"拷貝到copy這個字串第七個字元開始的位置
 ps=strncpy(copy+7,orig,5);
 puts(copy);      //Be the beast
 puts(ps);        //beast
 return 0;
}

/* char *strcpy()的回傳值為「目標字串開始的位置」!! */