#include<stdio.h>
#include<string.h>

int main()
{
 char *str="One, Two, Three, Four, Five, Four, Three, Two, One";
 char *str1="One",
	  *str2="Two",
	  *str3="Three",
	  *str4="Four",
	  *str5="Five";
 char *temp=NULL;

 printf("%s. \n",str);
 printf("%s. \n",str1);
 printf("%s. \n",str2);
 printf("%s. \n",str3);
 printf("%s. \n",str4);
 printf("%s. \n",str5);

 temp=strpbrk(str,str1); printf("%s. \n",temp);
 temp=strpbrk(str,str2); printf("%s. \n",temp);
 temp=strpbrk(str,str3); printf("%s. \n",temp);
 temp=strpbrk(str,str4); printf("%s. \n",temp);
 temp=strpbrk(str,str5); printf("%s. \n",temp);
 temp=strpbrk(str,"xyz");
 if(temp==NULL)
  printf("The character doesn't exit!! \n");
 else
  printf("%s. \n",temp);

 return 0;
}
/*
char *strpbrk(const char *str1,const char *str2);
這個Function會回傳字串str1中，包函字串str2"任何一個字元"的位置；
若無找到，就回傳空字元。
*/