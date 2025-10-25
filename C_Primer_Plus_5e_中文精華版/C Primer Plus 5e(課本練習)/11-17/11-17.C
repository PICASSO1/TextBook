#include<stdio.h>
#include<string.h>
#define ANSWER "Grant"

main()
{
 char try[40];

 printf("Who is buried in Grant's tomb? \n");
 gets(try);
 while(strcmp(try,ANSWER))      //«D¹s§Y¯u!!
 {
  printf("No,that's wrong!!Try again!! \n");
  gets(try);
 }
 printf("That's right!! \n");
}