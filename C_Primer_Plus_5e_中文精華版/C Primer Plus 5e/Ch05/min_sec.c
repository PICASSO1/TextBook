// min_sec.c -- converts seconds to minutes and seconds
#include <stdio.h>
#define SEC_PER_MIN 60       // seconds in a minute 
int main(void)
{
   int sec, min, left;

   printf("Convert seconds to minutes and seconds!\n");
   printf("Enter the number of seconds you wish to convert.\n");
   scanf("%d", &sec);        // number of seconds is read in 
   min = sec / SEC_PER_MIN;  // truncated number of minutes
   left = sec % SEC_PER_MIN; // number of seconds left over
   printf("%d seconds is %d minutes, %d seconds.\n", sec, min,
          left);
   return 0;
}
