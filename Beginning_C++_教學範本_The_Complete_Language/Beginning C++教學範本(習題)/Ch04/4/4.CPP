#include <iostream>

using namespace std;

int main(void)
{
	double dMoney(0);
	const unsigned int nA1(25), nB1(10), nC1(5);
	int nA2(0), nB2(0), nC2(0), nMoney(0);
// 1元 = 10角；1角 = 10 分!!
	cout << "請輸入介於$0~$10之間的金額(可有小數): ";
	cin >> dMoney;

	if(dMoney>=0 && dMoney<=10.)
	{
		nMoney = dMoney*100;      // 把輸入的金額(元)，換算成分
		nA2 = nMoney / nA1;      // nA2: 需要幾個二角五分
		nB2 = (nMoney % nA1) / nB1;      // nB2: 需要幾個一角
		nC2 = ((nMoney % nA1) % nB1) / nC1;      // nC: 需要幾個五分
		cout << dMoney << "總共需要: " << nA2 << "個二角五分；" << nB2 << "個一角，以及" << nC2
			 << "個五分!! " << endl;
	}
	else
		cout << "輸入錯誤!!" << endl;

	return 0;
}
