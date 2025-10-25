#ifndef LIST_H
#define LIST_H
#include "Box.H"

using namespace std;

class TruckLoad
{
private:
	class Package
	{
	public:
		Box *pBox;
		Package *pNext;
		void setNext(Package *pPackage);
		Package(Box *pNewBox)
		{
			pBox = pNewBox;
			pNext = 0;
		}
	};
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
	TruckLoad(const TruckLoad &load)      // 複製建構函數!!
	{
		pHead = 0;
		pTail = 0;
		pCurrent = 0;
		
		if(load.pHead == 0)
			return;

		Package *pTemp = load.pHead;
		do
		{
			addBox(pTemp->pBox);
		}while(pTemp = pTemp->pNext);
	}
	Box *getFirstBox(void);
	Box *getNextBox(void);
	void addBox(Box *pBox);
	Box operator[](int index) const;      // 註標運算子!!
//	~TruckLoad(void);                     // Destructor!!
};

#endif