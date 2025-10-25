#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Box.H"
#include "List.H"

using namespace std;

inline int random(int count);

int main(int argc, char *argv[], char *envp[])
{
	const int dimLimit(100);
	srand((unsigned)time(0));
	TruckLoad load1;

	for(int i(0); i<10; i++)
		load1.addBox(new Box(random(dimLimit), random(dimLimit), random(dimLimit)));

	Box *pBox = load1.getFirstBox();
	Box *pNextBox;
	while(pNextBox = load1.getNextBox())
	{
		if((pBox->compareVolume(*pNextBox)) < 0)
			pBox = pNextBox;
	}
	cout << "The largest box in the first list is "
		 << pBox->getLength() << " by " << pBox->getBreadth() << " by " << pBox->getHeight() << endl;

	const int boxCount(20);
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
	cout << "The largest box in the second list is "
		 << pBox->getLength() << " by " << pBox->getBreadth() << " by " << pBox->getHeight() << endl;

	pNextBox = load1.getFirstBox();
	while(pNextBox)
	{
		delete pNextBox;
		pNextBox = load1.getNextBox();
	}

	return 0;
}
//================================================================
int random(int count)
{
	return 1 + static_cast<int>((count * static_cast<long>(rand())) / (RAND_MAX + 1));
}
