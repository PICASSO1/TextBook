#include<stdio.h>
#define NAME "MEGATHINK, INC"
#define ADDRESS "10 Megabuck Plaza"
#define PLACE "Megapolice, CA 94904"
#define LIMIT 65

void starbar(void);

int main(void)
{
starbar();
printf("%s\n",NAME);
printf("%s\n",ADDRESS);
printf("%s\n",PLACE);
starbar();
return 0;
}

void starbar(void)
{
int count;
for(count=1;count<=LIMIT;count++)
 putchar('*');
putchar('\n');
}