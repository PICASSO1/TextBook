#include<stdio.h>
#include<string.h>

int main()
{
 int available;
 char flower[30],bug[13];
 char *addon="s smell like old shoes.";

 printf("What's your favorite flower? \n");
 gets(flower);
 if(strlen(addon)+strlen(flower)+1<=30)
  strcat(flower,addon);
 printf("%s \n",flower);
 printf("What's your favorite bug? \n");
 gets(bug);
 available=13-strlen(bug)-1;
 strncat(bug,addon,available);
 puts(bug);
 return 0;
}