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
//		Box *pBox;
		Box &rBox;
		Package *pNext;
		void setNext(Package *pPackage);
		Package(Box &rNewBox): rBox(rNewBox), pNext(0) {}
/*		{
			pBox = pNewBox;
			pNext = 0;
		}
*/		~Package(void)      // Destructor
		{
			cout << "Package destructor called!! " << endl;
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
				addBox(*(pBox + i));
		}
	}
	TruckLoad(const TruckLoad &load)      // ½Æ»s«Øºc¨ç¼Æ!!
	{
		pHead = 0;
		pTail = 0;
		pCurrent = 0;
		
		if(load.pHead == 0)
			return;

		Package *pTemp = load.pHead;
		do
		{
			addBox(pTemp->rBox);
		}while(pTemp = pTemp->pNext);
	}
	~TruckLoad(void);      // Destructor
//	{
//		cout << "TruckLoad destructor called!! " << endl;
//	}
	Box *getFirstBox(void);
	Box *getNextBox(void);
	void addBox(Box &rBox);
};

#endif