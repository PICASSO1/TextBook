#include <stdio.h>
#include <string.h>

char *itobs(int, char *);

int main(void)
{
	int number=0;
    char bin_str[8*sizeof(int)+1];
	memset(bin_str, 0, sizeof(bin_str));

	puts("Enter integers and see them in binary: ");
	puts("Non-numeric input terminates program. ");
	while(scanf("%d", &number)==1)
		fprintf(stdout, "%d is %s \n", number, itobs(number, bin_str));

	return 0;
}
//======================================================================
char *itobs(int n, char *ps)
{
    int i;
	static int size=8*sizeof(int);

	for(i=size-1; i>=0; i--,n>>=1)
        ps[i]=(01&n)+'0';
	ps[size]='\0';

	return ps;
}