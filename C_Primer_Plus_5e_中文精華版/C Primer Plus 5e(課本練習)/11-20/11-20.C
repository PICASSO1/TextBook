#include<stdio.h>
#include<string.h>
#define LISTSIZE 5

int main(void)
{
 int i,count=0;
 //char *list[5]=
 char list[5][13]=
 {
  "astronomy","astounding","astrophysics","ostracize","asterism"
 };

 for(i=0;i<5;i++)
 {
  if(strncmp(list[i],"astro",LISTSIZE)==0)
  {
   printf("Found: %s \n",list[i]);
   count++;
  }
 }
 printf("This list contained %d words beginning with astro. \n",count);
 return 0;
}