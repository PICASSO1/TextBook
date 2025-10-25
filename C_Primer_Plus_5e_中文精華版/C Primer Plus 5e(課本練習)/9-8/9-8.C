#include<stdio.h>
void binary(int n);
int main(void)
{
int number;
printf("Enter an interger(Q to quit): \n");
while(scanf("%d",&number)==1)
 {
 printf("Binary equivalent: ");
 binary(number);
 putchar('\n');
 printf("Enter an integer(Q to quit): \n");
 }
printf("Done. \n");
return 0;
}

void binary(int n)
{
int r;
r=n%2;
if(n>=2)
 binary(n/2);
putchar('0'+r);
}