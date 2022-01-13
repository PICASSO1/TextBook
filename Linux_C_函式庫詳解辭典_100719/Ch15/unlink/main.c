#include <unistd.h>
#include <stdio.h>

int main(void)
{
	int nRet = 1;
	
	nRet = unlink("./TEXT.TXT");
	if ( nRet != 0 )
		printf("Remove ./TEST.TXT failed!! \n");
	else
		printf("Remove ./TEMP.TXT success!! \n");

	system("ls -l");

	return 0;
}
