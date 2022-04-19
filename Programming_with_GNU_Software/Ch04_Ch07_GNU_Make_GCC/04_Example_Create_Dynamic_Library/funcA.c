#include "funcA.h"

void _FunCA(void)
{
	fprintf(stdout, "%s (%d): %s %s\n", __FUNCTION__, __LINE__, __DATE__, __TIME__);
	
	return;
}
