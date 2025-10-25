#include <iostream>
#include "Integer.H"

using namespace std;

int Integer::GetnRet(void)
{
	return nRet;
}

void Integer::SetnRet(int RET)
{
	nRet = RET + 2;

	return;
}