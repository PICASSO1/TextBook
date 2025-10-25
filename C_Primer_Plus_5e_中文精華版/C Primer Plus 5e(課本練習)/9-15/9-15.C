#include<stdio.h>
void interchange(int *u,int *v);
int main(void)
{
int x,y;
printf("Please enter two integers, and them will be changed each other. \n");
while(scanf("%d %d",&x,&y)==2)
 {
 printf("Originally x=%d and y=%d. \n",x,y);
 interchange(&x,&y);
 printf("Now x=%d and y=%d. \n",x,y);
 printf("Please enter next two integers(or Q to quit): \n");
 }
return 0;
}

void interchange(int *u,int *v)
{
int temp;
temp=*u;
*u=*v;
*v=temp;
}