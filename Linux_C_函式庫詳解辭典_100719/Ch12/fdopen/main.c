#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
	FILE *fdp = NULL;

	fdp = fdopen(0, "w+");
	fprintf(fdp, "%s \n", "Hello!! World!!");
	fclose(fdp);

	return 0;
}
