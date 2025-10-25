#include <stdio.h>
#include <string.h>

typedef unsigned int ASS;
void fit(char *String,unsigned int);

void main(void)
{
 char mesg[]="Hold on to your hats, hacker.";
 //memset(mesg,0,sizeof(mesg));
 //puts(mesg);
 fit(mesg,7);
 puts(mesg);
 puts("Let's look at some more of the string.");
 puts(mesg+8);
 return;
}

void fit(char String[],ASS size)
{
 if(strlen(String)>size)
  //*(String+size)='\0';
  String[size]='\0';
}