/* book.c -- one-book inventory */
#include <stdio.h>
#define MAXTITL  41    /* maximum length of title + 1         */
#define MAXAUTL  31    /* maximum length of author's name + 1 */
struct book {          /* structure template: tag is book     */
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};                     /* end of structure template           */
int main(void)
{
    struct book libry; /* declare libry as book-type variable */
    printf("Please enter the book title.\n");
    gets(libry.title);         /* access to the title portion */
    printf("Now enter the author.\n");
    gets(libry.author);
    printf("Now enter the value.\n");
    scanf("%f", &libry.value);
    printf("%s by %s: $%.2f\n",libry.title,
          libry.author, libry.value);
    printf("%s: \"%s\" ($%.2f)\n", libry.author,
          libry.title, libry.value);
    return 0;
}
