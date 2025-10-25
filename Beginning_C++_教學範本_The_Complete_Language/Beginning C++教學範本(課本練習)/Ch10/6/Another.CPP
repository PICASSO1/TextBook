#ifdef TESTFUNCTION
#include <iostream>
#endif
#include "Another.H"

int fun::sum(int x, int y)
{
#ifdef TESTFUNCTION
	std::cout << "Function sum called. " << std::endl;
#endif
	return x+y;
}
//=================================================================
int fun::product(int x, int y)
{
#ifdef TESTFUNCTION
	std::cout << "Function product called. " << std::endl;
#endif
	return x*y;
}
//=================================================================
int fun::difference(int x, int y)
{
#ifdef TESTFUNCTION
	std::cout << "Function difference called. " << std::endl;
#endif
	return x-y;
}
