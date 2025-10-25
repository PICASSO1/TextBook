#include <stdio.h>

int units=0;      // "定義宣告"一個全域變數，並給予初始化!!
void critic(void);

int main(void)
{
 // extern int units;  // "參考宣告"，表示在此一Func外已宣告過了!!

 printf("How many pounds to a firkin of butter?? \n");
 scanf("%d",&units);
 while(units!=56)
  critic();
 printf("You must have looked it up!! \n");
 return 0;
}
//====================================================
void critic(void)
{
 printf("No luck, chummy. Try again. \n");
 scanf("%d",&units);
}