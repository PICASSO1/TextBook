#include <iostream>
#include "Box.H"
#include "ToughPack.H"
#include "Carton.H"

using namespace std;

void showVolume(const Box &rBox);

int main(int argc, char *argv[], char *envp[])
{
	Box myBox(20.0, 30.0, 40.0);
	ToughPack hardcase(20.0, 30.0, 40.0);
	Carton aCarton(20.0, 30.0, 40.0);

	cout << "使用參考值呼叫虛擬函數!! " << endl;

	showVolume(myBox);
	showVolume(hardcase);
	showVolume(aCarton);

	return 0;
}
//==================================================================================
void showVolume(const Box &rBox)
{
	rBox.ShowVolume();

	return;
}
