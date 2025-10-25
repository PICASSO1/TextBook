#include<stdio.h>
/*void mikado(int);*/
int main(void)
{
int pooh,bah;
printf("Please enter two integers: \n");
while(scanf("%d %d",&pooh,&bah)==2)
 {
 printf("In main(), pooh=%d and &pooh=%p \n",pooh,&pooh);
 printf("In main(), bah=%d and &bah=%p \n",bah,&bah);
 printf("Please enter the next two(or Q to Quit): \n");
 }
/*mikado(pooh);*/
return 0;
}

/*void mikado(int bah)
{
int pooh=10;
printf("In main(), pooh=%d and &pooh=%p \n",pooh,&pooh);
printf("In main(), bah=%d and &bah=%p \n",bah,&bah);
}*/