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
		const int startValues = -10;
		const int endValues = startValues + size - 1;  // endValues = (-10) + 21 - 1 = 10
		Array<double> values(size, startValues);       // values(21, -10);
		for(int i(startValues); i<=endValues; i++)     // µù1:
			values[i] = i - startValues + 1;

		const int startData = startValues + 5;         // startData = -5;
		const int endData = endValues + 5;             // endData = 15;
		Array<double> data(size, startData);           // data(21, -5);
		for(int j = startData, k = startValues; k<=endValues; k++, j++) // µù2:
			data[j] = values[k];
		cout << "Sums of pairs of elements: ";

		int lines = 0;
		for(i = endData-1 ; i >= startData; i--)         // µù3:
			cout << (lines++ % 5 == 0? "\n": "") << setw(5) << data[i] + data[i - 1];
	}
	catch(const exception &EX)
	{
		cout << endl << "Out of range exception object caught!! " << EX.what() << endl;
	}
	cout << endl;

	return 0;
}
//============================================================================================
/*
for(int i = -10; i <= 10; i++)
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
//----------------------------------------------------------------------------------------------
/*
for(int j = -5, k = -10; k <= 10; k++, j++)
{
	data[-5] = values[-10] = 1;
	data[-4] = values[-9] = 2;
	data[-3] = values[-8] = 3;
	data[-2] = values[-7] = 4;
	data[-1] = values[-6] = 5;
	data[0] = values[-5] = 6;
	data[1] = values[-4] = 7;
	data[2] = values[-3] = 8;
	data[3] = values[-2] = 9;
	data[4] = values[-1] = 10;
	data[5] = values[0] = 11;
	data[6] = values[1] = 12;
	data[7] = values[2] = 13;
	data[8] = values[3] = 14;
	data[9] = values[4] = 15;
	data[10] = values[5] = 16;
	data[11] = values[6] = 17;
	data[12] = values[7] = 18;
	data[13] = values[8] = 19;
	data[14] = values[9] = 20;
	data[15] = values[10] = 21;
}
*/
//----------------------------------------------------------------------------------------------
/*
for(i = 14 ; i >= -5; i--)
{
	data[14] + data[13] = 20 + 19 = 39;
	data[13] + data[12] = 19 + 18 = 37;
	data[12] + data[11] = 18 + 17 = 35;
	....
	data[-4] + data[-5] = 2 + 1 = 3;
}
*/