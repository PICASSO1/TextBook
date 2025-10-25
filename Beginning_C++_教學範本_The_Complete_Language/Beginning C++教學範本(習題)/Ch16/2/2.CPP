#include <iostream>
#include "BaseLength.H"
#define SIZE 4

using namespace std;

int main(int argc, char *argv[], char *envp[])
{
	Inches AAA(5);
	Meters BBB(6);
	Yards CCC(7);
	Perches DDD(8);

	BaseLength *ptrBL[SIZE] = {&AAA, &BBB, &CCC, &DDD};

	cout << ptrBL[0]->getData() << "英吋 = " << ptrBL[0]->length() << "公釐. " << endl;
	cout << ptrBL[1]->getData() << "公尺 = " << ptrBL[1]->length() << "公釐. " << endl;
	cout << ptrBL[2]->getData() << "碼 = " << ptrBL[2]->length() << "公釐. " << endl;
	cout << ptrBL[3]->getData() << "桿 = " << ptrBL[3]->length() << "公釐. " << endl;

	return 0;
}
