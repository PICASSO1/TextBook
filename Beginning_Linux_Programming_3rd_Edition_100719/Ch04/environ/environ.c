#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int 
main(argc, argv, envp)
int argc;
char **argv;
char *envp[];
{
	char *var = (char *)NULL, *value = (char *)NULL;

	if (argc == 1 || argc > 3) {
		fprintf(stderr, "Usage: environ var [value] \n");
		exit(EXIT_FAILURE);
	}

	var = argv[1];
	value = getenv(var);
	if (value != NULL)
		fprintf(stdout, "Variable %s has value %s. \n", var, value);
	else
		fprintf(stdout, "Variable %s has no value!! \n", var);

	if (argc == 3) {
		char *string = (char *)NULL;
		value = argv[2];
		string = (char *)malloc(strlen(var) + strlen(value) + 2);
		if (string == NULL) {
			fprintf(stderr, "Out of memery!! \n");
			exit(EXIT_FAILURE);
		}
		strcpy(string, var);
		strcat(string, "=");
		strcat(string, value);
		fprintf(stdout, "Calling putenv with: %s \n", string);
		if (putenv(string) != 0) {
			fprintf(stderr, "Putenv failed!! \n");
			free((void *)string);
			exit(EXIT_FAILURE);
		}

		value = getenv(var);
		if (value != NULL)
			fprintf(stdout, "New value of %s is %s. \n", var, value);
		else
			fprintf(stdout, "New value of %s is NULL. \n", var);
	}

	exit(EXIT_SUCCESS);
//	return 0;
}
