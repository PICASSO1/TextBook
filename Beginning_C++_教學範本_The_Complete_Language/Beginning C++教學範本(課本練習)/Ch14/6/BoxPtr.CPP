#include <iostream>
#include "BoxPtr.H"
#include "List.H"

using namespace std;

BoxPtr::BoxPtr(TruckLoad &load): rLoad(load)      // Constructor
{
	pBox = rLoad.getFirstBox();
}
//===================================================================================
Box &BoxPtr::operator *(void) const
{
	if(pBox)
		return *pBox;
	else
	{
		cout << "Dereferencing null BoxPtr";
		exit(1);
	}
}
//====================================================================================
Box *BoxPtr::operator ->(void) const
{
	return pBox;
}
//====================================================================================
Box *BoxPtr::operator ++(void)
{
	return pBox = rLoad.getNextBox();
}
//====================================================================================
const Box *BoxPtr::operator ++(int)
{
	Box *pTemp = pBox;
	pBox = rLoad.getNextBox();

	return pTemp;
}
//=====================================================================================
BoxPtr::operator bool(void)
{
	return pBox != 0;
}
