/* zeno.c -- series sum */
#include <stdio.h>

int main(void)
{
 int count;
 double time, x;
 int limit;
 printf("How many terms do you want?\n");
 scanf("%d", &limit);

 for (time=0, x=1, count=1; count <= limit; count++, x *= 2.0)
 {
    time += 1.0/x;
    printf("time = %f when count = %d.\n", time, count);
 }
 return 0;
}
