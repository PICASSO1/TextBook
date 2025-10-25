#include <iostream>
#include <algorithm>
#include <list>
#include "Box.H"
#include "TruckLoad.H"

using namespace std;

inline int random(int count)
{
	return 1 + static_cast<int>((count * static_cast<long>(rand())) / (RAND_MAX + 1));
}

inline Box random_Box(int range)
{
	return Box(random(range), random(range), random(range));
}

int main(int argc, char *argv[], char *envp[])
{
	TruckLoad Rig(Box(30, 30, 30));
	for(int i(0); i<8; ++i)
		Rig.add_box(random_Box(100));

	cout << "Contents of Rig 1 " << endl;
	copy(Rig.begin(), Rig.end(), ostream_iterator<Box>(cout, "\n"));
	cout << endl;

	typedef TruckLoad::const_iterator BoxIter; // 這一行compile不會過??
	BoxIter big_one = max_element(Rig.begin(), Rig.end());
	cout << "The biggest box in Rig 1 is " << *big_one << " with volume " << big_one->volume << endl;
	cout << endl;

	cout << "Copying all boxes starting at big box to Rig 2 " << endl;
	TruckLoad Rig2(big_one, Rig.end());
	cout << "Contents of Rig2 " << endl;
	copy(Rig2.begin(), Rig2.end(), ostream_iterator<Box>(cout, "\n"));
	cout << endl;

	return 0;
}
