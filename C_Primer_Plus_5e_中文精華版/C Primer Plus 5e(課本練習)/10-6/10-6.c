#include<stdio.h>
#define SIZE 4
int main(void)
{
int i,value1=4,value2=88;
int arr[SIZE];
printf("Value1=%d, Value2=%d \n",value1,value2);
for(i=-1;i<=SIZE;i++)
 arr[i]=2*i+1;
for(i=-1;i<SIZE;i++)
 printf("%2d %d \n",i,arr[i]);
printf("Value1=%d, Value=%d\n",value1,value2);
return 0;
}