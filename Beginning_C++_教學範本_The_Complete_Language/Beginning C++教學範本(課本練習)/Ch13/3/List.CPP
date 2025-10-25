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

	return &pCurrent->rBox;
}

Box *TruckLoad::getNextBox(void)
{
	if(pCurrent)
		pCurrent = pCurrent->pNext;
	else
		pCurrent = pHead;

	return pCurrent? &pCurrent->rBox: 0;
}

void TruckLoad::addBox(Box &rBox)
{
	Package *pPackage = new Package(rBox);

	if(pHead)
		pTail->setNext(pPackage);
	else
		pHead = pPackage;
	pTail = pPackage;

//	delete pPackage;
//	pPackage = 0;

	return;
}

TruckLoad::~TruckLoad(void)      // Destructor
{
	cout << "TruckLoad destructor called!! " << endl;

	while(pCurrent = pHead->pNext)
	{
		delete pHead;
		pHead = pCurrent;
	}
	delete pHead;
}
