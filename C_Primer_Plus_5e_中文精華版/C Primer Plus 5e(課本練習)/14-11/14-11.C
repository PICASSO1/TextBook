#include<stdio.h>
#define FUNDLEN 50
#define N 2

struct funds
{
double bankfund,savefund;
char bank[FUNDLEN],save[FUNDLEN];
};

double sum(const struct funds money[],int n);

int main(void)
{
struct funds jones[N]=
{{2024.72,8237.11,"Garlic-Melon Bank","Lucky's Savings and Loan"},
 {1834.28,2903.89,"Honest Jack's Bank","Party Time Savings"}};

printf("Joneses have a total of $%.2f. \n",sum(jones,N));
return 0;
}

double sum(const struct funds money[],int n)
{
int i;
double total;

for(i=0,total=0;i<n;i++)
 total+=money[i].bankfund+money[i].savefund;
return total;
}