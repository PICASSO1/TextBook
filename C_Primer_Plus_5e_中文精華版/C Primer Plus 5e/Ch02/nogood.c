/* nogood.c -- a program with errors */
#include <stdio.h>
int main(void)
{
  int n, int n2, int n3;
     /* this program has several error */

  n = 5;
  n2 = n * n;
  n3 = n2 * n2;
  printf("n = %d, n squared = %d, n cubed = %d\n", n, n2, n3);
  return 0;
}
