#include<stdio.h>
#include<string.h>

int main(int argc,char *argv[],char *envp[])
{
 int i,j;

 printf("The command line has %d arguments: \n",argc-1);

 for(i=1;i<argc;i++)
  printf("%d: %s \n",i,argv[i]);
 printf("\n");

 printf("The Enviorment arguments: \n");
 //printf("%s \n",envp[7]);
 for(j=0;envp[j];j++)      // 可以找出所有的環境變數有那些!!
  printf("%s \n",envp[j]);

 return 0;
}