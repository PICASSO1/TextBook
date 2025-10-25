#include <stdio.h>
void put1(const char *);
int put2(const char *);

void main()
{
 put1("If I'd as much money");
 put1(" as I could spend,\n");
 printf("I count %d characters.\n",put2("I never would cry old chairs to mend."));
 return;
}

void put1(const char *String)
{
 while(*String!='\0')
  putchar(*String++);
}

int put2(const char *String)
{
 int count=0;
 while(*String!='\0')
 {
  putchar(*String++);
  count++;
 }
 putchar('\n');
 return count;
}