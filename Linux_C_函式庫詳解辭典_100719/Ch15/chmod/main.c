#include <sys/types.h>
#include <sys/stat.h>

int 
main()
{
	chmod("./TEXT.TXT", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

	return 0;
}
