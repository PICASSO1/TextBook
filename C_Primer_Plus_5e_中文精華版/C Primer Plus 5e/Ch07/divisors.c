// divisors.c -- nested ifs display divisors of a number 
#pragma c9x on     // for CW 6.0
#include <stdio.h>
#include <stdbool.h>
int main(void)
{
   long num;                      // number to be checked 
   long div;                      // potential divisors   
   bool numIsPrime;               // prime flag

   printf("Please enter an integer for analysis; ");
   printf("Enter q to quit.\n");
   while (scanf("%ld", &num) == 1)
   {
      for (div = 2, numIsPrime = true; (div * div) <= num; div++)
      {
         if (num % div == 0)
         {
            if ((div * div) != num)
               printf("%ld is divisible by %ld and %ld.\n",
                   num, div, num / div);
            else
               printf("%ld is divisible by %ld.\n", num, div);
            numIsPrime = false;           // number is not prime  
         }
      }
      if (numIsPrime)
         printf("%ld is prime.\n", num);
      printf("Please enter another integer for analysis; ");
      printf("Enter q to quit.\n");
   }
   return 0;
}
