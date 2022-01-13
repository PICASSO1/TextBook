#include <syslog.h>

int main(void)
{
	syslog(LOG_EMERG, "This is LOG_EMERG!! \n");
	syslog(LOG_ALERT, "This is LOG_ALERT!! \n");
	syslog(LOG_CRIT, "This is LOG_CRIT!! \n");
	syslog(LOG_ERR, "This is LOG_ERR!! \n");
	syslog(LOG_WARNING, "This is LOG_WARNING!! \n");
	syslog(LOG_NOTICE, "This is LOG_NOTICE!! \n");
	syslog(LOG_INFO, "This is LOG_INFO!! \n");
	syslog(LOG_DEBUG, "This is LOG_DEBUG!! \n");

	return 0;
}
