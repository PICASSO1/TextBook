#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int 
main()
{
	char *ptr = (char *)NULL;

	// To set a new environment - FRED, and its value is "hello"
	if (setenv("FRED", "hello", 0) == -1) {
		perror("setenv");
		exit(EXIT_FAILURE);
	}

	// To get the new environment - FRED
	ptr = getenv("FRED");
	if (ptr == NULL) {
		perror("getenv");
		exit(EXIT_FAILURE);
	}
	printf("The new environment - FRED: %s \n", ptr);

	// Overwrite the environment - FRED to "world"
	if (setenv("FRED", "world", 1) == -1) {
		perror("setenv");
		exit(EXIT_FAILURE);
	}

	ptr = getenv("FRED");
	if (ptr == NULL) {
		perror("getenv");
		exit(EXIT_FAILURE);
	}
	printf("Overwrite the FRED: %s \n", ptr);

	// Unset the new environment - FRED
	unsetenv("FRED");
	ptr = getenv("FRED");
	printf("Unset the FRED: %s \n", (ptr == NULL)? "(null)": ptr);
	
	return 0;
}
