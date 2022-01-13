#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[], char **envp)
{
	char *filename = (char *)NULL;

	if (argc != 2) {
		fprintf(stderr, "Usage: use upper file!! \n");
		exit(1);
	}

	filename = argv[1];
/*	if (!freopen(filename, "r", stdin)) {
		fprintf(stderr, "Couldn't redirect stdin from file: %s \n", filename);
		exit(2);
	}
	execl("./redirection", "redirection", (char *)NULL);
	perror("Couldn't execl()!! \n");
*/
	return 3;
}
