#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Box.H"
#include "List.H"

using namespace std;

inline int random(int count);
void Show(const Box &aBox);

int main(int argc, char *argv[], char *envp[])
{
	const int dimLimit(100);
	srand((unsigned)time(0));
	const int boxCount(20);
	Box boxes[boxCount];

	for(int i(0); i<boxCount; i++)
		boxes[i] = Box(random(dimLimit), random(dimLimit), random(dimLimit));

	TruckLoad load = TruckLoad(boxes, boxCount);
	Box maxBox = load[0];

	for(i = 1; i<boxCount; i++)
	{
		if(maxBox<load[i])
			maxBox = load[i];
	}
	cout << "The largest box in the list is ";
	Show(maxBox);

	return 0;
}
//================================================================
int random(int count)
{
	return 1 + static_cast<int>((count * static_cast<long>(rand())) / (RAND_MAX + 1));
}
//================================================================
void Show(const Box &aBox)
{
	cout << aBox.getLength() << " by " << aBox.getBreadth() << " by " << aBox.getHeight() << endl;

	return;
}
