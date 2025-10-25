#include<stdio.h>
#define FUNDLEN 50

struct funds
{
double bankfund,savefund;
char bank[FUNDLEN],save[FUNDLEN];
};

double sum(double,double);

int main(void)
{
struct funds stan=
 {
 2024.72,8237.11,"Garlic-Melon Bank","Lucky's Saving and Loan"
 };
printf("Stan has a total of $%.2f. \n",sum(stan.bankfund,stan.savefund));
return 0;
}

double sum(double x,double y)
{
return (x+y);
}