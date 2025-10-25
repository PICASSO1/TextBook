#include<stdio.h>
#include<string.h>

main()
{
 printf("%d \n",strcmp("A","A"));
 printf("%d \n",strcmp("A","B"));
 printf("%d \n",strcmp("B","A"));
 printf("%d \n",strcmp("C","A"));      //在其它系統下，可能回傳2，即其ASCII碼的差值!!
 printf("%d \n",strcmp("Z","a"));
 printf("%d \n",strcmp("apples","apple"));
}