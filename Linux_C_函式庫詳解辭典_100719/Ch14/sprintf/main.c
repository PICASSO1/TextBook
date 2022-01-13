#include <stdio.h>

int main(void)
{
	char *a = "This is string A! ";
	char buf[80];
	int nRcv = -1;

	nRcv = sprintf(buf, ">>> %s <<< \n", a);
	printf("nRcv = %d: %s", nRcv, buf);

	return 0;
}
