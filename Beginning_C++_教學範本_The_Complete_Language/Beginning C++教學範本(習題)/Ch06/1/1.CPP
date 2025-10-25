#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#define SIZE 10

using namespace std;

int main(void)
{
	string Name[SIZE];
	double dScope[SIZE];
	int nCount(0);
	double dTotal(0.00000), dAvg(0.00000);

	memset(dScope, 0.00000, sizeof(dScope));

	cout << "這支程式可以輸入" << SIZE << "個學生的成績!! " << endl;
	for(int i(0); i<SIZE; i++)
	{
		cout << "請輸入第" << i+1 << "個學生的名字: ";
		getline(cin, Name[i], '\n');
		if(i!=0)
			getline(cin, Name[i], '\n');
		if(Name[i][0]=='\0')
			break;
		while(1)
		{
			cout << "請輸入第" << i+1 << "個學生的成績: ";
			cin >> dScope[i];
			if(dScope[i]<0.00000 || dScope[i]>100.00000)
			{
				cout << "輸入錯誤!! " << endl;
				continue;
			}
			else
				break;
		}
		nCount++;
	}
	for(int j(0); j<nCount; j++)      // 計算總成績
		dTotal+=dScope[j];
	dAvg=dTotal / nCount;      // 計算平均
	cout << endl << "|----------------------------|" << endl;      // 開始畫表格
	cout << "|       姓  名       | 分 數 |" << endl;
	for(int k(0); k<nCount; k++)
		cout << "|" << left << setw(20) << Name[k] << "| " << setw(5) << setprecision(2) << fixed << dScope[k] << " |" << endl;
	cout << "|----------------------------|" << endl;
	cout << "|-------平  均-------| " << setprecision(2) << dAvg << " |" << endl << endl;

	return 0;
}
