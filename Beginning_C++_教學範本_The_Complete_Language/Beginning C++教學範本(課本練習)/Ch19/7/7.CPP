#include <iostream>
#include "Box.H"

using namespace std;

int main(int argc, char *argv[], char *envp[])
{
	Box BigBox(50, 60, 70), SmallBox(2, 3, 4);

	cout << endl;
	cout << "BigBox is " << BigBox << endl;
	cout << "SmallBox is " << SmallBox << endl;

	return 0;
}
