/* booksave.c -- saves structure contents in a file */
#include <stdio.h>
#include <stdlib.h>
#define MAXTITL   40
#define MAXAUTL   40
#define MAXBKS   10             /* maximum number of books */
struct book {                   /* set up book template    */
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};
int main(void)
{
     struct book libry[MAXBKS]; /* array of structures     */
     int count = 0;
     int index, filecount;
     FILE * pbooks;
     int size = sizeof (struct book);

     if ((pbooks = fopen("book.dat", "a+b")) == NULL)
     {
         fputs("Can't open book.dat file\n",stderr);
         exit(1);
     }
     rewind(pbooks);            /* go to start of file     */
     while (count < MAXBKS &&  fread(&libry[count], size,
                 1, pbooks) == 1)
     {
         if (count == 0)
             puts("Current contents of book.dat:");
         printf("%s by %s: $%.2f\n",libry[count].title,
             libry[count].author, libry[count].value);
         count++;
     }
     filecount = count;
     if (count == MAXBKS)
     {
         fputs("The book.dat file is full.", stderr);
         exit(2);
     }
     puts("Please add new book titles.");
     puts("Press [enter] at the start of a line to stop.");
     while (count < MAXBKS && gets(libry[count].title) != NULL
                         && libry[count].title[0] != '\0')
     {
         puts("Now enter the author.");
         gets(libry[count].author);
         puts("Now enter the value.");
         scanf("%f", &libry[count++].value);
         while (getchar() != '\n')
             continue;                /* clear input line  */
         if (count < MAXBKS)
             puts("Enter the next title.");
     }
     puts("Here is the list of your books:");
     for (index = 0; index < count; index++)
         printf("%s by %s: $%.2f\n",libry[index].title,
             libry[index].author, libry[index].value);
     fwrite(&libry[filecount], size, count - filecount,
             pbooks);
     fclose(pbooks);
     return 0;
}
