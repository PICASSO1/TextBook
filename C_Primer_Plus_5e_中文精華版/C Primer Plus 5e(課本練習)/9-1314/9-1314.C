#include<stdio.h>
void interchangr(int u,int v);
int main(void)
{
int x,y;
printf("This program will changer two integers.");
printf("Please enter two integers: \n");
while(scanf("%d %d",&x,&y)==2)
 {
 printf("Originally x=%d and y=%d. \n",x,y);
 interchangr(x,y);
 printf("Please enter next two integers: \n");
 }
return 0;
}

void interchangr(int u,int v)
{
int temp;
temp=u;
u=v;
v=temp;
printf("Now x=%d and y=%d. \n",u,v);
}