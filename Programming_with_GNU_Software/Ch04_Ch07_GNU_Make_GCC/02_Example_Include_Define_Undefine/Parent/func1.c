#include <stdio.h>

#include "../func2.h"
 
 void myFunC1(int *H)
{
#ifdef AAAAA
	printf("%s (%d): Defined: AAAAA \n", __PRETTY_FUNCTION__, __LINE__);
#else
#error "You don't  define "AAAAA"!! "
#endif
	printf("*H1 = %d \n", *H);
	*H += 2;
	printf("*H2 = %d \n", *H);
	myFunC2(H);
	
	return;
}
