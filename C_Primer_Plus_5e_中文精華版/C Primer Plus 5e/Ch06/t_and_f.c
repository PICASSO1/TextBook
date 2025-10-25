/* t_and_f.c -- true and false values in C */
#include <stdio.h>
int main(void)
{
  int true, false;

  true = (10 > 2);    /* value of a true relationship  */
  false = (10 == 2);  /* value of a false relationship */
  printf("true = %d; false = %d \n", true, false);
  return 0;
}
