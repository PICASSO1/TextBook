#include <iostream>

using namespace std;

int main(void)
{
	const int inches_per_foot(12);
	double dLength(0), dWidth(0), dFeet(0); 
	int nLengthSize(0), nWidthSize(0);
	long lResult(0L);

	cout << "這支程式可以計算一個矩形架子的一層可以放幾個正方形的盒子!! " << endl;
	cout << "請輸入一層矩形架子的長(單位: 呎): ";
	cin >> dLength;
	cout << "請輸入一層矩形架子的寬(單位: 呎): ";
	cin >> dWidth;
	cout << "請輸入一個正方形盒子的邊長(單位: 吋): ";
	cin >> dFeet;
	nLengthSize = (dLength * inches_per_foot) / dFeet;
	nWidthSize = (dWidth * inches_per_foot) / dFeet;
	lResult = nLengthSize * nWidthSize;
	cout << "可以容納: " << lResult << "個盒子!! " << endl;

	return 0;
}
