#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void showData(const int data[], int count=1, const string &title="Data Values", int width=10, int perLine=5);
// ㄧ计よ璝す砛肚把计惠恶糶箇砞!!

int main(void)
{
	int samples[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	int dataItem(99);

	showData(&dataItem);

	dataItem=13;
	showData(&dataItem, 1, "Unlucky for some! ");

	showData(samples, sizeof(samples)/sizeof(int));
	showData(samples, sizeof(samples)/sizeof(int), "Samples");
	showData(samples, sizeof(samples)/sizeof(int), "Samples", 14);
	showData(samples, sizeof(samples)/sizeof(int), "Samples", 14, 4);

	return 0;
}
//================================================================
void showData(const int data[], int count, const string &title, int width, int perLine)
// ㄧ计﹚竡よ把计箇砞玥ぃゲ恶糶!!
{
	cout << endl << title;
	for(int i(0); i<count; i++)
	{
		if(i%perLine == 0)
			cout << endl;
		cout << setw(width) << data[i];
	}
	cout << endl;

	return;
}
