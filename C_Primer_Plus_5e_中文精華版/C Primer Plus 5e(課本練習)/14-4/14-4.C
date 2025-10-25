#include<stdio.h>
#define LEN 20

struct name
{
char first[LEN],last[LEN];
};

struct guy
{
struct name handle;
char favfood[LEN],job[LEN];
float income;
};

int main(void)
{
struct guy fellow[2]=
 {
 {{"Chip","Vejer"},"nachos plate","memory broker",36827.00},
 {{"Rodney","Swillbelly"},"salmon mousse","tabloid editor",148500.00}
 };

struct guy *him;
printf("address #1: %p #2: %p \n",&fellow[0],&fellow[1]);
him=&fellow[0];
printf("address #1: %p #2: %p \n",him,him+1);
printf("him->income is $%.2f: (*him).income is $%.2f \n",
	   him->income,(*him).income);
him++;
printf("him->favfood is %s: him->handle.last is %s \n",
	   him->favfood,him->handle.last);
return 0;
}