#include <iostream>
#include <iomanip>
#include "Box.H"
#include "Array.H"

using namespace std;

int main(int argc, char *argv[], char *envp[])
{
	try
	{
		const int size = 21;
		const int start = -10;
		const int end = start + size - 1; // end = 10;
		Array<double, start> values(size);
		for(int i(start); i<end; i++) // for(int i(-10); i<10; i++)
			values[i] = i - start + 1; // µù1:
		cout << "Sums of pairs of elements:";
		int lines = 0;
		for(i = end-1 ; i>=start; i--)
			cout << (lines++ % 5 == 0? "\n": "") << setw(5) << values[i] + values[i - 1]; // µù2:
	}
	catch(const out_of_range &EX)
	{
		cout << endl << "Out of range exception object caught!! " << EX.what() << endl;
	}
	catch(const exception &EX)
	{
		cout << EX.what() << endl;
	}
	try
	{
		const int start = 0;
		const int size = 11;
		Array<Box, start - 5> boxes(size);
		for(int i(start - 5); i<=start + size - 5; i++)
			cout << "Box volume is " << boxes[i].volume() << endl;
	}
	catch(const exception &EX)
	{
		cout << typeid(EX).name() << " exception caught!! " << EX.what() << endl;
	}
	cout << endl;

	return 0;
}
//==========================================================================================
/*
for(int i(-10); i<=10; i++)
{
	values[-10] = (-10) - (-10) + 1 = 1;
	values[-9] = (-9) - (-10) + 1 = 2;
	values[-8] = (-8) - (-10) + 1 = 3;
	values[-7] = (-7) - (-10) + 1 = 4;
	values[-6] = (-6) - (-10) + 1 = 5;
	values[-5] = (-5) - (-10) + 1 = 6;
	values[-4] = (-4) - (-10) + 1 = 7;
	values[-3] = (-3) - (-10) + 1 = 8;
	values[-2] = (-2) - (-10) + 1 = 9;
	values[-1] = (-1) - (-10) + 1 = 10;
	values[0] = 0 - (-10) + 1 = 11;
	values[1] = 1 - (-10) + 1 = 12;
	values[2] = 2 - (-10) + 1 = 13;
	values[3] = 3 - (-10) + 1 = 14;
	values[4] = 4 - (-10) + 1 = 15;
	values[5] = 5 - (-10) + 1 = 16;
	values[6] = 6 - (-10) + 1 = 17;
	values[7] = 7 - (-10) + 1 = 18;
	values[8] = 8 - (-10) + 1 = 19;
	values[9] = 9 - (-10) + 1 = 20;
	values[10] = 10 - (-10) + 1 = 21;
}
*/
/*
for(i = 10; i>=-10; i--)
{
	values[10] + values[10 - 1] = values[10] + values[9] = 21 + 20 = 41;
	values[9] + values[9 - 1] = values[9] + values[8] = 20 + 19 = 39;
	....
}
*/