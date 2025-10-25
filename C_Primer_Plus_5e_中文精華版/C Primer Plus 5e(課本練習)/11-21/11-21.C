#include<stdio.h>
#include<string.h>

int main(void)
{
 int i=0;
 char temp[40],qwords[5][40];

 printf("Enter %d words beginning with QQ: \n",5);
 while(i<5 && gets(temp))
 {
  //if(temp[0]!='q')
  if(strncmp("QQ",temp,2)!=0)      //改成輸入的字串開頭要以QQ做開頭!!
   printf("%s doesn't beginning with QQ! \n",temp);
  else      //if(temp[0]=='q')
  {
   strcpy(qwords[i],temp);
   i++;
  }
 }
 puts("Here are the words accepted:");
 for(i=0;i<5;i++)
  puts(qwords[i]);
 return 0;
}