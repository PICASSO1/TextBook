#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[], char *envp[])
{
	int nB=0;
    double dA=0.000000, dResult=0.000000;

	dA=atof(argv[1]);
	printf("底數為: %lf \n", dA);
	nB=atoi(argv[2]);
	printf("指數為: %d \n", nB);
	dResult=pow(dA, (double)nB);
	printf("所以, %lf的%d次方為: %.6lf \n", dA, nB, dResult);

	return 0;
}
