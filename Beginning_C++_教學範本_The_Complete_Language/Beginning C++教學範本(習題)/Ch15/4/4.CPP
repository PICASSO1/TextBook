#include <iostream>
#include "Person.H"
#include "Employee.H"
#include "Executive.H"
#define M "Male"
#define F "Female"
#define Y 'Y'
#define N 'N'

using namespace std;

int main(int argc, char *argv[], char *envp[])
{
	cout << "以下是基礎類別 - Person的測試!! " << endl;
	Person AAA, BBB(17, "Silvia", F);
	Person CCC[5];
	CCC[0] = Person(18, "Shermie", F);
	CCC[1] = Person(19, "Picasso", M);
	CCC[2] = Person(20, "Mary", F);
	CCC[3] = Person(21, "Jerry", M);
	CCC[4] = Person(22, "Mai", F);

	AAA.Print();
	BBB.Print();
	CCC[0].Print();
	CCC[1].Print();
	CCC[2].Print();
	CCC[3].Print();
	CCC[4].Print();

	cout << "以下是衍生類別 - Employee的測試!! " << endl;
	Employee DDD, EEE(29, "Moda", M, 00000001);
	Employee FFF[5];
	FFF[0] = Employee(30, "Anna", F, 10000002);
	FFF[1] = Employee(31, "Dutch", M, 10000003);
	FFF[2] = Employee(32, "Mac", M, 10000004);
	FFF[3] = Employee(33, "Dillon", M, 10000005);
	FFF[4] = Employee(34, "Billy", M, 10000006);

	DDD.Print();
	EEE.Print();
	FFF[0].Print();
	FFF[1].Print();
	FFF[2].Print();
	FFF[3].Print();
	FFF[4].Print();

	cout << "以下是衍生類別 - Executive的測試!! " << endl;
	Executive GGG, HHH(41, "King", F, 20000001, Y);
	Executive III[5];
	III[0] = Executive(42, "Yagami", M, 20000002, N);
	III[1] = Executive(43, "Kyo", M, 20000003, Y);
	III[2] = Executive(44, "Ryo", M, 20000004, Y);
	III[3] = Executive(45, "Orochi", M, 20000005, Y);
	III[4] = Executive(46, "Chris", M, 20000006, N);

	GGG.Print();
	HHH.Print();
	for(int i(0); i<5; i++)
	{
		if(III[i].getKey() == Y)
			III[i].Employee::Print();
		else
			III[i].Print();
	}

	return 0;
}
