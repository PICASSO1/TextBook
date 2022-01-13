#include <stdio.h>	// for printf() function.
#include <unistd.h>	// for popen() function.
#define SIZE 50	// for char strTemp[] declear.
#include <string.h>	// for bzero() and fgets() function.

int main(void)
{
	FILE *fp = NULL;
	char strTemp[SIZE];

	bzero((void *)strTemp, sizeof(char) * SIZE);
	fp = popen("cat -n /etc/passwd | tail -n 5", "r");
	fgets(strTemp, sizeof(char) * SIZE, fp);	// Only need 1st line.
	printf("%s \n", strTemp);
	pclose(fp);

	return 0;
}
