#include <stdio.h>

int main(void)
{
 int n=10;

 printf("Initilly, n = %d \n",n);
 for(int n=1;n<3;n++)
  printf("Loop 1: n = %d \n",n);
 printf("After loop 1, n = %d \n",n);
 for(int n=1;n<3;n++)
 {
  printf("Loop 2 index n = %d \n",n);
  int n=30;
  printf("Loop 2: n = %d \n",n);
  n++;
 }
 printf("After loop 2, n = %d \n",n);
 return 0;
}