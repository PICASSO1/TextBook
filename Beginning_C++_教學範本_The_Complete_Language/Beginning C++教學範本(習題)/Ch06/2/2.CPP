#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>      // for memset();

using namespace std;

int main(void)
{
	double dData[5][3], dMorning(0.00000), dNoon(0.00000), dEvening(0.00000);
	double dTotal1(0.00000), dTotal2(0.00000), dTotal3(0.00000);

	memset(dData, 0, sizeof(dData));

	cout << "這支程式可以計算星期一到星期五的氣象濕度!! " << endl;
	for(int i(0); i<5; i++)
	{
		cout << "星期" << i+1 << ": " << endl;
		cout << "早晨: ";
		cin >> dData[i][0];
		cout << "中午: ";
		cin >> dData[i][1];
		cout << "晚上: ";
		cin >> dData[i][2];
		cout << endl;
	}
	for(int j(0); j<5; j++)
	{
		dTotal1+=dData[j][0];
		dMorning=dTotal1/5;
		dTotal2+=dData[j][1];
		dNoon=dTotal2/5;
		dTotal3+=dData[j][2];
		dEvening=dTotal3/5;
	}
	cout << "本星期三個時段的平均濕度為: "<< endl;
	cout << "早晨: " << setprecision(2) << fixed << dMorning << endl;
	cout << "中午: " << setprecision(2) << fixed << dNoon << endl;
	cout << "晚上: " << setprecision(2) << fixed << dEvening << endl;

	return 0;
}
