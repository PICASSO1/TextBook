#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Box.H"
#include "List.H"

using namespace std;

inline int random(int count);
Box *maxBox(TruckLoad &load); //New!!

int main(int argc, char *argv[], char *envp[])
{
	const int dimLimit(100);
	srand((unsigned)time(0));
	TruckLoad load1;

	for(int i(0); i<3; i++)
		load1.addBox(new Box(random(dimLimit), random(dimLimit), random(dimLimit)));

	Box *pBox = maxBox(load1);

	cout << "The largest box in the first list is "
		 << pBox->getLength() << " by " << pBox->getBreadth() << " by " << pBox->getHeight() << endl;

	TruckLoad load2(load1);
	pBox = maxBox(load2);
/*	const int boxCount(20);
	Box boxes[boxCount];

	for(int j(0); j<boxCount; j++)
		boxes[j] = Box(random(dimLimit), random(dimLimit), random(dimLimit));

	TruckLoad load2(boxes, boxCount);
	pBox = load2.getFirstBox();
	while(pNextBox = load2.getNextBox())
	{
		if(pBox->compareVolume(*pNextBox) < 0)
			pBox = pNextBox;
	}
*/	cout << "The largest box in the second list is "
		 << pBox->getLength() << " by " << pBox->getBreadth() << " by " << pBox->getHeight() << endl;

	for(int j(0); j<5; j++)
		load2.addBox(new Box(random(dimLimit), random(dimLimit), random(dimLimit)));

	pBox = maxBox(load2);

	cout << "The largest box in the extended second list is "
		 << pBox->getLength() << " by " << pBox->getBreadth() << " by " << pBox->getHeight() << endl;

	Box *pNextBox = load1.getFirstBox();
	int count(0);
	while(pNextBox)
	{
		count++;
		pNextBox = load1.getNextBox();
	}
	cout << "First list still contains " << count << " Box objects. " << endl;
	pNextBox = load2.getFirstBox();
	while(pNextBox)
	{
		delete pNextBox;
		pNextBox = load2.getNextBox();
	}

	return 0;
}
//================================================================
int random(int count)
{
	return 1 + static_cast<int>((count * static_cast<long>(rand())) / (RAND_MAX + 1));
}
//================================================================
Box *maxBox(TruckLoad &Load) //New!!
{
	Box *pBox = Load.getFirstBox();
	Box *pNextBox;

	while(pNextBox = Load.getNextBox())
	{
		if(pBox->compareVolume(*pNextBox) < 0)
			pBox = pNextBox;
	}

	return pBox;
}
