#include <iostream>
#include "Box.H"
#include "List.H"

using namespace std;

void Package::setNext(Package *pPackage)
{
	pNext = pPackage;

	return;
}
//=======================================================================
Box *TruckLoad::getFirstBox(void)
{
	pCurrent = pHead;

	return pCurrent->getBox();
}

Box *TruckLoad::getNextBox(void)
{
	if(pCurrent)
		pCurrent = pCurrent->getNext();
	else
		pCurrent = pHead;

	return pCurrent? pCurrent->getBox(): 0;
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
