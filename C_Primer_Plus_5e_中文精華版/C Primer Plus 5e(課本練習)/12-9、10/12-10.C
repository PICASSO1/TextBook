#include <stdio.h>

extern void srand1(unsigned int x);
extern int rand1(void);

int main(void)
{
    int count;
	unsigned seed;

	printf("Please enter your choice for seed (0 to quit): ");
	while(scanf("%u", &seed)==1 && seed!=0)
	{
	    srand1(seed);
	    for(count=0; count<5; count++)
	        printf("%hd\n",rand1());
		printf("Please enter your choice for seed (0 to quit): ");
	}
	printf("Good-Bye!! \n");
	return 0;
}