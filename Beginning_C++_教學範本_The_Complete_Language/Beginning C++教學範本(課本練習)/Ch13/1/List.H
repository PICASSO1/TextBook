#ifndef LIST_H
#define LIST_H
#include "Box.H"

using namespace std;

class Package
{
private:
	Box *pBox;
	Package *pNext;
public:
	Package(Box *pNewBox)
	{
		pBox = pNewBox;
		pNext = 0;
	}
	inline Box *getBox(void) const
	{
		return pBox;
	}
	inline Package *getNext(void) const
	{
		return pNext;
	}
	void setNext(Package *pPackage);
};
//==========================================================================
class TruckLoad
{
private:
	Package *pHead;
	Package *pTail;
	Package *pCurrent;
public:
	TruckLoad(Box *pBox = 0, int count = 1)
	{
		pHead = 0;
		pTail = 0;
		pCurrent = 0;

		if((count > 0) && (pBox != 0))
		{
			for(int i(0); i<count; i++)
				addBox(pBox + i);
		}
	}
	Box *getFirstBox(void);
	Box *getNextBox(void);
	void addBox(Box *pBox);
};

#endif