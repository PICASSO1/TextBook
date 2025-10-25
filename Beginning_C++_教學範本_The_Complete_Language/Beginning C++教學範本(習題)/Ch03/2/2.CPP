#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
	unsigned int nNum(0U);
	unsigned int nMask=0X00000001;

	cout << "請輸入一個二進位的正整數: ";
	cin >> nNum;
	cout << nNum << "的16進位為: " << showbase << uppercase << hex << nNum << endl;
	nNum ^= nMask;
	cout << nNum << "最後一位元反轉後為: " << dec << nNum << endl;

	return 0;
}
