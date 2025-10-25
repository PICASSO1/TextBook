#include<stdio.h>
#include<string.h>

int main(void)
{
 double prize;
 //char first[20],last[20],formal[50];
 char *first,*last,*formal;
 first=(char *)malloc(20); last=(char *)malloc(20); formal=(char *)malloc(50); 

 puts("Enter your first name:");
 gets(first);
 puts("Enter your last name:");
 gets(last);
 puts("Enter your prize money:");
 scanf("%lf",&prize);
 sprintf(formal,"%s,%-19s,$%6.2f \n",first,last,prize);
 puts(formal);
 free((void *)first); free((void *)last); free((void *)formal); 
 return 0;
}