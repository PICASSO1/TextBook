#include<stdio.h>
int main(void)
{
char ch;
int ei=0;
int flag=0;

printf("Please enter a string(# to quit).\n");
while((ch=getchar())!='#')
 {
  if(ch=='e')
   flag=1;
  else
   if(ch=='i')
   {
   ei++;
   flag=0;
   }
   else 
    flag=0;
 }
printf("There are %d \'ei\' string.\n",ei);
return 0;
}