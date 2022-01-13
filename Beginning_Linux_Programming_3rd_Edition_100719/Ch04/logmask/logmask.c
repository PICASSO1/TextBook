#include <stdio.h>
#include <syslog.h>
#include <unistd.h>

int 
main()
{
	int logmask = 0;

	openlog("logmask", LOG_PID | LOG_CONS, LOG_USER);
	syslog(LOG_INFO | LOG_USER, "Informative message, PID = %d \n", getpid());
	syslog(LOG_DEBUG | LOG_USER, "Debug message, should apear. \n");
	logmask = setlogmask(LOG_UPTO(LOG_NOTICE));
	syslog(LOG_DEBUG | LOG_USER, "Debug message, shouldn't apear. \n");
	closelog();

	return 0;
}
