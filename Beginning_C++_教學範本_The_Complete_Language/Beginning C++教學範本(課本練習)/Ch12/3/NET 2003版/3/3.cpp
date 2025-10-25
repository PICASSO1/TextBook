// 3.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include "Another.H"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
//	Box firstBox = {80.0, 50.0, 40.0};
	Box firstBox(80.0, 50.0, 40.0);
	double firstBoxVolume(firstBox.volume());

	cout << "Size of first Box object is " << firstBox.length << " by " << firstBox.breadth << " by " << firstBox.height << endl;
	cout << "Volume of first Box object is " << firstBoxVolume << endl;

	Box smallBox;
	smallBox.breadth = 5.0;
	smallBox.height = 4.0;
	smallBox.length = 10.0;

	cout << "Size of small Box object is " << smallBox.length << " by " << smallBox.breadth << " by " << smallBox.height << endl;
	cout << "Volume of small Box object is " << smallBox.volume() << endl;

	return 0;
}

