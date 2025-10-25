/* electric.c -- calculates electric bill */
#include <stdio.h>
#define RATE1 0.11439       /* rate for first 240 kwh      */
#define RATE2 0.12032       /* rate for next 300 kwh       */
#define RATE3 0.14022       /* rate for over 540 kwh       */
#define BREAK1 240.0        /* first breakpoint for rates  */
#define BREAK2 540.0        /* second breakpoint for rates */
#define BASE1 (RATE1 * BREAK1)
                            /* cost for 240 kwh            */
#define BASE2 (BASE1 + (RATE2 * (BREAK2 - BREAK1)))
                            /* cost for 540 kwh            */
int main(void)
{
  double kwh;               /* kilowatt-hours used         */
  double bill;              /* charges                     */

  printf("Please enter the kwh used.\n");
  scanf("%lf", &kwh);       /* %lf for type double         */
  if (kwh <= BREAK1)
      bill = RATE1 * kwh;
  else if (kwh <= BREAK2)   /* kwh between 240 and 540     */
      bill = BASE1 + (RATE2 * (kwh - BREAK1));
  else                      /* kwh above 540               */
      bill = BASE2 + (RATE3 * (kwh - BREAK2));
  printf("The charge for %.1f kwh is $%1.2f.\n", kwh, bill);
  return 0;
}

