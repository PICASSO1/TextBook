#include<stdio.h>
#define ANSWER "Grant"

main()
{
 char try[40];

 printf("Who is buried in Grant's tomb? \n");
 gets(try);
 while(try!=ANSWER)      //僅會比較字串所儲存的記憶體位置是否相同!!
 {
  printf("No,that's wrong!!Try again!! \n");
  gets(try);
 }
 printf("That's right!!");
}