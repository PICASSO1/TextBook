/*主程式在此*/
#include<stdio.h>
#include "hotel.h"
int main(void)
{
int code,nights;
double hotel;
while((code=menu())!=QUIT)
 {
 switch(code)
  {
  case1:hotel=HOTEL1;
   break;
  case2:hotel=HOTEL2;
   break;
  case3:hotel=HOTEL3;
   break;
  case4:hotel=HOTEL4;
   break;
  default:hotel=0.0;
   printf("Oops! \n");
   break;
  }
 nights=getnights();
 showprice(hotel,nights);
 }
printf("Thank you and goodbye.");
return 0;
}