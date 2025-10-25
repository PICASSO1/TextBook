#include<stdio.h>
#define ROW 8

int main(void)
{
int row,col;
char ch;
printf("Please enter a char you want :\n");
scanf("%c",&ch);
for (row=1;row<=ROW;row++)
 {
 for(col=1;col<=row;col++)
  {
  if(ch==123)
   ch=97;
  printf("%c",ch);
  ch+=1;
  }
 printf("\n");
 }
return 0;
}