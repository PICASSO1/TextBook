#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Box.H"
#include "List.H"
#include "BoxPtr.H"

using namespace std;

inline int random(int count);

int main(int argc, char *argv[], char *envp[])
{
	const int dimLimit(100);
	srand((unsigned)time(0));
	const int boxCount(20);
	Box boxes[boxCount];

	for(int i(0); i<boxCount; i++)
		boxes[i] = Box(random(dimLimit), random(dimLimit), random(dimLimit));

	TruckLoad load = TruckLoad(boxes, boxCount);
//  New!!
	BoxPtr pLoadBox(load);

	Box maxBox = *pLoadBox;
	if(pLoadBox)
		cout << "Volume of first Box is " << pLoadBox->volume() << endl;

	while(++pLoadBox)
	{
		if(maxBox < *pLoadBox)
			maxBox = *pLoadBox;
	}
	cout << "The largest box in the list is " << maxBox.getLength() << " by "
		 << maxBox.getBreadth() << " by " << maxBox.getHeight() << " with volume "
		 << maxBox.volume() << endl;

	return 0;
}
//================================================================
int random(int count)
{
	return 1 + static_cast<int>((count * static_cast<long>(rand())) / (RAND_MAX + 1));
}
