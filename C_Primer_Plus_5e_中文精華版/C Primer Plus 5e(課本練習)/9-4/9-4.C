#include<stdio.h>
int imax(int,int);

int main(void)
{
int a,b;
printf("Please enter any two number(Q to quit): \n");
while(scanf("%d %d",&a,&b)==2)
 {
 printf("The bigger number is: \n",imax(a,b));
 printf("Please enter any two number(Q to quit): \n");
 }
 return 0;
}

int imax(int m,int n)
{
int max;
return max=(m>n)?m:n;
}