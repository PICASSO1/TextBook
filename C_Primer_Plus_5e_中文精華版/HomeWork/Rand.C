#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 6
#define random(x) (rand()%(x))
#define randomize() srand((unsigned)time(NULL))
int main(void)
{
int count[MAX]={0};
int i;
randomize();
for(i=1;i<=500;i++)
 {
 switch(random(MAX)+1)
  {
  case 1:
   count[0]++;
   break;
  case 2:
   count[1]++;
   break;
  case 3:
   count[2]++;
   break;
  case 4:
   count[3]++;
   break;
  case 5:
   count[4]++;
   break;
  case 6:
   count[5]++;
   break;
  }
 }
printf("NUM | count\n");
for(i=0;i<MAX;i++)
 {
 printf("%-3d | %-5d\n",i+1,count[i]);
 }
 printf("total %-3d\n",count[0]+count[1]+count[2]+count[3]+count[4]+count[5]);
 }