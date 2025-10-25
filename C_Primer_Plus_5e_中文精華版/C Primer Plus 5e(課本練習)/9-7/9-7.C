#include<stdio.h>
long fact(int n);
long rfact(int n);
int main(void)
{
int num;
printf("This program calculates factorials. \n");
printf("Enter a value in the rage 0-16(Q to quit): \n");
while(scanf("%d",&num)==1)
 {
 if(num<0)
  printf("No negative number, please. \n");
 else
  if(num>15)
   printf("Keep input under 16. \n");
  else
   {
   printf("loop: %d factorial=%d. \n",num,fact(num));
   printf("Recursion: %d factorial=%d. \n",num,rfact(num));
   }
  printf("Enter a value in the rage 0-16(Q to quit): \n");
 }
printf("Bye! \n");
return 0;
}

long fact(int n)
{
long ans;
for(ans=1;n>1;n--)
 ans*=n;
return ans;
}

long rfact(int n)
{
long ans;
return ans=(n>0)?(n*rfact(n-1)):1;
}
