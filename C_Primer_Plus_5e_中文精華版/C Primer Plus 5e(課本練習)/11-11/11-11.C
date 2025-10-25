#include<stdio.h>
#include<string.h>

int put2(const char *string);

int main(void)
{
int count;
char words[24];

scanf("%s",&words);
while(strlen(words)<=24)
 {
 count=put2(words);
 printf("\n");
 printf("You enter words are %d bit!!\n",count);
 return 0;
 }
}

int put2(const char *string)
{
int total=0;
while(*string!='\0')
 {
 putchar(*string++);
 total++;
 }
return total;
}