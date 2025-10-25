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

 temp=strstr(str,str1); printf("%s. \n",temp);
 temp=strstr(str,str2); printf("%s. \n",temp);
 temp=strstr(str,str3); printf("%s. \n",temp);
 temp=strstr(str,str4); printf("%s. \n",temp);
 temp=strstr(str,str5); printf("%s. \n",temp);
 temp=strstr(str,"six");
 if(temp==NULL)
  printf("These strings don't match!! \n");
 else
  printf("%s. \n",temp);

 return 0;
}
/*
char *strstr(const char *str1,const char *str2);
這個Function會回傳字串str1中，第一次出現字串str2的位置；
若無找到，就回傳空字元。
*/