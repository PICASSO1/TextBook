#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
	unsigned int nNum(30U);

	cout << "※這支程式會計算小於" << nNum << "的每個奇數的平方!! " << endl;
	for(int i(1); i<nNum; i+=2)
		cout << setw(2) << i << " * " << setw(2) << i << " = " << setw(3) << i*i << endl;

	return 0;
}
