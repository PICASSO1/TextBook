#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Box.H"

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

	int first(0), second(1);
	double minVolume = (boxes[first] + boxes[second]).volume();

	for(i = 0; i<boxCount-1; i++)
	{
		for(int j(i+1); j<boxCount; j++)
		{
			if(boxes[i] + boxes[j] < minVolume)
			{
				first = i;
				second = j;
				minVolume = (boxes[i] + boxes[j]).volume();
			}
		}
	}
	cout << "The objects that sum to smallest volume are: " << endl;
	cout << "boxes[" << first << "]" << endl;
	Show(boxes[first]);
	cout << "boxes[" << second << "]" << endl;
	Show(boxes[second]);
	cout << "Volume at the sum is " << minVolume << endl;

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
