#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Box.H"

using namespace std;

inline int random(int count);

int main(int argc, char *argv[], char *envp[])
{
	const int dimlimit(100);
	srand((unsigned)time(0));
	const int boxCount(20);
	Box boxes[boxCount];
	for(int i(0); i<boxCount; i++)
		boxes[i] = Box(random(dimlimit), random(dimlimit), random(dimlimit));

	Box *pLargest = &boxes[0];
	for(i = 1; i<boxCount; i++)
	{
		if(*pLargest < boxes[i])
			pLargest = &boxes[i];
	}

	cout << "The box with the largest volume has dimensions: "
		 << pLargest->getLength() << " by "
		 << pLargest->getBreadth() << " by "
		 << pLargest->getHeight() << endl;

	return 0;
}
//====================================================================
inline int random(int count)
{
	return 1 + static_cast<int>((count * static_cast<long>(rand())) / (RAND_MAX + 1));
}
