#include <iostream>
#include "Box.H"
#include "List.H"

using namespace std;

void TruckLoad::Package::setNext(Package *pPackage)
{
	pNext = pPackage;

	return;
}

Box *TruckLoad::getFirstBox(void)
{
	pCurrent = pHead;

	return pCurrent->pBox;
}

Box *TruckLoad::getNextBox(void)
{
	if(pCurrent)
		pCurrent = pCurrent->pNext;
	else
		pCurrent = pHead;

	return pCurrent? pCurrent->pBox: 0;
}

void TruckLoad::addBox(Box *pBox)
{
	Package *pPackage = new Package(pBox);

	if(pHead)
		pTail->setNext(pPackage);
	else
		pHead = pPackage;
	pTail = pPackage;

//	delete pPackage;
//	pPackage = 0;

	return;
}
