// trouble.c -- misuse of = 
// will cause infinite loop
#include <stdio.h>
int main(void)
{
  long num;
  long sum = 0L;
  int status;

  printf("Please enter an integer to be summed. ");
  printf("Enter q to quit.\n");
  status = scanf("%ld", &num);
  while (status = 1)
  {
        sum = sum + num;
        printf("Please enter next integer to be summed. ");
        printf("Enter q to quit.\n");
        status = scanf("%ld", &num);
  }
  printf("Those integers sum to %ld.\n", sum);
  return 0;
}
