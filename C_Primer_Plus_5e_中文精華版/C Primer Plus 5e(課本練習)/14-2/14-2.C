#include<stdio.h>
#define MAXTITL 40
#define MAXTUTL 40
#define MAXBKS 100

struct book
{
char title[MAXTITL],author[MAXTUTL];
float value;
};

int main(void)
{
struct book libry[MAXBKS];
int index,count=0;

printf("Please enter the book title: \n");
printf("press [enter] at the start of a line to stop. \n");
while(count<MAXBKS && gets(libry[count].title)!=NULL
	  &&libry[count].title[0]!='/0')
 {
 printf("Now enter the author: \n");
 gets(libry[count].author);
 
 printf("Now enter the value: \n");
 scanf("%f",&libry[count++].value);
 while(getchar()!='\n')
  continue;
 if(count<MAXBKS)
  printf("Enter the next title. \n");
 }
printf("Here is the list of your books: \n");
for(index=0;index<count;index++)
 printf("%s by %s: $%.2f \n",libry[index].title,libry[index].author,
         libry[index].value);
return 0;
}