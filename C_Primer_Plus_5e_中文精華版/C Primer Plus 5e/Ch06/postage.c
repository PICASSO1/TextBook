// postage.c -- first-class postage rates
#include <stdio.h>
int main(void)
{
   const int FIRST_OZ = 34;
   const int NEXT_OZ = 23;
   int ounces, cost;

   printf(" ounces  cost\n");
   for(ounces=1, cost=FIRST_OZ; ounces <= 16; ounces++,
          cost += NEXT_OZ) 
      printf("%5d %7d\n", ounces, cost);
  return 0;
}
