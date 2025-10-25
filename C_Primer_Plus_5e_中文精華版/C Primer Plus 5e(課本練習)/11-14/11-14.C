#include<stdio.h>
#include<string.h>
#define SIZE 80

main()
{
 long lnPos;
 char flower[SIZE];
 char *addon;
 addon=(char *)malloc(25);
 memset(addon,0,sizeof(char)*25);
 strcpy(addon,"s smell like old shoes.");

 puts("What's your favorite flower?");
 gets(flower);
 lnPos=strcat(flower,addon);      //strcat()的回傳值為第一個字串，接第二個字串開始的記憶體位置!!
 puts(flower);
 puts(addon);
 printf("%ld\n",lnPos);
}