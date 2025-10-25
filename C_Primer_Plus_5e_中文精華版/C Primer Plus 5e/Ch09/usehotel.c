/* usehotel.c -- room rate program */
/* compile with  Listing 9.11      */
#include <stdio.h>
#include "hotel.h" /* defines constants, declares functions */
int main(void)
{
   int nights;
   double hotel;
   int code;

   while ((code = menu()) != QUIT)
   {
      switch(code)
      {
      case 1 : hotel = HOTEL1;
               break;
      case 2 : hotel = HOTEL2;
               break;
      case 3 : hotel = HOTEL3;
               break;
      case 4 : hotel = HOTEL4;
               break;
      default: hotel = 0.0;
               printf("Oops!\n");
               break;
      }
      nights = getnights();
      showprice(hotel, nights);
   }
   printf("Thank you and goodbye.");
   return 0;
}
