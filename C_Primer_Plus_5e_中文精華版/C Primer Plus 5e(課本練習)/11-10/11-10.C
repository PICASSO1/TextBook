#include<stdio.h>
#include<string.h>

void put1(const char *string);

int main(void)
{
char word[11];

scanf("%s",&word);
while(strlen(word)<=11)
 {
 put1(&word);      /* This put1 function don't bring enter!! */
 puts(&word);
 return 0;
 }
puts("The word entered length more than 11 bits!!");
}

void put1(const char *string)
{
while(*string!='\0')
 putchar(*string++);
}