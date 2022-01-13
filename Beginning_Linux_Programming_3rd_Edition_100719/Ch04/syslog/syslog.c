#include <stdio.h>
#include <syslog.h>

int 
main()
{
	FILE *fp = (FILE *)NULL;

	fp = fopen("Not_Here", "r");
	if (fp == NULL)
		syslog(LOG_ERR | LOG_USER, "Oops - %m \n");

	return 0;
}
