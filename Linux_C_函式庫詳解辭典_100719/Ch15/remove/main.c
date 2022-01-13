#include <stdio.h>

int main(void) {

	int nRet = 1;

	nRet = remove("./TEMP");
	if ( nRet != 0 )
		printf("Remove ./TEMP/ failed!! \n");
	else
		printf("Remove ./TEMP/ success!! \n");
	
	nRet = 2;
	nRet = remove("./TEST.TXT");
	if ( nRet != 0 )
		printf("Remove ./TEST.TXT failed!! \n");
	else
		printf("Remove ./TEMP.TXT success!! \n");

	system("ls -l");

	return 0;
}
