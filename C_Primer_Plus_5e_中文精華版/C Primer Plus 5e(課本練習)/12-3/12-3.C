#include <stdio.h>

void trystat(void);

int main(void)
{
 int count;
 for(count=1;count<=3;count++)
 {
  printf("Here comes iteration %d: \n",count);
  trystat();
 }
 return 0;
}

//================================================================
void trystat(void)
{
 int fade=1;             // 每次進到這個Function，就重新被初始化
 static int stay=1;      // 因加了ststic後，每次++後的值都被保留

 printf("fade = %d and stay = %d \n",fade++,stay++);
 return;
}