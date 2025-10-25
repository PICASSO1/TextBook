#include<stdio.h>
#include<string.h>

main()
{
 int Pos=0;
 char input[100][81];

 puts("Enter up to 100 lines(type quit to quit):");
 while(Pos<100 && gets(input[Pos])!=NULL && strcmp(input[Pos],"quit")!=0)
 //while(Pos<100 && gets(input[Pos])!=NULL && input[Pos][0]!='\0')
  Pos++;
 printf("%d strings entered. \n",Pos);
}