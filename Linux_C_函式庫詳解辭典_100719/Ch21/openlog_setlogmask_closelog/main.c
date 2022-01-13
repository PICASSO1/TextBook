#include <syslog.h>
#include <stdio.h>

/*
*	File Name: main.c
*
*	CopyLeft (C) 2016; All rights reserved.
*
*	Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
*
*	Version: 0.0.1.build022516
*
*	Date: 2016 / 02 / 25
*
*	Description: 
*	1. Generally speaking, of course, we only use "syslog()" function;
*	2. If you want to more details about syslog feature, to must use -- openlog, setlogmask, closelog function.
*	3. setlogmask() 可以設定LOG訊息的遮罩；有2種使用方式：
*		a). LOG_MASK() ---- 只顯示某一特定等級的訊息，如下例的LOG_ERR;
*		b). LOG_UPTO() ---- 僅顯示某個等級以上的訊息，如註解掉的LOG_NOTICE，LOG_NOTICE以下的訊息不會儲存至rsyslogd.
*	4. You could see: "tail -n 10 /var/log/messages"
*/

int 
main(argc, argv, envp)
int argc;
char *argv[], **envp;
{
	char *ptr = (char *)NULL;
	int logmask = 0;

	ptr = argv[0];	// Copy the process name....
	openlog(ptr, LOG_CONS | LOG_NDELAY | LOG_PERROR | LOG_PID, LOG_USER);
	syslog(LOG_NOTICE | LOG_USER, "Log level ---- (%d). \n", LOG_NOTICE);
	logmask = setlogmask(LOG_MASK(LOG_ERR));
//	logmask = setlogmask(LOG_UPTO(LOG_NOTICE));
	syslog(LOG_EMERG | LOG_USER, "Log level ---- (%d). \n", LOG_EMERG);
	syslog(LOG_ERR | LOG_USER, "Log level ---- (%d). \n", LOG_ERR);
	closelog();

	return 0;
}
