#include<stdio.h>
#include<string.h>

int main(void)
{
int a,b;
char fname[20],lname[20];

printf("Please enter your first name: \n");
scanf("%s %s",fname,lname);

a=strlen(fname);
b=strlen(lname);

printf("%s %s\n",fname,lname);
printf("%*d %*d\n",a,a,b,b);
printf("%s %s\n",fname,lname);
printf("%-*d %-*d\n",a,a,b,b);
return 0;
}