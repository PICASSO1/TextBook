#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i=0, max=0, number=0;
	double *ptr=NULL;

	puts("What is the maximum number of type double entries?");
	scanf("%d", &max);
	// ptr=(double *)malloc(max *sizeof(double));
	ptr=(double *)calloc(max, sizeof(double));
	if(ptr==NULL)
	{
	    puts("Memory allocation failed. Goodbye! \n");
		exit(EXIT_FAILURE);
	}

	puts("Enter the values(q to quit):");
	while(scanf("%lf", &ptr[i])==1 && i<max)
		++i;
	printf("Here are your %d entries: \n", number=i);
	for(i=0; i<number; i++)
	{
	    printf("%-7.2f", ptr[i]);
		if(i%7==6)
			putchar('\n');
	}
	if(i%7!=0)
		putchar('\n');
	puts("Done");
	free(ptr);

	return 0;
}