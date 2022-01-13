#include <sys/types.h>
#include <signal.h>

#define	PID	3262	// nice -n -20 scite &

int 
main()
{
	(int)kill(PID, SIGKILL);

	return 0;
}
