#include <stdio.h>
#include <string.h>

int 
main()
{
	char tmpname[L_tmpnam];
	char *filename = (char *)NULL;
	FILE *tmpfp = (FILE *)NULL;

	memset(tmpname, '\0',sizeof(char) * L_tmpnam);
	filename = tmpnam(tmpname);
	printf("Temporary file name is %s \n", filename);
	tmpfp = tmpfile();
	if (tmpfp != NULL)
		printf("Open a temporary file OK!! \n");
	else
		perror("tmpfile");

	return 0;
}
