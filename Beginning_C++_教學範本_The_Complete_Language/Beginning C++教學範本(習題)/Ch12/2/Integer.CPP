#include <iostream>
#include "Integer.H"

using namespace std;

int Call_by_Value(Integer RET)
{
	return (RET.getnRet() + 20);
}
//=============================================================
int Call_by_Reference(Integer &RET)
{
	return (RET.getnRet() + 30);
}
