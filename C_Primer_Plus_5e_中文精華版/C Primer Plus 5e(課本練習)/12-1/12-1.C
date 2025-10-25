#include <stdio.h>

int main(void)
{
 int x=30;

 printf("x in outter block: %d \n",x);      // x=30;
 {
  int x=77;
  printf("x in inner block: %d \n",x);      // x=77;
 }
 printf("x in outter block: %d \n",x);      // x=30;
 while(x++<33)                              // x=30;
 {
  int x=100;      // 因為每次進來，x就被初始化為100，所以101印3次!!
  x++;
  printf("x in while loop: %d \n",x);       // (x=101)*三次;
 }
 return 0;
}