#include<stdio.h>
#define MAXTITL 41
#define MAXAUTL 31

struct book
{
char title[MAXTITL],author[MAXAUTL];
float value;
};

int main(void)
{
struct book libry;
printf("Please enter the book title: \n");
gets(libry.title);
printf("Now enter the author: \n");
gets(libry.author);
printf("Now enter the value: \n");
scanf("%f",&libry.value);
printf("%s by %s: $%.2f. \n",libry.title,libry.author,libry.value);
printf("%s: \"%s\" ($%.2f) \n",libry.title,libry.author,libry.value);
return 0;
}