/* divide.c -- divisions we have known */
#include <stdio.h>
int main(void)
{
	int i  = 10;
	i = ++i + 1;
	printf("%i\n", i);
   printf("integer division:  5/4   is %d \n", 5/4);
   printf("integer division:  6/3   is %d \n", 6/3);
   printf("integer division:  7/4   is %d \n", 7/4);
   printf("floating division: 7./4. is %1.2f \n", 7./4.);
   printf("mixed division:    7./4  is %1.2f \n", 7./4);
   return 0;
}
