#include <iostream>
#include "Integer.H"

using namespace std;

int main(int argc, char *argv[], char *envp[])
{
	Integer begin(3), end(7);

	cout << "Today's integers are: ";
//	for(; begin != end; ++begin)
//		cout << *begin << " ";
	for(Integer I(begin); I<end; ++I)
	{
		cout << I;
		cout << " ";
	}
	cout << endl;

	return 0;
}

