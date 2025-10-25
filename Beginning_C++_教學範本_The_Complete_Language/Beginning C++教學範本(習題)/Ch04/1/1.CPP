#include <iostream>

using namespace std;

int main(void)
{
	unsigned int nNum1(0U), nNum2(0U);

	while(1)
	{
		cout << "請輸入第一個正整數: ";
		cin >> nNum1;
		if(nNum1<=0)
		{
			cout << "不能輸入0喔!!" << endl;
			continue;
		}
		break;
	}
	while(1)
	{
		cout << "請輸入第二個正整數: ";
		cin >> nNum2;
		if(nNum2<=0)
		{
			cout << "不能輸入0喔!!" << endl;
			continue;
		}
		break;
	}
	if(nNum1<nNum2)
	{
		if(nNum2%nNum1==0)
			cout << "可以整除!!" << endl;
		else
			cout << "不能整除!!" << endl;
	}
	else
	{
		if(nNum1%nNum2==0)
			cout << "可以整除!!" << endl;
		else
			cout << "不能整除!!" << endl;
	}
	cout << "程式結束!!" << endl;

	return 0;
}
