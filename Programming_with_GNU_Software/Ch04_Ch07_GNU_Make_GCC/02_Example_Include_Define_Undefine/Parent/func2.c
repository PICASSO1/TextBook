 #include <stdio.h>
 
 void myFunC2(int *EE)
{
#ifndef BBBBB
	printf("%s (%d): Non-Defined: BBBBB \n", __func__, __LINE__);
#else
#error "You  define "BBBBB"!! "
#endif	
	printf("*EE1 = %d \n", *EE);
	*EE += 2;
	printf("*EE2 = %d \n", *EE);

	return;
}
