#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int 
main(void)
{
	FILE *read_fp = (FILE *)NULL;
	char buffer[BUFSIZ + 1];
	int chars_read = 0;

	memset(&buffer, '\0', sizeof(char) * (BUFSIZ + 1));
	read_fp = (FILE *)popen("ps ax", "r");
	if (read_fp != NULL) {
		chars_read = fread(buffer, sizeof(char), BUFSIZ, read_fp);
		while (chars_read > 0) {
			buffer[chars_read - 1] = '\0';
			printf("Reading: -\n %s\n", buffer);
			chars_read = fread(buffer, sizeof(char), BUFSIZ, read_fp);
		}
		pclose(read_fp);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
/*	return 0;	*/
}
