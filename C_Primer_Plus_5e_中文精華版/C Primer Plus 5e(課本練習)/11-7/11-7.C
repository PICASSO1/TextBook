#include<stdio.h>

int main(void)
{
int count,i;
char name1[11],name2[11];

for(i=0;i<3;i++)
 {
 printf("Please enter two names!! \n");
 count=scanf("%5s %10s",name1,name2);
 printf("I read the %d names: %s and %s. \n",count,name1,name2);
 }
return 0;
}