/* funds3.c -- passing a pointer to a structure */
#include <stdio.h>
#define FUNDLEN 50
struct funds {
    char   bank[FUNDLEN];
    double bankfund;
    char   save[FUNDLEN];
    double savefund;
};
double sum(struct funds moolah);  /* argument is a structure */
int main(void)
{
    struct funds stan = {
        "Garlic-Melon Bank",
        2024.72,
        "Lucky's Savings and Loan",
        8237.11
    };
    printf("Stan has a total of $%.2f.\n", sum(stan));
    return 0;
}
double sum(struct funds moolah)
{
    return(moolah.bankfund + moolah.savefund);
}
