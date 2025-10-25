/* prntval.c -- finding printf()'s return value */
#include <stdio.h>
int main(void)
{
  int bph20 = 212;
  int rv;

  rv = printf("%d F is water's boiling point.\n", bph20);
  printf("The printf() function printed %d characters.\n",
             rv);
  return 0;
}
