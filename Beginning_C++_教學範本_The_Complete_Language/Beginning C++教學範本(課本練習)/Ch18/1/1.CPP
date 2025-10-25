#include <iostream>
#include <iomanip>
#include "Box.H"
#include "Array.H"

using namespace std;

int main(int argc, char *argv[], char *envp[])
{
	const int doubleCount(50);
	Array<double> values(doubleCount);
	try
	{
		for(int i(0) ; i<doubleCount; i++)
			values[i] = i + 1;
		cout << "Sums of pairs of elements:";
		int lines = 0;
		for(i = doubleCount - 1; i>=0; i--)
			cout << (lines++ % 5 == 0? "\n": "") << setw(5) << values[i] + values[i - 1];
	}
	catch(const out_of_range &EX)
	{
		cout << endl << "Out of range exception object caught!! " << EX.what() << endl;
	}
	try
	{
		const int boxCount(10);
		Array<Box> boxes(boxCount);
		for(int i(0); i<=boxCount; i++)
			cout << "Box volume is " << boxes[i].volume() << endl;
	}
	catch(const out_of_range &EX)
	{
		cout << "Out of range exception object caught!! " << EX.what() << endl;
	}
	cout << endl;

	return 0;
}
