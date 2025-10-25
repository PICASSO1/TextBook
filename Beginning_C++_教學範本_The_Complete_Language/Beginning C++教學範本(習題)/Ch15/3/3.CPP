#include <iostream>
#include "Animal.H"
#include "Lion.H"
#include "Aardvark.H"

using namespace std;

int main(void)
{
	Animal AAA, BBB("Bird", 30);
	Lion CCC, DDD("Cow", 20);
	Aardvark EEE, FFF("Hen", 10);

	cout << "以下是基礎類別 - Animal的測試: " << endl;
	AAA.who();
	BBB.who();
	cout << endl;

	cout << "以下是衍生類別 - Lion的測試: " << endl;
	CCC.Animal::who();
	DDD.who();
	cout << endl;

	cout << "以下是衍生類別 - Aardvark的測試:" << endl;
	EEE.Animal::who();
	FFF.who();
	cout << endl;

	return 0;
}
