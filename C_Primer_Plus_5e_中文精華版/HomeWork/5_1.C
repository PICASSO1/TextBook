#include<stdio.h>
#define MIN_PER_HR 60
int main(void)
{
int min,hr,right,rv;

while(rv!=0) 
{
printf("Conver minutes to hours and minutes!\n");
printf("Enter the number of minutes you wish to convert.\n");
rv=scanf("%d",&min);
hr=min/MIN_PER_HR;
right=min%MIN_PER_HR;
printf("%d minutes is %d hours, %d minutes.\n",min,hr,right);
}
return 0;
}
