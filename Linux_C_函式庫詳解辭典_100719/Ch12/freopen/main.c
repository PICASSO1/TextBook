#include <stdio.h>

int 
main(void)
{
	FILE *fp = (FILE *)NULL;

	fp = fopen("/etc/passwd", "r");
	fp = freopen("/etc/group", "r", fp);
	fclose(fp);

	return 0;
}
